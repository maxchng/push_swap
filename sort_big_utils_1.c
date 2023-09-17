/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:37:55 by ychng             #+#    #+#             */
/*   Updated: 2023/09/17 17:02:32 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index(t_linked_list *stack)
{
	int		index;
	t_node	*current;

	index = 0;
	current = stack->head;
	while (current)
	{
		current->index = index++;
		current = current->next;
	}
}

int	count_stack_size(t_linked_list *stack)
{
	int		size;
	t_node	*current;

	size = 0;
	current = stack->head;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	find_min_num(t_linked_list *stack)
{
	int		min_num;
	t_node	*current;

	min_num = stack->head->data;
	current = stack->head;
	while (current)
	{
		if (min_num > current->data)
			min_num = current->data;
		current = current->next;
	}
	return (min_num);
}

int	find_max_num(t_linked_list *stack)
{
	int		max_num;
	t_node	*current;

	max_num = stack->head->data;
	current = stack->head;
	while (current)
	{
		if (max_num < current->data)
			max_num = current->data;
		current = current->next;
	}
	return (max_num);
}

int	find_max_index(t_linked_list *stack)
{
	int		max_num;
	t_node	*current;

	add_index(stack);
	max_num = find_max_num(stack);
	current = stack->head;
	while (current)
	{
		if (current->data == max_num)
			break ;
		current = current->next;
	}
	return (current->index);
}
