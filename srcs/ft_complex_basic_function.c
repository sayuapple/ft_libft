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
//複素平面上での複素数の原点からの距離
//powではなく直接乗算する

t_complex	ft_conj(t_complex c)
{
	c.imag *= -1;
	return (c);
}

double	ft_carg(t_complex c)
{
	return (atan2(c.imag, c.real));
}
//複素数の偏角(複素数が実数軸に対してどれだけ傾いているか)を計算
//結果はラジアン単位(-πからπ)
