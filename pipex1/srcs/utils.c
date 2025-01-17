
#include "utils.h"
#include <libft.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

//指定されたfd（input と output）を標準入力（STDIN_FILENO）および標準出力（STDOUT_FILENO）に設定する
// inputは標準入力として設定したいfd, outputは標準出力として設定したいfd
// dup2 や close の失敗をチェックしてない
void	setstdio(int input, int output)
{
	dup2(input, STDIN_FILENO);
	// input で指定されたファイルディスクリプタを標準入力に複製(標準入力が input と同じソースを指す)
	if (STDIN_FILENO != input)
		close(input); //不要なファイルディスクリプタが開きっぱなしになるのを防ぐ
	dup2(output, STDOUT_FILENO);
	if (STDOUT_FILENO != output) //標準出力が output と同じ先に出力される
		close(output);
}

//指定されたプログラム(pathname)を実行するためにプロセスを生成し、必要に応じて標準入力および標準出力をリダイレクトする
// var->run_here フラグに応じて、現在のプロセス内で実行するか、新しい子プロセスを生成して実行するかを決定

pid_t	execute(char *pathname, char *argv[], char *envp[], t_execute *var)
{
	pid_t	pid;

	if (!var->run_here)
		// var->run_here が false（0）の場合、新しい子プロセスを生成するために fork() を呼ぶ
		pid = fork(); // pid には子プロセスのプロセスIDが格納
	else
		pid = 0; //現在のプロセス内でプログラムを実行
	if (!pid)
	{
		setstdio(var->stdin_fd, var->stdout_fd);
		//標準入力 (STDIN_FILENO) と標準出力 (STDOUT_FILENO) を var->stdin_fd と var->stdout_fd にリダイレクト
		pid = execve(pathname, argv, envp);
		// execve システムコールを使用して、指定された pathname のプログラムを実行,
		//成功すると、現在のプロセスのイメージが新しいプログラムに置き換わる, 失敗した場合、pid は -1
		if (!var->run_here)
			// var->run_here が false の場合（子プロセス内で実行している場合）、execve が失敗した際に EXIT_FAILURE を返してプロセスを終了
			exit(EXIT_FAILURE);
	}
	return (pid); //実行されたプロセスのプロセスID（pid_t）を返す
}

//環境変数配列から PATH 環境変数を取得し、それをコロン（:）で区切って配列に分割する
char	**get_path(char *envp[])
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(&envp[i][5], ':')); // PATHの各ディレクトリパスを要素とする文字列の配列
											//&envp[i][5]は実際のPATH値へのポインタ
}

/// @brief 新しいパイプを作成し、readerとwriterを呼び出し元に提供。作成に失敗したら両ディスクリプタを-1に設定し、エラーを表示
/// @param reader パイプの読み取り側のファイルディスクリプタを格納するためのポインタ
/// @param writer パイプの書き込み側のファイルディスクリプタを格納するためのポインタ
/// @return パイプの作成が成功した場合は 0 を、失敗した場合は -1
int	newpipe(int *reader, int *writer)
{
	int ret;        // pipe システムコールの戻り値を格納
	int fd[2];      //パイプのfdを格納する配列。fd[0] が読み取り用、fd[1] が書き込み用のディスクリプタ
	ret = pipe(fd); //新しいパイプを作成し、読み取り用と書き込み用のfdを fd[0] と fd[1] に格納
	if (!ret)
	{
		*reader = fd[0];
		*writer = fd[1];
	}
	else
	{
		*reader = -1;
		*writer = -1;
	}
	return (ret);
}

/// @brief here_docの入力を取得し、それをパイプに書き込むことで、後続のプロセスがその入力を標準入力として受け取れるようにする
/// @param delimited here_docの終了を示すデリミタ文字列。ユーザーが入力を終了する際にこの文字列を入力
/// @return パイプの読み取り側のファイルディスクリプタ（成功時）または -1（失敗時）
int	here_doc_fd(char *delimited)
{
	int ret;                   //パイプの読み取り側のファイルディスクリプタを格納
	int temp;                  //パイプの書き込み側のファイルディスクリプタを格納
	char *str;                 // here_docの入力内容を一時的に格納するための文字列ポインタ
	if (!newpipe(&ret, &temp)) //新しいパイプを作成し、読み取り側と書き込み側のfdをそれぞれ ret と temp に設定
	{
		str = here_doc(delimited);
			//ユーザーからの入力を受け取り、delimited までの入力を収集。通常、標準入力から行を読み取り、delimited と一致する行が現れるまで続ける
									//戻り値: ヒアドキュメントの内容を含む文字列ポインタ
		if (str)
		{
			ft_putstr_fd(str, temp);//str の内容を temp（パイプの書き込み側）に書き込み

			free(str);//入力内容を保持しているメモリを解放
		}
		else
		{
			close(ret);//パイプの読み取り側を閉じます。これはエラー発生時にリソースを解放するため

			ret = -1;
		}
		close(temp);//パイプの書き込み側を閉じます。これにより、パイプへの書き込みが完了し、後続のプロセスがパイプの読み取り側でEOFを検出できる

	}
	return (ret);//未初期化だから条件式はいらないとバグ
}
