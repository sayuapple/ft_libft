/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:00:50 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/09 17:33:18 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int i, int f)
{
	char	*hex;
	int		n;

	hex = ft_pointer_base((unsigned long long)i, 16);
	if (f == 1)
		hex = ft_tolower_all(hex);
	n = ft_str_count(hex);
	free(hex);
	return (n);
}
