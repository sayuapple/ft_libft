/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:04:12 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/09 14:41:32 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ascii to hex
static char	*change_to_hex(unsigned long long usnum, int base, char *rtn, int d)
{
	while (usnum != 0)
	{
		if ((usnum % base) < 10)
			rtn[d - 1] = (usnum % base) + 48;
		else
			rtn[d - 1] = (usnum % base) + 55;
		usnum /= base;
		d--;
	}
	return (rtn);
}

char	*ft_pointer_base(unsigned long long pointer, int base)
{
	char				*point_rtn;
	unsigned long long	usnum;
	int					digit;

	digit = 0;
	usnum = pointer;
	if (pointer == 0)
		return (ft_strdup("0"));
	while (pointer != 0)
	{
		pointer = pointer / base;
		digit++;
	}
	point_rtn = ft_calloc(digit + 1, sizeof(char));
	if (!point_rtn)
		return (0);
	point_rtn = change_to_hex(usnum, base, point_rtn, digit);
	return (point_rtn);
}
