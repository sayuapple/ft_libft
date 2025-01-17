
#include <libft.h>

static int	core(char ***lst_ptr, t_strgen *strgen, char *s);
static int	loop(t_strgen *strgen, char **s);
static int	singlequote_mode(t_strgen *strgen, char **s);
static int	doublequote_mode(t_strgen *strgen, char **s);

/// @brief コマンドライン入力を複数の単語に分割する（トークン化する）
/// @param s
/// @return 分割されたトークンを指す文字列の配列 char **
char	**cmdline_split(char *s)
{
	char **ret;              //最終的に返す配列へのポインタ
	char **lst;              //分割されたトークンを一時的に格納するための連結リスト
	t_strgen *strgen;        //文字列生成やバッファ管理を行うための構造体へのポインタ
	strgen = ft_strgennew(); //新しい t_strgen 構造体を初期化
	if (!strgen)
		return (NULL);
	lst = NULL;                //最初は空のリストとして NULL に設定
	if (core(&lst, strgen, s)) //入力文字列 s を解析し、トークンに分割して連結リスト lst に追加
		ret = NULL;
	else
		ret = ft_xlst2array(lst, sizeof(char *), NULL); //連結リスト lst を配列に変換
	ft_xlstclear(&lst, sizeof(char *));                 //連結リスト lst のすべてのノードを解放
	ft_strgendel(strgen);
	//文字列生成構造体 strgen のメモリを解放
	return (ret);
}

/// @brief 入力された文字列を解析し、スペースで区切られたトークンをリストに追加。具体的には、シングルクォートやダブルクォートで囲まれた部分を適切に処理し、各トークンを動的に管理されたリストに追加
/// @param lst_ptr リストの先頭へのポインタへのポインタ。このリストは、文字列ポインタ（char *）を格納するための動的配列またはリンクリスト
/// @param strgen
/// @param s  解析対象の入力文字列を指すポインタ
/// @return
static int	core(char ***lst_ptr, t_strgen *strgen, char *s)
{
	char *temp; // 一時的な文字列ポインタを保持
	while (1)
	{
		while (*s && ft_isspace(*s)) //連続する空白文字をスキップ
			s++;
		if (!*s)
			break ;
		if (loop(strgen, &s)) //次のトークンを解析し、strgen に追加
			return (-2);
		temp = ft_strgencomp(strgen);                              
			// strgen に蓄積されたバッファの内容を最終的な文字列として結合し、temp に保存
		if (!temp || ft_xlstappend(lst_ptr, sizeof(char *), &temp))
			//生成された文字列tempをリストlst_ptrに追加し、エラーの場合は終了
			return (-1);
	}
	temp = NULL;                                            // NULL ポインタを設定
	return (ft_xlstappend(lst_ptr, sizeof(char *), &temp)); //リストに NULL を追加
}

/// @brief 文字列 s を解析し、スペースが現れるまでの間に出現する文字を strgen というバッファに追加
/// *s は、文字列へのポインタ（char *）を取得
/// @param s **s は、s が指すポインタ（char *）が指す文字（char）を取得
/// @return
static int	loop(t_strgen *strgen, char **s)
{
	while (**s && !ft_isspace(**s))
	{
		if (**s == '\'')
		{
			if (singlequote_mode(strgen, s)) //シングルクォートで囲まれた部分をバッファに追加
				return (-1);
		}
		else if (**s == '"')
		{
			if (doublequote_mode(strgen, s))
				return (-1);
		}
		else
			ft_strgenchr(strgen, *(*s)++); // strgen のバッファに単一の文字を追加
	}
	return (0);
}

/// @brief シングルクォート内の文字を一文字ずつt_strgen構造体のバッファに追加し、シングルクォートの終了位置まで解析
/// @param strgen 文字列生成を管理する構造体へのポインタ
/// @param s 現在解析中の文字列のポインタへのポインタ。関数内でポインタを進めることで、文字列の解析位置を更新
/// @return
static int	singlequote_mode(t_strgen *strgen, char **s)
{
	(*s)++;                        //シングルクォート自体をスキップ
	while (*(*s) && *(*s) != '\'') //現在の文字がヌル文字でなく、かつシングルクォートでない限りループを継続
		ft_strgenchr(strgen, *(*s)++);
	//現在の文字を t_strgen のバッファに追加し、ポインタ *s を一つ進める
	if (!*(*s))
		//現在の文字がヌル文字である、つまりシングルクォートが閉じられていないまま文字列が終了したらエラー
		return (-1);
	(*s)++; //シングルクォートの終了文字をスキップ
	return (0);
}

/// @brief ダブルクォートで囲まれた文字列の内部を解析し、その内容を t_strgen 構造体のバッファに追加
/// @return
static int	doublequote_mode(t_strgen *strgen, char **s)
{
	(*s)++;
	while (*(*s) && *(*s) != '"')
	{
		if (*(*s) == '\\' && ft_strchr("\\\"", *(*s + 1)))
			//エスケープシーケンスを認識したら、\をスキップし、次の文字をそのままバッファに追加
			//現在の文字が（\）であり、次の文字が（\）または（"）である場合
			(*s)++;
		ft_strgenchr(strgen, *(*s)++);
	}
	if (!*(*s))
		return (-1);
	(*s)++;
	return (0);
}
//他のエスケープシーケンス（例: \n, \t, \r）サポートしてない