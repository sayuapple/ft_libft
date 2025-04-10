/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:50:49 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 17:50:51 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	check_sign(const char *str, int *sign, t_node **st_a, t_node **hd_a)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
		if (!ft_isdigit(str[i]))
		{
			*st_a = *hd_a;
			error_free_exit(st_a);
		}
	}
	return (i);
}

void	check_error(const char str, long long res, t_node **st_a, t_node **hd_a)
{
	if (!ft_isdigit(str) && str != '\0')
	{
		*st_a = *hd_a;
		error_free_exit(st_a);
	}
	else if (res > INT_MAX || res < INT_MIN)
	{
		*st_a = *hd_a;
		error_free_exit(st_a);
	}
}

int	ps_atoi(const char *str, t_node **stack_a, t_node **head_a)
{
	long long	res;
	int			sign;
	size_t		i;

	res = 0;
	sign = 1;
	i = check_sign(str, &sign, stack_a, head_a);
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (sign * (str[i] - '0'));
		check_error(str[i], res, stack_a, head_a);
		i++;
	}
	while (str[i] != '\0')
		check_error(str[i], res, stack_a, head_a);
	return ((int)res);
}
