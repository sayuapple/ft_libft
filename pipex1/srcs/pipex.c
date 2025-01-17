
#include "pipex.h"
#include "utils.h"
#include <libft.h>


typedef struct s_pipex_local
{
	t_eval config; //パイプライン処理に必要な設定や評価結果を保持する構造体
	pid_t	pid;
	// pid_t（プロセスIDを表す型）ただのint,現在の子プロセスのプロセスIDを保持。fork()によって生成された子プロセスのIDが格納

	int reader;  //パイプの読み取り側のfdを保持。前のコマンドの出力を現在のコマンドの入力として使用する際に利用
	int writer;  //パイプの書き込み側のfdを保持。現在のコマンドの出力を次のコマンドの入力として渡すために使用
	int tempfd;  //一時的なfdを保持。このfdは、一時的な操作やリダイレクションに使用
	int infile;  //パイプラインの最初のコマンドへの入力元として使用されるfdを保持。通常、入力ファイルを開いた際のfdが格納
	int outfile; //パイプラインの最後のコマンドの出力先として使用されるfdを保持。通常、出力ファイルを開いた際のfdが格納
	size_t	i;
}			t_pipex_local;

static int	init_fd(t_pipex *var, t_pipex_local *sp);
static int	set_fd(t_pipex *var, t_pipex_local *sp, int is_last);
static int	section_to_execute(t_pipex *var, t_pipex_local *sp);
static int	execute_cmd(t_pipex *var, t_pipex_local *sp, size_t i);

/// @brief パイプラインを設定し、複数のコマンドを連結して実行
/// @param var pipex 関数に必要な設定やコマンド情報を保持する構造体へのポイン
/// @param envp 環境変数の配列
/// @return
int	pipex(t_pipex *var, char *envp[])
{
	t_pipex_local	sp;

	sp.pid = 0;                      //プロセスIDを初期化
	sp.config.envp = envp;           //環境変数を設定
	sp.config.path = get_path(envp); //環境変数から PATH を取得し、コマンドの検索パスを設定
	sp.config.execute_var.run_here = 0;
	if (init_fd(var, &sp))
	{
		free(sp.config.path);
		return (-1); // init_fd が失敗した場合、sp.config.path を解放し、-1 を返して終了
	}
	if (section_to_execute(var, &sp))
	{
		free(sp.config.path);
		return (-1);
	}
	ft_2darraydel(sp.config.path);
		// sp.config.path に格納された2次元配列（おそらくコマンド検索パス）を解放
	if (0 < sp.pid)//sp.pid が有効なプロセスIDであれば、そのプロセスの終了を待機
		waitpid(sp.pid, NULL, 0);
	return (0);
}

