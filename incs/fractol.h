/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:01:28 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 18:01:39 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include "renderer.h"
# include "types.h"
# include <stddef.h>

typedef struct s_plot_var
{
	int					*index;
	t_position			position;
	int					max_iter;
	int					iter;
}						t_plot_var;

typedef unsigned int	(*t_plot_func)(t_plot_var *var, void *args_ptr);

typedef struct s_fractol
{
	char				*title;
	t_size				size;
	int					max_iter;
	t_position			position;
	double				scale;
	t_plot_func			plot_func;
	void				*plot_args;
}						t_fractol;

typedef struct s_fractol_local
{
	t_fractol			*var;
	t_renderer			*renderer;
	int					iter;
}						t_fractol_local;

void					fractol(t_fractol *var);

#endif