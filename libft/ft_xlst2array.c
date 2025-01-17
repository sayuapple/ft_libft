/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlst2array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:57:57 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 16:55:16 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief カスタムリンクリスト（拡張リスト）を 配列に変換
/// @param lst 変換対象のリストの先頭ノードへのポインタ
/// @param size 各ノード内のデータ部分のサイズ（バイト単位）
/// @param __len リストの長さ（ノード数）を返すためのポインタ
/// @return
void	*ft_xlst2array(void *lst, size_t size, size_t *__len)
{
	size_t	len;
	void	*array;
	void	*head;

	len = ft_xlstlen(lst, size);
	array = malloc(len * size);
	if (!array)
		return (NULL);
	head = array;
	while (lst)
	{
		ft_memcpy(array, lst, size);
		array += size;                //配列内の次の位置にポインタを移動
		lst = *(void **)(lst + size); //現在のノードから次のノードへのポインタを取得
	}
	if (__len)
		*__len = len; //呼び出し元にリストの長さを提供
	return (head);
}
//カスタムリンクリストとは特定の要件や用途に合わせて設計・実装されたリンクリスト（連結リスト）