/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:03:31 by ychng             #+#    #+#             */
/*   Updated: 2023/09/19 19:32:58 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_linked_list *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack->head;
	second = first->next;
	third = second->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = 0;
	third->prev = first;
	stack->head = second;
}

void	push(t_linked_list *src, t_linked_list *dest)
{
	t_node	*first;

	first = pop(src);
	link_list(dest, first, 1);
}

void	shift(t_linked_list *stack, int up)
{
	t_node	*first;
	t_node	*last;

	first = stack->head;
	last = stack->tail;
	if (up == 1)
	{
		stack->head = first->next;
		stack->head->prev = 0;
		first->next = 0;
		last->next = first;
		stack->tail = first;
		stack->tail->prev = last;
	}
	else if (up == 0)
	{
		stack->tail = last->prev;
		stack->tail->next = 0;
		last->prev = 0;
		first->prev = last;
		stack->head = last;
		stack->head->next = first;
	}
}

void	show_list(t_linked_list *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}
