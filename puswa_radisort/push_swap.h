/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:04:05 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/10 18:04:07 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	unsigned long	rank;
	struct s_node	*next;
}					t_node;

int					ps_atoi(const char *str, t_node **stack_a, t_node **head_a);
void				all_stack_free(t_node **stack);
t_node				*ps_lstnew(t_node **stack, t_node **head);
void				sa(t_node **stack, t_node **head);
void				sb(t_node **stack, t_node **head);
void				ss(t_node **st_a, t_node **head_a, t_node **st_b,
						t_node **head_b);
void				pa(t_node **head_b, t_node **st_b, t_node **head_a,
						t_node **st_a);
void				pb(t_node **head_a, t_node **st_a, t_node **head_b,
						t_node **st_b);
void				ra(t_node **stack, t_node **head);
void				rb(t_node **stack, t_node **head);
void				rotate(t_node **stack, t_node **head);
void				rr(t_node **st_a, t_node **head_a, t_node **st_b,
						t_node **head_b);
void				rra(t_node **stack, t_node **head);
void				reverse_rotate(t_node **stack, t_node **head);
void				rra(t_node **stack, t_node **head);
void				rrb(t_node **stack, t_node **head);
void				rrr(t_node **st_a, t_node **head_a, t_node **st_b,
						t_node **head_b);
void				sort_two(t_node *head_a, t_node *stack_a);
void				sort_three(t_node **hd_a, t_node **st_a, bool is_exit);
void				sort_four(t_node *hd_a, t_node *st_a, t_node *hd_b,
						t_node *st_b);
void				sort_five(t_node *hd_a, t_node *st_a, t_node *hd_b,
						t_node *st_b);
void				sort_any(int argc, t_node *hd_a, t_node *st_a,
						t_node *hd_b);
void				coordinate_compression(t_node **stack_a, t_node **head_a);
void				error_free_exit(t_node **stack_a);

void				check_need_sort(t_node **stack_a, t_node **head_a);
void				check_duplication(t_node **stack_a);
#endif
