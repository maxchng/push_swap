/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:48:15 by ychng             #+#    #+#             */
/*   Updated: 2023/09/11 17:12:23 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_linked_list
{
	t_node	*head;
	t_node	*tail;	
}	t_linked_list;

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

#endif