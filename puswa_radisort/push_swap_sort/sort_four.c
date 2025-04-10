/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:51:26 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 17:51:28 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_case1(t_node *hd_a, t_node *st_a, t_node *hd_b, t_node *st_b)
{
	bool	is_exit;

	is_exit = false;
	st_a = hd_a;
	pb(&hd_a, &st_a, &hd_b, &st_b);
	sort_three(&hd_a, &st_a, is_exit);
	pa(&hd_b, &st_b, &hd_a, &st_a);
	all_stack_free(&st_a);
	exit(EXIT_SUCCESS);
}

static void	sort_case2(t_node *hd_a, t_node *st_a, t_node *hd_b, t_node *st_b)
{
	bool	is_exit;

	is_exit = false;
	sa(&st_a, &hd_a);
	pb(&hd_a, &st_a, &hd_b, &st_b);
	sort_three(&hd_a, &st_a, is_exit);
	pa(&hd_b, &st_b, &hd_a, &st_a);
	all_stack_free(&st_a);
	exit(EXIT_SUCCESS);
}

static void	sort_case3(t_node *hd_a, t_node *st_a, t_node *hd_b, t_node *st_b)
{
	bool	is_exit;

	is_exit = false;
	ra(&st_a, &hd_a);
	ra(&st_a, &hd_a);
	pb(&hd_a, &st_a, &hd_b, &st_b);
	sort_three(&hd_a, &st_a, is_exit);
	pa(&hd_b, &st_b, &hd_a, &st_a);
	all_stack_free(&st_a);
	exit(EXIT_SUCCESS);
}

static void	sort_case4(t_node *hd_a, t_node *st_a, t_node *hd_b, t_node *st_b)
{
	bool	is_exit;

	is_exit = false;
	rra(&st_a, &hd_a);
	pb(&hd_a, &st_a, &hd_b, &st_b);
	sort_three(&hd_a, &st_a, is_exit);
	pa(&hd_b, &st_b, &hd_a, &st_a);
	all_stack_free(&st_a);
	exit(EXIT_SUCCESS);
}

void	sort_four(t_node *hd_a, t_node *st_a, t_node *hd_b, t_node *st_b)
{
	int	num_1;
	int	num_2;
	int	num_3;
	int	num_4;

	num_1 = st_a->num;
	num_2 = st_a->next->num;
	num_3 = st_a->next->next->num;
	num_4 = st_a->next->next->next->num;
	if (num_1 < num_2 && num_1 < num_3 && num_1 < num_4)
		sort_case1(hd_a, st_a, hd_b, st_b);
	else if (num_2 < num_1 && num_2 < num_3 && num_2 < num_4)
		sort_case2(hd_a, st_a, hd_b, st_b);
	else if (num_3 < num_1 && num_3 < num_2 && num_3 < num_4)
		sort_case3(hd_a, st_a, hd_b, st_b);
	else if (num_4 < num_1 && num_4 < num_2 && num_4 < num_3)
		sort_case4(hd_a, st_a, hd_b, st_b);
}
