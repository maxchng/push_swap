/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:35:31 by ychng             #+#    #+#             */
/*   Updated: 2023/09/20 00:20:24 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_linked_list *stack_a, int should_print)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	swap(stack_a);
	if (should_print)
		write(1, "sa\n", 3);
}

void	sb(t_linked_list *stack_b, int should_print)
{
	if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	swap(stack_b);
	if (should_print)
		write(1, "sb\n", 3);
}

void	ss(t_linked_list *stack_a, t_linked_list *stack_b, int should_print)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	else if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	swap(stack_a);
	swap(stack_b);
	if (should_print)
		write(1, "ss\n", 3);
}

void	pa(t_linked_list *stack_a, t_linked_list *stack_b, int should_print)
{
	if (stack_b->head == NULL)
		return ;
	push(stack_b, stack_a);
	if (should_print)
		write(1, "pa\n", 3);
}

void	pb(t_linked_list *stack_a, t_linked_list *stack_b, int should_print)
{
	if (stack_a->head == NULL)
		return ;
	push(stack_a, stack_b);
	if (should_print)
		write(1, "pb\n", 3);
}
