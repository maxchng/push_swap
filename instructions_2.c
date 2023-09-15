/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:24:23 by ychng             #+#    #+#             */
/*   Updated: 2023/09/15 15:02:12 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_linked_list *stack_a)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	shift(stack_a, 1);
}

void	rb(t_linked_list *stack_b)
{
	if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	shift(stack_b, 1);
}

void	rr(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	else if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	shift(stack_a, 1);
	shift(stack_b, 1);
}
