
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*loop(t_bufferio *stdin, char *delimited);
static char	*here_doc_read(t_bufferio *stdin, char *delimited, size_t *line);
static int	chaek_delimited(t_strgen *strgen, char *str, char *delimited,
				size_t delimited_len);
static void	put_error(size_t line, char *delimited);

/// @brief
/// @param delimited here_docの終了を示すデリミタ（区切り文字列）
/// @return
char	*here_doc(char *delimited)
{
	char		*ret;
	t_bufferio	*stdin;

	stdin = ft_bufferionew(STDIN_FILENO, 0);
		//標準入力（STDIN_FILENO）用の t_bufferio 構造体を生成
        //close_on_error フラグを 0 に設定し、エラー時にfdを閉じないようにします
	if (!stdin)
	{
		perror("stdin");
		return (NULL);
	}
	ret = loop(stdin, delimited);
    //蓄積されたhere_docの内容を含む文字列。デリミタが正しく検出されなかった場合やエラーが発生した場合はNULLを返す
	if (!ret && stdin->strgen->error)
		perror("here_doc");
        //loop 関数の戻り値が NULL であり、かつ strgen 構造体の error フラグが立っている場合、エラーメッセージを表示
	ft_bufferiodel(stdin, 0);//stdin 構造体を解放,fdは閉じない
	return (ret);//here_docの内容を含む文字列を返す
}

/// @brief ユーザーからの入力を1行ずつ読み取り、指定されたデリミタと比較し、デリミタが検出されるまで入力を蓄積し、最終的に完全なhere_docの内容を取得
/// @param stdin
/// @param delimited ヒアドキュメントの終了を示すデリミタ（区切り文字列）
/// @return
static char	*loop(t_bufferio *stdin, char *delimited)
{
	t_strgen	*strgen;

	size_t delimited_len;                 //デリミタ文字列の長さ
	size_t line;                          //現在の行番号を追跡
	char *temp;                           //現在読み取った入力行を一時的に保持するポインタ
	delimited_len = ft_strlen(delimited); //デリミタ文字列の長さを計算
	strgen = ft_strgennew();              // here_docの内容を蓄積するための構造体を準備
	if (!strgen)
		return (NULL);
	line = 0;
	while (1) //ループはデリミタが検出されるまで継続
	{
		temp = here_doc_read(stdin, delimited, &line); //ユーザーから1行の入力を取得
		if (!temp)
			// EOFに達したかエラーが発生した場合、ループを終了
			break ;
		if (chaek_delimited(strgen, temp, delimited, delimited_len))
		//読み取った行 temp がデリミタと一致するかどうか
		{
			temp = ft_strgencomp(strgen); //一致する場合、蓄積された文字列を取得し、ループを終了
			break ;
		} //ヒアドキュメントの終了条件を判定
	}
	ft_strgendel(strgen);
	return (temp);
}

/// @brief here_docの入力処理を効率的かつ安全に行うための補助的な役割
/// @param stdin バッファリングされた入力操作を管理するための構造体へのポインタ
/// C言語の標準ライブラリで使用される stdin と名前が同じため、混乱を避けるために別の名前（例：input_io）を使用することを推奨
/// @param delimited ヒアドキュメントの終了を示すデリミタ（区切り文字列）
/// @param line 行番号を追跡するためのポインタ
/// @return
static char	*here_doc_read(t_bufferio *stdin, char *delimited, size_t *line)
{
	char	*temp;

	ft_putstr_fd("> ", STDOUT_FILENO); //標準出力に "> " を表示
	temp = ft_readline(stdin);         //ユーザーからの1行分の入力を取得
	if (!temp)
		put_error(*line, delimited); // EOFに達したかエラーが発生した場合）、エラーメッセージを表示
	(*line)++;                       //次の入力行の行番号を正しく追跡
	return (temp);                   //読み取られた行の文字列を返す
}

/// @brief　指定された文字列がデリミタと一致するかどうかをチェックし、一致する場合は処理を終了し、一致しない場合は文字列を蓄積
/// @param strgen
/// @param str チェック対象の文字列
/// @param delimited 期待されるデリミタ（区切り文字列）
/// @param delimited_len デリミタ文字列の長さ
/// @return
static int	chaek_delimited(t_strgen *strgen, char *str, char *delimited,
		size_t delimited_len)
{
	if (!ft_strncmp(str, delimited, delimited_len)
		&& str[delimited_len] == '\n') // str がデリミタと一致し、かつその後に改行が続いている場合
	{
		free(str);
		return (1);
	}
	else //入力された行がデリミタではないため、strgen に蓄積して後続の処理を続行
	{
		ft_strgenstr(strgen, str);
		free(str);
		return (0);
	}
}
//関数名のスペルミス、入力が改行で終わることが前提になっている

/// @brief here-docの処理中に期待されるデリミタが見つからずファイルの終わりに達した場合に、ユーザーに対して具体的な警告メッセージを表示
/// @param line エラーが発生した行番号を示す整数値
/// @param delimited 期待されるhere-documentの終了デリミタ（区切り文字列）
static void	put_error(size_t line, char *delimited)
{
	if (line)
	{
		ft_putstr_fd("line ", STDERR_FILENO);
		ft_putnbr_fd(line, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd("warning: ", STDERR_FILENO);
	ft_putstr_fd("here-document at line 0 delimited by end-of-file ",
		STDERR_FILENO);
	ft_putstr_fd("(wanted `", STDERR_FILENO);
	ft_putstr_fd(delimited, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
}
