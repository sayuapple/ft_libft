/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:01:17 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/09 17:39:01 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_count(char *c)
{
	// int	num;

	if (!c)
		return (0);
	// num = ft_strlen(c);
	// ft_putstr_fd(c, 1);
	// return (num);
	return (write(1, c, ft_strlen(c)));
}
