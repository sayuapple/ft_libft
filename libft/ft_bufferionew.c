/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferionew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:54:52 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 19:17:21 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 新しいバッファIO構造体(t_bufferio)を初期化し、指定されたfdと関連リソースを設定
/// @param fd 
/// @param close_on_error 
/// @return 初期化された t_bufferio 構造体へのポインタ
t_bufferio	*ft_bufferionew(int fd, int close_on_error)
{
	t_bufferio	*ret;

	if (fd == -1)
		return (NULL);
	ret = (t_bufferio *)malloc(sizeof(t_bufferio));
	if (!ret)
	{
		if (close_on_error)
			close(fd);
		return (NULL);
	}
	ret->strgen = ft_strgennew();
	if (!ret->strgen)
	{
		free(ret);
		if (close_on_error)
			close(fd);
		return (NULL);
	}
	ret->fd = fd;
	return (ret);
}