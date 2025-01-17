
#include "utils.h"
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// 0: コマンドが実行可能であり、filename にそのパスが設定された。
// 1: コマンドが見つからないか、実行権限がない。
// -1: メモリ割り当てやその他の内部エラーが発生。
// -2: loop 関数内でエラーが発生。

/// @brief 指定されたコマンドが実行可能であるかを確認し、その実行可能なファイルのパスを取得
/// @param cmd 実行可能かを確認したいコマンド名またはパス
/// @param path コマンドが存在する可能性のあるディレクトリの配列。通常は環境変数 PATH を分割したもの
/// @param filename 見つかった実行可能ファイルのパスを格納するためのポインタへのポインタ。成功したら、このポインタに実行可能ファイルのパスが設定
/// @return 
int	executable(char *cmd, char *path[], char **filename)
{
	if (cmd && ft_strchr(cmd, '/'))//コマンド名に/が含まれているかを確認。ある場合、絶対パスまたは相対パスを示し、PATH 環境変数を探索する必要なし
	{
		if (!access(cmd, X_OK))//指定されたファイル cmd に実行権限があるかを確認
		{
			*filename = ft_strdup(cmd);//cmd のコピーを作成し、filename に設定
			return (-!*filename);//*filename が NULL でなければ 0、NULL であれば -1 
		}
		perror(cmd);//cmd に関連するエラーメッセージを標準エラー出力に表示
	}
	else//path 配列（通常は PATH 環境変数を分割したもの）を順にチェックし、cmd を各ディレクトリと結合したパスが実行可能かを確認
	{
		while (cmd && path && *path)
		{
			*filename = ft_joinpath(*path++, cmd);//path 配列の各ディレクトリに対して ft_joinpathでcmd を結合し、フルパスを生成
			if (!*filename || !access(*filename, X_OK))//生成されたパスが実行可能であれば、filename に設定し、0 を返す
				return (-!*filename);
			free(*filename);//実行可能でない場合は、メモリを解放して次のディレクトリに進む
		}
		if (cmd)
			ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);//コマンド見つからないときエラーメッセージを標準エラー出力に表示
	}
	*filename = NULL;
	return (1);//filename を NULL に設定し、1 を返す

}
//char *path[] は char **path と同等でpath は「文字列へのポインタを指すポインタ
//*path は、path ポインタを参照解除したもの。具体的には、path が指す現在のディレクトリパス（文字列）
//ループの各イテレーションで、path は配列内の異なるディレクトリを指し
//初回のループでは *path は "/bin" を指し、次回のループでは "/usr/bin" を指す

// When -1				: error
// When 0				: not_found
// When greater than 0	: success

/// @brief 与えられたコマンド文字列を解析し、適切な実行可能ファイルを見つけて実行しそのプロセスIDを返す
/// @param cmd 実行したいコマンド文字列、例 "ls -l /home"のような形式
/// @param config
/// @return
pid_t	eval(char *cmd, t_eval *config)
{
	pid_t	ret;
	char	*path;
	char	**head;
	char	**args;

	args = cmdline_split(cmd); //入力されたコマンド文字列を個々の引数に分割しargsという文字列配列に格納
	if (!args)                 //失敗しNULLを返した場合、-1を返して終了
		return (-1);
	ret = executable(args[0], config->path, &path);
	//指定されたconfig->path内の各ディレクトリを検索しコマンド(args[0])の実行ファイルを検索し見つかったらpathにそのフルパスを設定
	if (ret == 0)
		ret = execute(path, args, config->envp, &config->execute_var);
	//新しい子プロセスを生成し指定されたコマンドを実行、成功すると子プロセスのプロセスID(pid_t)返す
	else if (ret == 1)
		ret = 0; //コマンドが存在しないことを示すために、ret=0に設定(何したいか不明瞭ret=-1の設定のほうがいいかも)
	head = args; //もとの配列のポインタを保持
	while (*args)
		free(*args++); //配列の各要素(文字列で)解放
	free(*args);       //最後のNULLポインタを解放(不要かも)
	free(head);        //配列自体を解放
	free(path);        //実行可能ファイルのパス文字列を解放
	return (ret);
}
