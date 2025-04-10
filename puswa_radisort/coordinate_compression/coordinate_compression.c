/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:52:56 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 17:52:57 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	coordinate_compression(t_node **stack_a, t_node **head_a)
{
	t_node	*target;
	size_t	rank_count;

	*stack_a = *head_a;
	target = *stack_a;
	while (target)
	{
		rank_count = 0;
		while (*stack_a)
		{
			if (target->num >= (*stack_a)->num)
			{
				rank_count++;
				target->rank = rank_count;
			}
			*stack_a = (*stack_a)->next;
		}
		*stack_a = *head_a;
		target = target->next;
	}
	*stack_a = *head_a;
}
// same num has same rank