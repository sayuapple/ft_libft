/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:55:08 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 17:55:09 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

unsigned int	*index2addr(t_data_addr *data_addr, int index[2])
{
	char	*addr;

	addr = (data_addr->addr);
	addr += index[0] * data_addr->bits_per_pixel / 8;
	addr += index[1] * data_addr->size_line;
	return ((unsigned int *)addr);
}

t_position	index2position(int index[2], t_position center, t_size size,
		double scale)
{
	return ((t_position){
		.x = center.x + (index[0] - size.width / 2.) * scale,
		.y = center.y + (index[1] - size.height / 2.) * scale});
}