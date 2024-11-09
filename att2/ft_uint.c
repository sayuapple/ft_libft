/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:01:31 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/08 16:50:41 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uint(unsigned int uint)
{
	char	str;
	int		digit;

	digit = 1;
	if (uint > 9)
		digit += ft_uint(uint / 10);
	str = (uint % 10) + '0';
	write(1, &str, 1);
	return (digit);
}
