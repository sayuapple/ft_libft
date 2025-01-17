/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:58:40 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 17:58:22 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief カスタムリンクリストから特定のインデックスに位置するノードを削除（ポップ）し、そのデータを取得
/// @param lst_ptr リストの先頭ノードへのポインタを指すポインタ
/// @param size 各ノード内のデータ部分のサイズ（バイト単位）
/// @param index 削除するノードのインデックス
/// @param dst 削除したノードのデータを格納するためのバッファへのポインタ
/// @return
int	ft_xlstpop(void *lst_ptr, size_t size, int index, void *dst)
{
	void	*node;
	void	*temp;

	if (index < 0)
	{
		index += ft_xlstlen(*(void **)lst_ptr, size);
		//インデックスが負の場合、リストの長さを取得し、負のインデックスをリストの長さに加算して正のインデックスに変換
		if (index < 0) //再び負になる場合、無効なインデックスとして -1
			return (-1);
	}
	temp = lst_ptr;
	while (*(void **)temp && index--) //指定されたインデックスに位置するノードを見つける
		temp = *(void **)temp + size;
	node = *(void **)temp; // node は削除対象のノードを指す
	if (!node)
		return (-1);
	*(void **)temp = *(void **)(node + size);
    //現在のノード temp の次のポインタに、削除対象ノードの次のノードへのポインタを設定
	if (dst)
		ft_memcpy(dst, node, size);
	free(node);
	return (0);
}
//dstがNULLに固定されている(引数として)ので削除したノードのデータはコピーされない
