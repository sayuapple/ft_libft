/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:58:28 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 14:56:57 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief リストの先頭ポインタと、各ノード内で次のノードへのポインタが存在するオフセット（バイト単位）を受け取り、リスト内のノード数を返す
/// @param lst リストの開始点を指定
/// @param size ノード構造体内で次のノードへのポインタがどの位置にあるか
/// @return リスト内のノード数
size_t	ft_xlstlen(void *lst, size_t size)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		lst = *(void **)(lst + size);
		// lst+size で得られたアドレスを、次のノードへのポインタを指す void **型にキャスト
		// void ** 型にキャストされたアドレスから、実際の void * 型のポインタ値 を取得
		count++;
	}
	return (count);
}
//オフセット: 構造体内の特定のメンバーが構造体の先頭から何バイト離れているか