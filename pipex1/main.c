/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:28:50 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/13 18:43:55 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <libft.h>

static int	setvar(t_pipex *var, int len, char *args[], int here_doc);

/// @brief コマンドライン引数と環境変数を受け取り、パイプライン処理を実行するための設定と実行,特に、here_doc と呼ばれる機能をサポート
/// @param argc
/// @param argv
/// @param envp
/// @return
int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	var;

	int here_doc; // here_doc 機能が有効かどうかを示すフラグ
	here_doc = ((1 < argc) && !ft_strcmp(argv[1], "here_doc"));
	if (setvar(&var, argc - 1 - here_doc, &argv[1 + here_doc], here_doc))
	{
		ft_putendl_fd("error", 2);
			// setvar がエラーを返した場合、標準エラー出力に "error" を表示し、-1 を返して終了
		return (-1);
	}
	pipex(&var, envp);
	return (0);
}

/// @brief コマンドライン引数から必要な情報を抽出し、t_pipex 構造体に設定
/// @param var
/// @param len args配列の要素数
/// @param args パイプライン処理に使用する引数の配列
/// @param here_doc here_docを使用するかどうか示すフラグ
/// @return
static int	setvar(t_pipex *var, int len, char *args[], int here_doc)
{
	if (len < 4)
		return (-1);
	var->in = args[0];
	var->cmds = &args[1];
	// args[1]以降がコマンド及びその引数と仮定し、var->cmdsにポインタとして格納、cmdsはコマンド開始位置
	var->len = len - 2; //コマンド数、len - 入出力file
	var->out = args[len - 1];
	var->here_doc = here_doc;
	var->append = here_doc;
	// here_docを使用する場合、出力fileの追記モードを有効にするためと考えられる(here_docを使用する際は通常出力fileに追記する動作が求められることが多い)
	return (0);
}
