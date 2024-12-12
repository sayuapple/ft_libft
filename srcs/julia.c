/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:55:46 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 17:55:47 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "formula.h"
#include "fractol.h"
#include "ft_complex.h"
#include "types.h"
#include <math.h>
#include <stddef.h>

unsigned int	plot_julia(t_plot_var *var, void *__args)
{
	t_julia			*args;
	unsigned int	ret;
	t_complex		*buff_addr;

	args = (t_julia *)__args;
	buff_addr = &args->buff[var->index[0]][var->index[1]];
	if (var->iter <= 1)
		*buff_addr = (t_complex){var->position.x, var->position.y};
	*buff_addr = ft_cadd(ft_cpow(*buff_addr, (t_complex){args->exp, 0}),
			args->point);
	if (2. < ft_cabs(*buff_addr))
		ret = colormap(pow(var->iter / (double)var->max_iter, 1/log10(var->max_iter)));
	else
		ret = rgba2hex(0, 0, 0, 0xFF);
	return (ret);
}