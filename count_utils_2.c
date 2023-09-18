/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:35:53 by ychng             #+#    #+#             */
/*   Updated: 2023/09/18 19:51:29 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	steps_min_to_top_of_b(t_node *current_a, t_linked_list *stack_b)
{
	int		min_b;
	int		size_b;
	t_node	*current_b;

	min_b = find_min_num(stack_b);
	size_b = count_stack_size(stack_b);
	current_b = stack_b->head;
	while (current_b)
	{
		if (current_b->data == min_b)
		{
			if (current_b->index > (size_b / 2))
				current_a->steps.rrb += (size_b - current_b->index);
			else
				current_a->steps.rb += (current_b->index);
		}
		current_b = current_b->next;
	}
}

void	steps_max_to_top_of_b(t_node *current_a, t_linked_list *stack_b)
{
	int		max_b;
	int		size_b;
	t_node	*current_b;

	max_b = find_max_num(stack_b);
	size_b = count_stack_size(stack_b);
	current_b = stack_b->head;
	while (current_b)
	{
		if (current_b->data == max_b)
		{
			if (current_b->index > (size_b / 2))
				current_a->steps.rrb += (size_b - current_b->index);
			else
				current_a->steps.rb += (current_b->index);
		}
		current_b = current_b->next;
	}
}

void	set_steps(t_node *current_a, t_node *current_b, t_linked_list *stack_b)
{
	int	size_b;

	size_b = count_stack_size(stack_b);
	if (current_b->next->index > (size_b / 2))
		current_a->steps.rrb = (size_b - current_b->next->index);
	else
		current_a->steps.rb = current_b->next->index;
}
