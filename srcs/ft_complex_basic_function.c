/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_basic_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:57:00 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 17:57:02 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_complex.h"
#include <math.h>

double	ft_cabs(t_complex c)
{
	return (sqrt(pow(c.real, 2) + pow(c.imag, 2)));
}

t_complex	ft_conj(t_complex c)
{
	c.imag *= -1;
	return (c);
}

double	ft_carg(t_complex c)
{
	return (atan2(c.imag, c.real));
}