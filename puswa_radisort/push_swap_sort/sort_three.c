/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:51:16 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 17:51:18 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_case1(t_node **head, t_node **stack, bool is_exit)
{
	int	top_num;
	int	middle_num;
	int	bottom_num;

	top_num = (*stack)->num;
	middle_num = (*stack)->next->num;
	bottom_num = (*stack)->next->next->num;
	if (middle_num < bottom_num && top_num < bottom_num)
		sa(stack, head);
	else if (middle_num > bottom_num && top_num > bottom_num)
	{
		sa(stack, head);
		rra(stack, head);
	}
	else if (middle_num < bottom_num && top_num > bottom_num)
		ra(stack, head);
	if (is_exit)
	{
		*stack = *head;
		all_stack_free(stack);
		exit(EXIT_SUCCESS);
	}
}

void	sort_case2(t_node **head, t_node **stack, bool is_exit)
{
	int	top_num;
	int	middle_num;
	int	bottom_num;

	top_num = (*stack)->num;
	middle_num = (*stack)->next->num;
	bottom_num = (*stack)->next->next->num;
	if (middle_num > bottom_num && top_num < bottom_num)
	{
		sa(stack, head);
		ra(stack, head);
	}
	else if (middle_num > bottom_num && top_num > bottom_num)
	{
		rra(stack, head);
	}
	if (is_exit)
	{
		*stack = *head;
		all_stack_free(stack);
		exit(EXIT_SUCCESS);
	}
}

void	sort_three(t_node **head, t_node **stack, bool is_exit)
{
	int	top_num;
	int	middle_num;

	top_num = (*stack)->num;
	middle_num = (*stack)->next->num;
	if (top_num > middle_num)
		sort_case1(head, stack, is_exit);
	else if (top_num < middle_num)
		sort_case2(head, stack, is_exit);
}
