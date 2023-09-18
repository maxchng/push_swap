/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:37:44 by ychng             #+#    #+#             */
/*   Updated: 2023/09/18 17:29:03 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	steps_to_top_of_a(t_linked_list *stack_a)
{
	int		size_a;
	t_node	*current_a;

	add_index(stack_a);
	size_a = count_stack_size(stack_a);
	current_a = stack_a->head;
	while (current_a)
	{
		if (current_a->index > (size_a / 2))
			current_a->steps.rra += (size_a - current_a->index);
		else
			current_a->steps.ra += current_a->index;
		current_a = current_a->next;
	}
}

void	steps_to_handle_min_max(t_stacks stacks)
{
	int		min_b;
	int		max_b;
	t_node	*current_a;

	add_index(stacks.stack_b);
	min_b = find_min_num(stacks.stack_b);
	max_b = find_max_num(stacks.stack_b);
	current_a = stacks.stack_a->head;
	while (current_a)
	{
		if (current_a->data < min_b || current_a->data > max_b)
			steps_max_to_top_of_b(current_a, stacks.stack_b);
		current_a = current_a->next;
	}
}

static void	steps_for_other_numbers(t_stacks stacks)
{
	int		min_b;
	int		max_b;
	t_node	*current_a;

	add_index(stacks.stack_b);
	min_b = find_min_num(stacks.stack_b);
	max_b = find_max_num(stacks.stack_b);
	current_a = stacks.stack_a->head;
	while (current_a)
	{
		steps_small_top_big_bottom(current_a, stacks.stack_b);
		current_a = current_a->next;
	}
}

void	steps_for_rr_rrr(t_linked_list *stack_a)
{
	t_node	*current_a;

	current_a = stack_a->head;
	while (current_a)
	{
		if (current_a->steps.ra && current_a->steps.rb)
		{
			current_a->steps.ra--;
			current_a->steps.rb--;
			current_a->steps.rr++;
		}
		if (current_a->steps.rra && current_a->steps.rrb)
		{
			current_a->steps.rra--;
			current_a->steps.rrb--;
			current_a->steps.rrr++;
		}
		current_a = current_a->next;
	}
}

void	count_sorting_steps(t_linked_list *stack_a, t_linked_list *stack_b)
{
	t_node	*current_a;

	current_a = stack_a->head;
	while (current_a)
	{
		current_a->steps = (t_steps){0};
		current_a = current_a->next;
	}
	steps_to_top_of_a(stack_a);
	steps_to_handle_min_max((t_stacks){stack_a, stack_b});
	steps_for_other_numbers((t_stacks){stack_a, stack_b});
	steps_for_rr_rrr(stack_a);
}
