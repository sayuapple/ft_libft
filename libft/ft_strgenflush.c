/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenflush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:56:42 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 18:11:19 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 文字列生成構造体 (t_strgen) 内のバッファ (buff) に蓄積されたデータをメインの文字列 (str) に統合（フラッシュ）する
/// @param strgen  文字列生成を管理する構造体へのポインタ
void	ft_strgenflush(t_strgen *strgen)
{
	char	*temp;

	if (!strgen->position || strgen->error) //バッファにデータが存在しない場合
		return ;
	strgen->buff[strgen->position] = '\0';
	//バッファの現在の書き込み位置にヌル文字 ('\0') を挿入し、文字列として正しく終端
	temp = ft_strjoin2(strgen->str, strgen->buff);
	if (!temp)
	{
		strgen->error = 1;
		return ;
	}
	free(strgen->str);
	strgen->str = temp;
	strgen->position = 0;
}
