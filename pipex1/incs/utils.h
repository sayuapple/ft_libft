/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:29:36 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/12 14:02:36 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/wait.h>

//	utils.c
typedef struct s_execute
{
	int stdin_fd; // コマンドの標準入力をリダイレクトするfd

	int stdout_fd; //コマンドの標準出力をリダイレクトするfd

	int run_here; // 現在のプロセス内で実行するかどうかのフラグ
}			t_execute;

void		setstdio(int input, int output);
pid_t		execute(char *pathname, char *argv[], char *envp[], t_execute *var);
char		**get_path(char *envp[]);
int			newpipe(int *reader, int *writer);

char		**cmdline_split(char *s);
char		*here_doc(char *delimited);
int			here_doc_fd(char *delimited);

//	eval.c
/// @brief プロセスの実行やパイプライン処理を行う際に必要な情報(環境変数、パス情報、および実行に関連する変数)をまとめて保持する
typedef struct s_eval
{
	char **envp; //プロセスの環境変数を保持する配列。各要素は"KEY=VALUE"形式の文字列で、システムやユーザーが設定した環境変数を表す
	char	**path;
	//システムのPATH環境変数を分割・解析した結果を保持する配列。各要素はディレクトリパス（例："/usr/bin"、"/bin"）を表す

	t_execute execute_var; //プロセスの実行に関連する変数や設定を保持する構造体
}			t_eval;

int			executable(char *cmd, char *path[], char **filename);
pid_t		eval(char *cmd, t_eval *config);

#endif