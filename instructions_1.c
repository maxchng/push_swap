/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:35:31 by ychng             #+#    #+#             */
/*   Updated: 2023/09/11 18:27:08 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_linked_list *stack_a, t_steps *steps)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	swap(stack_a);
	steps->sa++;
}

void	sb(t_linked_list *stack_b, t_steps *steps)
{
	if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	swap(stack_b);
	steps->sb++;
}

void	ss(t_linked_list *stack_a, t_linked_list *stack_b, t_steps *steps)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	else if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	swap(stack_a);
	swap(stack_b);
	steps->ss++;
}

void	pa(t_linked_list *stack_a, t_linked_list *stack_b, t_steps *steps)
{
	if (stack_b->head == NULL)
		return ;
	push(stack_b, stack_a);
	steps->pa++;
}

void	pb(t_linked_list *stack_a, t_linked_list *stack_b, t_steps *steps)
{
	if (stack_a->head == NULL)
		return ;
	push(stack_a, stack_b);
	steps->pb++;
}
