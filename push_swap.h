/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:48:15 by ychng             #+#    #+#             */
/*   Updated: 2023/09/19 23:57:16 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_steps
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_steps;

typedef struct s_node
{
	int				data;
	int				rank;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
	t_steps			steps;
}	t_node;

typedef struct s_linked_list
{
	t_node	*head;
	t_node	*tail;	
}	t_linked_list;

typedef struct s_stacks
{
	t_linked_list	*stack_a;
	t_linked_list	*stack_b;
}	t_stacks;

// utils.c
int		is_not_sorted(t_linked_list *stack_a);

// operations_utils.c
t_node	*create_node(int num);
t_node	*pop(t_linked_list *stack);
void	link_list(t_linked_list *stack, t_node *node, int insert_after_head);

// operations.c
void	swap(t_linked_list *stack);
void	push(t_linked_list *src, t_linked_list *dest);
void	shift(t_linked_list *stack, int up);
void	show_list(t_linked_list *stack);

// instructions_1.c
void	sa(t_linked_list *stack_a);
void	sb(t_linked_list *stack_b);
void	ss(t_linked_list *stack_a, t_linked_list *stack_b);
void	pa(t_linked_list *stack_a, t_linked_list *stack_b);
void	pb(t_linked_list *stack_a, t_linked_list *stack_b);

// instructions_2.c
void	ra(t_linked_list *stack_a);
void	rb(t_linked_list *stack_b);
void	rr(t_linked_list *stack_a, t_linked_list *stack_b);

// instructions_3.c
void	rra(t_linked_list *stack_a);
void	rrb(t_linked_list *stack_b);
void	rrr(t_linked_list *stack_a, t_linked_list *stack_b);

// ft_strtok.c
char	*ft_strtok(char *str, const char *delim);

// ps_atoi.c
long	ps_atoi(const char *str);

// parse_argv.c
void	parse_argv(t_linked_list *stack_a, int argc, char **argv);

// err_handling.c
void	free_stack(t_linked_list *stack);
void	exit_error(t_linked_list *stack, char *msg);

// sort_small.c
void	sort_two(t_linked_list *stack_a);
void	sort_three(t_linked_list *stack_a, t_linked_list *stack_b);
void	sort_four(t_linked_list *stack_a, t_linked_list *stack_b);
void	sort_five(t_linked_list *stack_a, t_linked_list *stack_b);

// sort_small_utils.c
void	add_rank(t_linked_list *stack);
void	set_ra_rra(t_node *current_a, t_linked_list *stack_a);

// sort_big.c
void	sort_big(t_linked_list *stack_a, t_linked_list *stack_b);

// sort_big_utils_1.c
void	add_index(t_linked_list *stack);
int		count_stack_size(t_linked_list *stack);
int		find_min_num(t_linked_list *stack);
int		find_max_num(t_linked_list *stack);
int		find_max_index(t_linked_list *stack);

// sort_big_utils_2.c
int		sum_steps(t_node *current_a);
void	run_steps(t_node *current_a, t_stacks stacks);
int		find_min_steps_index(t_linked_list *stack_a);
void	sort_descending(t_linked_list *stack);

// count_ascending.c
void	count_ascending_steps(t_linked_list *stack_a, t_linked_list *stack_b);

// count_descending.c
void	count_descending_steps(t_linked_list *stack_a, t_linked_list *stack_b);

// count_utils_1.c
void	steps_to_top_of_a(t_linked_list *stack_a);
void	steps_for_rr_rrr(t_linked_list *stack_a);
void	steps_small_top_big_bottom(t_node *current_a, t_linked_list *stack_b);
void	steps_big_top_small_bottom(t_node *current_a, t_linked_list *stack_b);

// count_utils_2.c
void	steps_min_to_top_of_b(t_node *current_a, t_linked_list *stack_b);
void	steps_max_to_top_of_b(t_node *current_a, t_linked_list *stack_b);
void	set_steps(t_node *current_a, t_node *current_b, t_linked_list *stack_b);

#endif