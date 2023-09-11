/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:48:15 by ychng             #+#    #+#             */
/*   Updated: 2023/09/11 18:25:12 by ychng            ###   ########.fr       */
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

typedef struct s_steps
{
	unsigned int	sa;
	unsigned int	sb;
	unsigned int	ss;
	unsigned int	pa;
	unsigned int	pb;
	unsigned int	ra;
	unsigned int	rb;
	unsigned int	rr;
	unsigned int	rra;
	unsigned int	rrb;
	unsigned int	rrr;
}	t_steps;

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
void	sa(t_linked_list *stack_a, t_steps *steps);
void	sb(t_linked_list *stack_b, t_steps *steps);
void	ss(t_linked_list *stack_a, t_linked_list *stack_b, t_steps *steps);
void	pa(t_linked_list *stack_a, t_linked_list *stack_b, t_steps *steps);
void	pb(t_linked_list *stack_a, t_linked_list *stack_b, t_steps *steps);

// instructions_2.c
void	ra(t_linked_list *stack_a, t_steps *steps);
void	rb(t_linked_list *stack_b, t_steps *steps);
void	rr(t_linked_list *stack_a, t_linked_list *stack_b, t_steps *steps);

// instructions_3.c
void	rra(t_linked_list *stack_a, t_steps *steps);
void	rrb(t_linked_list *stack_b, t_steps *steps);
void	rrr(t_linked_list *stack_a, t_linked_list *stack_b, t_steps *steps);

#endif