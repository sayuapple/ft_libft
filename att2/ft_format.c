/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:01:17 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/05 14:03:08 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(int c, va_list args)
{
	int	n;

	n = 0;
	if (c == 'c')
		n = ft_char(va_arg(args, int));
	else if (c == 's')
		n = ft_str(va_arg(args, char *));
	else if (c == 'p')
		n = ft_pointer((unsigned long long)va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		n = ft_int(va_arg(args, int));
	else if (c == 'u')
		n = ft_uint((unsigned long long)va_arg(args, unsigned long long));
	else if (c == 'x')
		n = ft_hex(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		n = ft_hex(va_arg(args, unsigned int), 2);
	else if (c == '%')
		n = ft_str_count("%");
	return (n);
}
//va_arg(args, xxx) can translate the type 