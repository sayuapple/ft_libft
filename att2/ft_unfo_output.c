/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unfo_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:01:36 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/05 13:01:39 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unfo_output(const char *input, va_list args)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
		{
			i++;
			c += ft_format(input[i], args);
		}
		else
		{
			ft_putchar_fd(input[i], 1);
			c++;
		}
		i++;
	}
	return (c);
}
// add num of words from 'ft_format' and return it(c)