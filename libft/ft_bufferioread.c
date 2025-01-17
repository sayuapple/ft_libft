/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferioread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:55:06 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 19:34:42 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief バッファIO構造体 (t_bufferio) に関連付けられたfdからデータを読み取り、文字列生成構造体 (t_strgen) のバッファに蓄積
/// @param io バッファIOを管理する構造体へのポインタ
/// @return
int	ft_bufferioread(t_bufferio *io)
{
	ssize_t	read_size;

	if (io->strgen->error)
		return (-1);
	read_size = read(io->fd, &io->strgen->buff[io->strgen->position],
			STRGEN_BUFFSIZE - io->strgen->position);
	if (read_size < 0)
		return (-1);
	io->strgen->position += read_size;
	//読み取ったデータ量 (read_size) をバッファの現在位置に追加
	if (io->strgen->position > STRGEN_BUFFSIZE)
		ft_strgenflush(io->strgen);
	return (!read_size);
    //read_size が0の場合（EOFに達した場合）、!read_size は 1 を返します
}
