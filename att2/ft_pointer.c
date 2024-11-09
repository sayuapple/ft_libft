/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:01:07 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/08 16:06:30 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long long pointer)
{
	char	*point_ad;
	int		num;

	if (pointer == 0)
		return (write(1, "(nil)", ft_strlen("(nil)")));
	point_ad = ft_tolower_all(ft_pointer_base(pointer, 16));
	num = ft_str_count("0x");
	num += ft_str_count(point_ad);
	free(point_ad);
	return (num);
}
