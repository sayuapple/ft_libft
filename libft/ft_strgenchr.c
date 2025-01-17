/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:56:13 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 18:34:21 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 文字列生成構造体 (t_strgen) に単一の文字を追加,指定された文字を一時的なバッファに挿入し、満杯になった場合にはその内容をメインの文字列(str)に統合
/// @param strgen 文字列生成を管理する構造体へのポインタ
/// @param insert バッファに挿入する単一の文字
void	ft_strgenchr(t_strgen *strgen, char insert)
{
	if (strgen->error)
		return ;
	strgen->buff[strgen->position++] = insert;
	if (strgen->position >= STRGEN_BUFFSIZE)
		ft_strgenflush(strgen);
}
