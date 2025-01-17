/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:58:06 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 17:07:34 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief カスタムリンクリスト（拡張リスト）に新しいノードを追加
/// @param lst_ptr リストの先頭ノードへのポインタを指すポインタ
/// @param size 各ノード内のデータ部分のサイズ（バイト単位）
/// @param  new 追加する新しいノードのデータを指すポインタ
/// @return
int	ft_xlstappend(void *lst_ptr, size_t size, void *new)
{
	void	*node;
	void	*tmp;

	node = malloc(size + sizeof(void *));
	//割り当てるメモリサイズは、データ部分のサイズと次のノードへのポインタのサイズを合計したもの
	if (!node)
		return (-1);
	ft_memcpy(node, new, size);
	*(void **)(node + size) = NULL;
	//ノードのデータ部分の後ろにある次のノードへのポインタを指すメモリ位置に NULL を設定
	//次のノードが存在しないことを示す
	tmp = lst_ptr;
	while (*(void **)tmp)
		tmp = *(void **)tmp + size;
	*(void **)tmp = node;
	//末尾ノードの次のポインタに、新しく作成したノードのポインタを設定
	return (0);
}
