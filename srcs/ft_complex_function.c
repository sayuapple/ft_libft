/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:56:28 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 21:42:36 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <math.h>

t_complex	ft_cexp(t_complex c)//複素数の指数関数を計算(オイラーの公式)
{
	t_complex	ret;

	ret.real = exp(c.real) * cos(c.imag);//虚数部 bに対する余弦関数cos𝑏を計算
	ret.imag = exp(c.real) * sin(c.imag);//虚数部 bに対する正弦関数sin𝑏を計算
	return (ret);
}

t_complex	ft_cln(t_complex c)
{
	t_complex	ret;

	ret.real = log(sqrt(pow(c.real, 2) + pow(c.imag, 2)));
	ret.imag = ft_carg(c);
	return (ret);
}

t_complex	ft_cpow(t_complex a, t_complex b)
{
	if (!a.imag && !b.imag)
		return ((t_complex){pow(a.real, b.real), 0});
	return (ft_cexp(ft_cmul(b, ft_cln(a))));
}

t_complex	ft_clog(t_complex a, t_complex b)
{
	if (!a.imag && !b.imag)
		return ((t_complex){log(a.real) / log(b.real), 0});
	return (ft_cdiv(ft_cln(a), ft_cln(b)));
}
//exp(自然対数の底𝑒を基数とする指数関数を計算)