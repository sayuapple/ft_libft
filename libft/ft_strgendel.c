/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgendel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:56:25 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 18:45:28 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief t_strgen 構造体に動的に割り当てられたメモリを解放し、構造体自体のメモリも解放
/// @param strgen 文字列生成を管理する構造体へのポインタ
void	ft_strgendel(t_strgen *strgen)
{
	if (strgen)
		free(strgen->str);
	free(strgen);
}
