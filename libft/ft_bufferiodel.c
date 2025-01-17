/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferiodel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:54:32 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 19:03:18 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief バッファIO構造体 (t_bufferio) に関連するリソースを適切に解放し、必要に応じてfdを閉じる
/// @param io バッファIOを管理する構造体へのポインタ
/// @param do_close
void	ft_bufferiodel(t_bufferio *io, int do_close)
{
	ft_strgendel(io->strgen);
	if (do_close)
		close(io->fd);
	free(io);
	// io ポインタが指す t_bufferio 構造体自体のメモリを解放
}
