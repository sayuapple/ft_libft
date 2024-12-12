/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:01:47 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 18:01:55 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMULA_H
# define FORMULA_H

# include "fractol.h"
# include "ft_complex.h"

typedef struct s_mandelbrot
{
	double		exp;
	t_complex	**buff;
}				t_mandelbrot;

unsigned int	plot_mandelbrot(t_plot_var *var, void *args);

typedef struct s_julia
{
	double		exp;
	t_complex	point;
	t_complex	**buff;
}				t_julia;

unsigned int	plot_julia(t_plot_var *var, void *args);

#endif