/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgencomp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:56:20 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 18:43:10 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief バッファに蓄積されたデータをメインの文字列に統合し、エラーチェックを行った後、完成した文字列を返す
/// @param strgen 文字列生成を管理する構造体へのポインタ
/// @return 完成した文字列へのポインタ
char	*ft_strgencomp(t_strgen *strgen)
{
	char	*ret;

	ft_strgenflush(strgen);
	//バッファに蓄積された未処理のデータをメインの文字列に統合
	if (!strgen->error)
	{
		ret = strgen->str;
		if (!ret) //初期化に失敗している場合
		{
			ret = ft_strdup("");
			if (!ret)
				strgen->error = 1;
		}
	}
	if (strgen->error)
	{
		free(strgen->str);
		//メイン文字列 (str) のメモリを解放
		ret = NULL;
	}
	strgen->str = NULL;
	strgen->position = 0;
	strgen->error = 0;
	return (ret);
}
