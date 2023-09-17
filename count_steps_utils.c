/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:42:40 by ychng             #+#    #+#             */
/*   Updated: 2023/09/17 16:57:04 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	steps_small_top_big_bottom(t_node *current_a, t_linked_list *stack_b)
{
	int		a_data;
	int		b_data;
	int		next_b_data;
	t_node	*current_b;

	current_b = stack_b->head;
	a_data = current_a->data;
	b_data = current_b->data;
	if (a_data > b_data && a_data < stack_b->tail->data)
		return ;
	while (current_b->next)
	{
		next_b_data = current_b->next->data;
		if (a_data > next_b_data && a_data < b_data)
			set_steps(current_a, current_b, stack_b);
		current_b = current_b->next;
		b_data = current_b->data;
	}
}
