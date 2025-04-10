/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:50:35 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 17:50:37 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_stack_free(t_node **stack)
{
	t_node	*free_tmp;

	while (*stack)
	{
		free_tmp = (*stack)->next;
		free(*stack);
		*stack = free_tmp;
	}
}

void	error_free_exit(t_node **stack_a)
{
	write(2, "Error\n", 6);
	all_stack_free(stack_a);
	exit(EXIT_FAILURE);
}

void	check_need_sort(t_node **stack_a, t_node **head_a)
{
	while (*stack_a && (*stack_a)->next)
	{
		if ((*stack_a)->num > (*stack_a)->next->num)
		{
			*stack_a = *head_a;
			return ;
		}
		*stack_a = (*stack_a)->next;
	}
	stack_a = head_a;
	all_stack_free(stack_a);
	exit(EXIT_SUCCESS);
}

void	check_duplication(t_node **stack_a)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = *stack_a;
	tmp2 = tmp1->next;
	while (tmp1)
	{
		while (tmp2)
		{
			if (tmp1->rank == tmp2->rank)
				error_free_exit(stack_a);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		if (tmp1)
			tmp2 = tmp1->next;
	}
}
