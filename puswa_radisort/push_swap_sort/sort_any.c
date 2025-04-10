/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:52:02 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 17:52:04 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	get_max_rank_bin(int rank)
{
	size_t	max_rank_digits;

	max_rank_digits = 0;
	while (rank)
	{
		rank /= 2;
		max_rank_digits++;
	}
	return (max_rank_digits);
}

void	radix_sort(t_node **hd_a, t_node **st_a, t_node **hd_b, int num)
{
	int		bin_digit;
	int		j;
	int		max_rank_bin_digits;
	t_node	**st_b;

	max_rank_bin_digits = get_max_rank_bin(num);
	st_b = hd_b;
	bin_digit = 0;
	while (bin_digit < max_rank_bin_digits)
	{
		j = 0;
		while (j < num)
		{
			if ((*st_a)->rank >> bin_digit & 1)
				ra(st_a, hd_a);
			else
				pb(hd_a, st_a, hd_b, st_b);
			j++;
		}
		while (*st_b)
			pa(hd_b, st_b, hd_a, st_a);
		bin_digit++;
	}
}

void	sort_any(int num, t_node *hd_a, t_node *st_a, t_node *hd_b)
{
	radix_sort(&hd_a, &st_a, &hd_b, num);
	all_stack_free(&st_a);
	exit(EXIT_SUCCESS);
}
