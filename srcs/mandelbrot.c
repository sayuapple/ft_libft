/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:55:23 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 17:55:34 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "color.h"
#include "formula.h"
#include "fractol.h"
#include "ft_complex.h"
#include "types.h"
#include <math.h>
#include <stddef.h>

unsigned int	plot_mandelbrot(t_plot_var *var, void *__args)
{
	t_mandelbrot	*args;
	unsigned int	ret;
	t_complex		*buff_addr;

	args = (t_mandelbrot *)__args;
	buff_addr = &args->buff[var->index[0]][var->index[1]];
	if (var->iter <= 1)
		*buff_addr = (t_complex){0, 0};
	*buff_addr = ft_cadd(ft_cpow(*buff_addr, (t_complex){args->exp, 0}),
			(t_complex){var->position.x, var->position.y});
	if (2. < ft_cabs(*buff_addr))
		ret = colormap(pow(var->iter / (double)var->max_iter, 1/log10(var->max_iter)));
	else
		ret = rgba2hex(0, 0, 0, 0xFF);
	return (ret);
}
//nは最小値0.1-0.2,最大値1
