/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:00:55 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/07 13:32:51 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int(int i)
{
	char	*str;
	int		n;

	str = ft_itoa(i);
	n = ft_str_count(str);
	free(str);
	return (n);
}
