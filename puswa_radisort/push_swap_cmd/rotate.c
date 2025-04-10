/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:58:28 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 17:58:29 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_node **stack, t_node **head)
{
	size_t	count;

	*stack = *head;
	if (*stack && (*stack)->next)
	{
		count = 0;
		while ((*stack)->next)
		{
			*stack = (*stack)->next;
			count++;
		}
		(*stack)->next = *head;
		*stack = *head;
		*head = (*stack)->next;
		*stack = *head;
		while (count > 0)
		{
			*stack = (*stack)->next;
			count--;
		}
		(*stack)->next = NULL;
	}
}

void	ra(t_node **stack, t_node **head)
{
	*stack = *head;
	if (*stack && (*stack)->next)
	{
		rotate(stack, head);
		write(1, "ra\n", 3);
		*stack = *head;
	}
}

void	rb(t_node **stack, t_node **head)
{
	*stack = *head;
	if (*stack && (*stack)->next)
	{
		rotate(stack, head);
		write(1, "rb\n", 3);
		*stack = *head;
	}
}

void	rr(t_node **st_a, t_node **head_a, t_node **st_b, t_node **head_b)
{
	*st_a = *head_a;
	*st_b = *head_b;
	if (*st_a && (*st_a)->next && (*st_b) && (*st_b)->next)
	{
		rotate(st_a, head_a);
		rotate(st_b, head_b);
		write(1, "rr\n", 3);
		*st_a = *head_a;
		*st_b = *head_b;
	}
}
