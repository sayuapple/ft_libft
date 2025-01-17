/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenfetch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:56:35 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 18:54:26 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief メイン文字列の最初の len 文字を取得し、残りの部分を構造体内に保持
/// @param strgen 字列生成を管理する構造体へのポインタ
/// @param len 抽出する指定された長さ
/// @return 抽出された部分文字列へのポインタ
char	*ft_strgenfetch(t_strgen *strgen, size_t len)
{
	char	*ret;
	char	*temp;

	if (strgen->error)
		return (NULL);
	if (!len || !strgen->str)
		return (ft_strdup(""));
	temp = ft_substr(strgen->str, len, -1);
	if (!temp)
		return (NULL);
	ret = ft_substr(strgen->str, 0, len);
	if (!ret)
		free(temp);
	else
	{
		if (!ft_strlen(temp))
		{
			free(temp);
			temp = NULL;
		}
		free(strgen->str);
		strgen->str = temp;
	}
	return (ret);
}
