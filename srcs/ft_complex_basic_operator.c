/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:57:12 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 17:57:43 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <math.h>

t_complex	ft_cadd(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.real = a.real + b.real;
	ret.imag = a.imag + b.imag;
	return (ret);
}

t_complex	ft_csub(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.real = a.real - b.real;
	ret.imag = a.imag - b.imag;
	return (ret);
}

t_complex	ft_cmul(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.real = a.real * b.real - a.imag * b.imag;
	ret.imag = a.real * b.imag + a.imag * b.real;
	return (ret);
}

t_complex	ft_cdiv(t_complex a, t_complex b)
{
	t_complex	ret;
	double		pow2_abs_b;

	ret = ft_cmul(a, ft_conj(b));
	pow2_abs_b = pow(b.real, 2) + pow(b.imag, 2);
	ret.real /= pow2_abs_b;
	ret.imag /= pow2_abs_b;
	return (ret);
}