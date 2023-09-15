/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:34:23 by ychng             #+#    #+#             */
/*   Updated: 2023/09/15 15:02:27 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_linked_list *stack_a)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	shift(stack_a, 0);
}

void	rrb(t_linked_list *stack_b)
{
	if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	shift(stack_b, 0);
}

void	rrr(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	else if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	shift(stack_a, 0);
	shift(stack_b, 0);
}
