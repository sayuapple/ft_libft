/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:57:14 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 18:51:21 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 文字列の各文字を順次バッファに追加し、必要に応じてバッファをフラッシュ（内容をメインの文字列に統合）
/// @param strgen 文字列生成を管理する構造体へのポインタ
/// @param insert 追加する文字列へのポインタ
void	ft_strgenstr(t_strgen *strgen, char *insert)
{
	while (!strgen->error && *insert)
		ft_strgenchr(strgen, *insert++);
}
