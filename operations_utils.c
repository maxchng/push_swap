/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:40:13 by ychng             #+#    #+#             */
/*   Updated: 2023/09/11 16:52:57 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int num)
{
	t_node	*newnode;

	newnode = ft_calloc(1, sizeof(t_node));
	if (!newnode)
	{
		write(2, "ft_calloc() failed in create_node().\n", 37);
		return (NULL);
	}
	newnode->data = num;
	return (newnode);
}

t_node	*pop(t_linked_list *stack)
{
	t_node	*first;

	first = stack->head;
	stack->head = first->next;
	first->next = 0;
	first->prev = 0;
	if (stack->head != NULL)
		stack->head->prev = 0;
	return (first);
}

void	link_list(t_linked_list *stack, t_node *node, int insert_after_head)
{
	if (stack->head == 0)
	{
		stack->head = node;
		stack->tail = node;
	}
	else if (insert_after_head == 1)
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
	}
	else if (insert_after_head == 0)
	{
		node->prev = stack->tail;
		stack->tail->next = node;
		stack->tail = node;
	}
}
