/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:55:59 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 19:43:42 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 改行文字を基準にしてデータを分割し、読み取った行を動的に割り当てられた文字列として返す
/// @param io バッファIOを管理する構造体へのポインタ
/// @return 読み取った1行分の文字列へのポインタ
char	*ft_readline(t_bufferio *io)
{
	size_t	len;

	len = 0;
	while (1) //改行文字が見つからず、EOFにも達していない場合、ループを継続してデータの読み取り
	{
		ft_strgenflush(io->strgen);
		//バッファ内のデータを確実にメイン文字列に追加し、検索可能に
		if (io->strgen->str)
		{
			while (!ft_strchr("\n", io->strgen->str[len]))
				len++;
			if (io->strgen->str[len] == '\n')
				return (ft_strgenfetch(io->strgen, ++len));
			//改行文字が見つかった場合、その位置までの部分文字列を取得し、返す
		}
		if (ft_bufferioread(io)) //追加のデータを読み取り
		{
			if (!io->strgen->str)
				//バッファ内にまだ未処理のデータが残っているかを確認(ファイルの最後が改行文字で終わっていない場合)
				return (NULL);
			return (ft_strgencomp(io->strgen));
		}
	}
}
