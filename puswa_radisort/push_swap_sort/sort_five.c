/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:51:38 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 17:51:39 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

static int	min_sign(t_node **st_a, t_node **hd_a, int target)
{
	int	result;

	result = 0;
	while (*st_a && (*st_a)->num != target)
	{
		*st_a = (*st_a)->next;
		result++;
	}
	*st_a = *hd_a;
	return (result);
}

static int	get_min(t_node **st_a, t_node **hd_a)
{
	int	result;

	result = (*st_a)->num;
	while (*st_a)
	{
		*st_a = (*st_a)->next;
		if (*st_a && result > (*st_a)->num)
			result = (*st_a)->num;
	}
	*st_a = *hd_a;
	return (result);
}

static void	two_pb(t_node **hd_a, t_node **st_a, t_node **hd_b, t_node **st_b)
{
	int	target;
	int	sign;

	target = get_min(st_a, hd_a);
	sign = min_sign(st_a, hd_a, target);
	if (sign == 3 || sign == 4)
	{
		while (*st_a && (*st_a)->num != target)
			rra(st_a, hd_a);
	}
	else
	{
		while (*st_a && (*st_a)->num != target)
			ra(st_a, hd_a);
	}
	pb(hd_a, st_a, hd_b, st_b);
	*st_a = *hd_a;
}

void	sort_five(t_node *hd_a, t_node *st_a, t_node *hd_b, t_node *st_b)
{
	bool	is_exit;

	is_exit = false;
	two_pb(&hd_a, &st_a, &hd_b, &st_b);
	two_pb(&hd_a, &st_a, &hd_b, &st_b);
	sort_three(&hd_a, &st_a, is_exit);
	pa(&hd_b, &st_b, &hd_a, &st_a);
	pa(&hd_b, &st_b, &hd_a, &st_a);
	all_stack_free(&st_a);
	exit(EXIT_SUCCESS);
}
