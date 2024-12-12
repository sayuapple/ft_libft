/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:01:14 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 18:01:22 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

t_complex	ft_cadd(t_complex a, t_complex b);
t_complex	ft_csub(t_complex a, t_complex b);
t_complex	ft_cmul(t_complex a, t_complex b);
t_complex	ft_cdiv(t_complex a, t_complex b);

double		ft_cabs(t_complex c);
t_complex	ft_conj(t_complex c);
double		ft_carg(t_complex c);

t_complex	ft_cexp(t_complex c);
t_complex	ft_cln(t_complex c);
t_complex	ft_cpow(t_complex a, t_complex b);
t_complex	ft_clog(t_complex a, t_complex b);

#endif