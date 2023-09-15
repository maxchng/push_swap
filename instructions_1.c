/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:35:31 by ychng             #+#    #+#             */
/*   Updated: 2023/09/15 15:01:51 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_linked_list *stack_a)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	swap(stack_a);
}

void	sb(t_linked_list *stack_b)
{
	if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	swap(stack_b);
}

void	ss(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	else if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	swap(stack_a);
	swap(stack_b);
}

void	pa(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (stack_b->head == NULL)
		return ;
	push(stack_b, stack_a);
}

void	pb(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (stack_a->head == NULL)
		return ;
	push(stack_a, stack_b);
}
