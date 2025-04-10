/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:51:05 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 17:51:07 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_node *head_a, t_node *stack_a)
{
	if (head_a->num > stack_a->next->num)
	{
		sa(&stack_a, &head_a);
		all_stack_free(&stack_a);
		exit(EXIT_SUCCESS);
	}
	else
	{
		all_stack_free(&stack_a);
		exit(EXIT_SUCCESS);
	}
}
