/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:03:39 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 19:46:55 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "formula.h"
#include "fractol.h"
#include <libft.h>

#define MAX_ITER 1000
#define WIDTH_SIZE 800
#define HEIGHT_SIZE 600

int	mandelbrot(double exp);
int	julia(double exp, t_complex point);

int	main(int argc, char *argv[])
{
	double	exp;

	exp = 2.0;
	if (1 < argc)
	{
		if (!ft_strcmp(argv[1], "M"))
		{
			if (2 < argc)
				exp = ft_atof(argv[2]);
			return (mandelbrot(exp));
		}
		else if (!ft_strcmp(argv[1], "J"))
		{
			if (4 < argc)
				exp = ft_atof(argv[4]);
			if (3 < argc)
				return (julia(exp, (t_complex){ft_atof(argv[2]),
						ft_atof(argv[3])}));
		}
	}
	ft_putendl_fd("error", 2); //error出力の変更(引数が異なるとき)
	return (-1);
}

int	mandelbrot(double exp)
{
	t_complex	**buff;

	buff = ft_2darraynew(sizeof(t_complex), WIDTH_SIZE, HEIGHT_SIZE);
	if (!buff)
		return (-1);
	fractol(&(t_fractol){
		.size = (t_size){.width = WIDTH_SIZE, .height = HEIGHT_SIZE},
		.max_iter = MAX_ITER,
		.position = (t_position){.x = 0., .y = 0.},
		.scale = 0.01,
		.title = "mandelbrot",
		.plot_func = plot_mandelbrot,
		.plot_args = &(t_mandelbrot){.exp = exp, .buff = buff},
	});
	ft_2darraydel(buff);
	return (0);
}

int	julia(double exp, t_complex point)
{
	t_complex	**buff;

	buff = ft_2darraynew(sizeof(t_complex), WIDTH_SIZE, HEIGHT_SIZE);
	if (!buff)
		return (-1);
	fractol(&(t_fractol){
		.size = (t_size){.width = WIDTH_SIZE, .height = HEIGHT_SIZE},
		.max_iter = MAX_ITER,
		.position = (t_position){.x = 0., .y = 0.},
		.scale = 0.01,
		.title = "julia",
		.plot_func = plot_julia,
		.plot_args = &(t_julia){.exp = exp, .point = point, .buff = buff},
	});
	ft_2darraydel(buff);
	return (0);
}

// ft_atof(ascii to float)
// exp(指数部分を格納、指定されない場合デフォ2.0)
//　.buff = buff(割り当てたbuffへのポインタ)