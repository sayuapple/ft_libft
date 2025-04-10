/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:53:17 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 17:53:24 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_node **head_a, t_node **st_a, t_node **head_b, t_node **st_b)
{
	t_node	*push_node;

	if (*head_a)
	{
		push_node = *head_a;
		*head_a = (*head_a)->next;
		if (!(*head_b))
		{
			push_node->next = NULL;
			*head_b = push_node;
		}
		else
		{
			push_node->next = *head_b;
			*head_b = push_node;
		}
		write(1, "pb\n", 3);
		*st_a = *head_a;
		*st_b = *head_b;
	}
}

void	pa(t_node **head_b, t_node **st_b, t_node **head_a, t_node **st_a)
{
	t_node	*push_node;

	if (*head_b)
	{
		push_node = *head_b;
		*head_b = (*head_b)->next;
		if (!(*head_a))
		{
			push_node->next = NULL;
			*head_a = push_node;
		}
		else
		{
			push_node->next = *head_a;
			*head_a = push_node;
		}
		write(1, "pa\n", 3);
		*st_a = *head_a;
		*st_b = *head_b;
	}
}
