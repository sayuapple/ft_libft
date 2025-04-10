/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:50:11 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 17:50:56 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort(int num, t_node *head_a, t_node *stack_a)
{
	t_node	*stack_b;
	t_node	*head_b;

	stack_b = NULL;
	head_b = stack_b;
	stack_a = head_a;
	if (num == 2)
		sort_two(head_a, stack_a);
	else if (num == 3)
		sort_three(&head_a, &stack_a, true);
	else if (num == 4)
		sort_four(head_a, stack_a, head_b, stack_b);
	else if (num == 5)
		sort_five(head_a, stack_a, head_b, stack_b);
	else if (num >= 6)
		sort_any(num, head_a, stack_a, head_b);
}

void	sort_argv(int num, t_node **stack_a, t_node **head_a)
{
	*stack_a = *head_a;
	coordinate_compression(stack_a, head_a);
	check_duplication(stack_a);
	check_need_sort(stack_a, head_a);
	sort(num, *head_a, *stack_a);
}

void	proce_argv(const char *str, t_node **stack_a, t_node **head_a)
{
	char	**tokens;
	int		j;

	tokens = ft_split(str, ' ');
	if (!tokens)
		error_free_exit(stack_a);
	j = 0;
	while (tokens[j])
	{
		(*stack_a)->num = ps_atoi(tokens[j], stack_a, head_a);
		if (tokens[j + 1])
		{
			(*stack_a)->next = ps_lstnew(stack_a, head_a);
			*stack_a = (*stack_a)->next;
		}
		j++;
	}
	j = 0;
	while (tokens[j])
	{
		free(tokens[j]);
		j++;
	}
	free(tokens);
	sort_argv(j, stack_a, head_a);
}

void	initialize_stack(int argc, char *argv[], t_node **stack_a,
		t_node **head_a)
{
	int	i;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	*head_a = NULL;
	*stack_a = ps_lstnew(stack_a, head_a);
	if (!(*stack_a))
		exit(EXIT_FAILURE);
	*head_a = *stack_a;
	if (argc == 2)
		proce_argv(argv[1], stack_a, head_a);
	else
	{
		i = 1;
		while (i < argc)
		{
			(*stack_a)->num = ps_atoi(argv[i], stack_a, head_a);
			if (i != argc - 1)
			{
				(*stack_a)->next = ps_lstnew(stack_a, head_a);
				*stack_a = (*stack_a)->next;
			}
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*head_a;

	initialize_stack(argc, argv, &stack_a, &head_a);
	stack_a = head_a;
	coordinate_compression(&stack_a, &head_a);
	check_duplication(&stack_a);
	check_need_sort(&stack_a, &head_a);
	sort(argc - 1, head_a, stack_a);
	return (0);
}
