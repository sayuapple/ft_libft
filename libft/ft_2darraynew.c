/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darraynew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:22:10 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 21:11:17 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	clean(char **array, size_t i);

void	*ft_2darraynew(size_t size, size_t width, size_t height)
{
	char	**array;
	size_t	n[2];
	size_t	i;

	n[0] = sizeof(void *) * (width + 1);//各ポインタのサイズ*(行数+NULL)
	n[1] = size * height;
	if (n[0] / sizeof(void *) != (width + 1) || n[1] / size != height)
		return (NULL);
	array = malloc(n[0]);
	if (!array)
		return (NULL);
	i = 0;
	while (i < width)
	{
		array[i] = malloc(n[1]);
		if (!array[i++])
		{
			clean(array, --i);
			return (NULL);
		}
	}
	array[i] = NULL;
	return (array);
}

static void	clean(char **array, size_t i)
{
	while (i--)
		free(array[i]);//iが0になるまで各行のメモリを解放
	free(array);
}

// size(配列の各要素のサイズ)
//返り値(割り当てられた2次元配列へのポインタ)実際にはchar **型を返す
//n[2](配列の総バイト数を格納する配列)、n[0]はポインタ配列用(2次元配列全体の行ポインタ（char *）のメモリサイズ)
//n[1]は各行のデータ用(各行のデータ部分（実際の要素）のメモリサイズ)
