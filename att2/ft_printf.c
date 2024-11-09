/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:51:02 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/09 13:34:29 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		num;

	num = 0;
	if (!input)
		return (-1);
	va_start(args, input);
	num = ft_unfo_output(input, args);
	va_end(args);
	return (num);
}
// va_start can put 'input' into 'args'
