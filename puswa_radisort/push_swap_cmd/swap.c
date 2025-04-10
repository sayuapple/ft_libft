/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:53:44 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 17:53:45 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **stack, t_node **head)
{
	t_node	*prev;
	int		tmp1;
	int		tmp2;

	*stack = *head;
	if (*stack && (*stack)->next)
	{
		tmp1 = (*stack)->num;
		prev = *stack;
		*stack = (*stack)->next;
		tmp2 = (*stack)->num;
		(*stack)->num = tmp1;
		prev->num = tmp2;
		write(1, "sa\n", 3);
	}
	*stack = *head;
}

void	sb(t_node **stack, t_node **head)
{
	t_node	*prev;
	int		tmp1;
	int		tmp2;

	*stack = *head;
	if (*stack && (*stack)->next)
	{
		tmp1 = (*stack)->num;
		prev = *stack;
		*stack = (*stack)->next;
		tmp2 = (*stack)->num;
		(*stack)->num = tmp1;
		prev->num = tmp2;
		write(1, "sb\n", 3);
	}
	*stack = *head;
}

void	ss(t_node **st_a, t_node **head_a, t_node **st_b, t_node **head_b)
{
	t_node	*prev_a;
	t_node	*prev_b;
	int		tmp1;
	int		tmp2;

	if (*st_a && (*st_a)->next && *st_b && (*st_b)->next)
	{
		*st_a = *head_a;
		tmp1 = (*st_a)->num;
		prev_a = *st_a;
		*st_a = (*st_a)->next;
		tmp2 = (*st_a)->num;
		(*st_a)->num = tmp1;
		prev_a->num = tmp2;
		*st_b = *head_b;
		tmp1 = (*st_b)->num;
		prev_b = *st_b;
		*st_b = (*st_b)->next;
		tmp2 = (*st_b)->num;
		(*st_b)->num = tmp1;
		prev_b->num = tmp2;
		write(1, "ss\n", 3);
	}
	*st_a = *head_a;
	*st_b = *head_b;
}