/// @brief パイプライン処理において入力および出力ファイルのfdを初期化,入力元および出力先のファイルを適切に設定
/// @param var パイプライン処理に必要な設定や情報を保持する構造体へのポインタ
/// @param sp ローカルなfdやプロセス情報を保持する構造体へのポインタ
/// @return 成功(0)失敗(-1)
static int	init_fd(t_pipex *var, t_pipex_local *sp)
{
	if (var->here_doc) // here_docを使用するならその入力を処理し、パイプの読み取り側のfdを取得
	{
		sp->infile = here_doc_fd(var->in);
		// here_docの入力をパイプに書き込む。この関数は、here_docの入力を受け取り、その内容をパイプ経由で提供するためのfdを返す
		// sp->infileにパイプの読み取り側のfdを格納
		if (sp->infile < 0) //失敗したら-1を返して終了
			return (-1);
	}
	else // here_docを使用しない場合、通常の入力ファイルをオープン
		sp->infile = open(var->in, O_RDONLY);
	// var->inに指定されたファイルを読み取り専用(O_RDONLY)でオープン
	if (sp->infile < 0)  //失敗したら標準エラー出力にエラーメッセージを表示
		perror(var->in); // perror(var->in) は、var->in のファイル名とエラー内容を表示
	if (var->append)     //出力ファイルを追記モード (O_APPEND) でオープン。これで、既存のファイル内容に新しいデータが追加
		sp->outfile = open(var->out, O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else //出力ファイルを上書きモード (O_TRUNC) でオープン。これで、既存のファイル内容が削除され、新しいデータで上書き
		sp->outfile = open(var->out, O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (sp->outfile < 0)  //オープンに失敗した場合、標準エラー出力にエラーメッセージを表示
		perror(var->out); // perror(var->out) は、var->out のファイル名とエラー内容を表示
	return (0);
}
// O_WRONLY: 書き込み専用でオープン。
// O_CREAT: ファイルが存在しない場合、新規に作成。
// O_APPEND または O_TRUNC: 追記モードまたは上書きモードの指定。
// S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH: ファイルのパーミッション設定。ユーザーに読み書き権限、グループに読み権限、その他に読み権限を付与。

/// @brief パイプライン処理において各コマンドの出力先(writer fd)を設定(最後のコマンドの場合は出力fileにリダイレクト、それ以外は次のコマンドへのパイプ作成)
/// @param var パイプライン処理に必要な設定や情報を保持する構造体へのポインタ
/// @param sp ローカルなfdやプロセス情報を保持する構造体へのポインタ
/// @param is_last 現在のコマンドがパイプラインの最後のコマンドであるかどうかを示すフラグ。1 なら最後、0 ならそれ以外
/// @return 成功(0)失敗(-1)
static int	set_fd(t_pipex *var, t_pipex_local *sp, int is_last)
{
	(void)var; //未使用、消すべき？
	if (is_last)
		sp->writer = sp->outfile;
	//現在のコマンドの標準出力を sp->outfile(パイプラインの最後のコマンドの出力先となるfileのfd)にリダイレクト
	else if (newpipe(&sp->tempfd, &sp->writer))
	//新しいパイプを作成し、読み取り側を sp->tempfd、書き込み側を sp->writerに設定
	// sp->writerを現在のコマンドの標準出力として使用。これで次のコマンドがこのパイプの読み取り側 (sp->tempfd) を標準入力として使用できる
	{
		perror("pipe");
		return (-1); //作成に失敗した場合、エラーメッセージを標準エラー出力に表示し、-1 を返して終了
	}
	return (0);
}

/// @brief パイプライン内で複数のコマンドを順次実行し、各コマンド間のデータフローを管理
/// @param var パイプライン全体の設定や状態を保持する構造体へのポインタ
/// @param sp パイプライン内の特定のコマンド実行ステージのローカル設定や状態を保持する構造体へのポインタ
/// @return
static int	section_to_execute(t_pipex *var, t_pipex_local *sp)
{
	size_t	i;

	i = 0;
	sp->reader = sp->infile; //最初のコマンドの標準入力として入力ファイル (sp->infile) を設定
	while (i++ < var->len)   //コマンドの数 (var->len) に基づいてループ
	{
		if (set_fd(var, sp, i == var->len)) //現在のコマンドの標準入力と標準出力を適切に設定
		{
			close(sp->reader); // fdの設定に失敗したら、現在のリーダー (sp->reader) を閉じ、エラーとして
								//-1 を返す
			return (-1);
		}
		if (execute_cmd(var, sp, i - 1)) //指定されたコマンド (var->cmds[i
											//- 1]) を実行し、パイプの設定を行う
		{
			perror("eval");
			close(sp->tempfd);
			return (-1); //失敗した場合、エラーメッセージを表示し、-1 を返す
		}
		sp->reader = sp->tempfd;
		//成功すれば、次のコマンドの標準入力として現在のコマンドの出力 (sp->tempfd) を設定
	}
	return (0);
}

/// @brief パイプの読み取り側 (reader) と書き込み側 (writer) を設定し、指定されたコマンドを実行
/// @param var パイプライン全体の設定や状態を保持する構造体へのポインタ
/// @param sp パイプライン内の特定のコマンド実行ステージのローカル設定や状態を保持する構造体へのポインタ
/// @param i var->cmds 配列内のどのコマンドを実行するかを指定するインデックス
/// @return 実行後に不要になったfdを閉じ、コマンドの実行が成功(0)したかどうかを返す
static int	execute_cmd(t_pipex *var, t_pipex_local *sp, size_t i)
{
	if (0 < sp->reader && 0 < sp->writer) //パイプの読み取り側と書き込み側が有効なfdであるか
	{
		sp->config.execute_var.stdin_fd = sp->reader;  //パイプの読み取り側を標準入力として設定
		sp->config.execute_var.stdout_fd = sp->writer; //パイプの書き込み側を標準出力として設定
		sp->pid = eval(var->cmds[i], &sp->config);
		//指定されたコマンド (var->cmds[i]) を実行
	}
	close(sp->reader); //要になったパイプの読み取り側と書き込み側fdを閉じる
	close(sp->writer);
	return (-(sp->pid < 0));
}
// sp->config.execute_var: コマンド実行時の標準入力 (stdin_fd) と標準出力 (stdout_fd) の設定を保持
// sp->config は、コマンド実行時の設定情報（標準入力・出力のファイルディスクリプタなど）を含む構造体
//成功失敗のときの整合性がない、マクロ使用