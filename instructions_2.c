/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:24:23 by ychng             #+#    #+#             */
/*   Updated: 2023/09/15 16:17:09 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_linked_list *stack_a)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	shift(stack_a, 1);
	write(1, "ra\n", 3);
}

void	rb(t_linked_list *stack_b)
{
	if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	shift(stack_b, 1);
	write(1, "rb\n", 3);
}

void	rr(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	else if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	shift(stack_a, 1);
	shift(stack_b, 1);
	write(1, "rr\n", 3);
}
