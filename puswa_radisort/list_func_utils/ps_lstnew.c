/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:52:45 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 17:52:46 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ps_lstnew(t_node **stack, t_node **head)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		*stack = *head;
		error_free_exit(stack);
	}
	new_node->num = 0;
	new_node->rank = 0;
	new_node->next = NULL;
	return (new_node);
}
