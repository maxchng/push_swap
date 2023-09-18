/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ascending.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:13:08 by ychng             #+#    #+#             */
/*   Updated: 2023/09/18 19:51:37 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	steps_to_handle_min(t_stacks stacks)
{
	int		min_b;
	t_node	*current_a;

	add_index(stacks.stack_b);
	min_b = find_min_num(stacks.stack_b);
	current_a = stacks.stack_a->head;
	while (current_a)
	{
		if (current_a->data < min_b)
			steps_min_to_top_of_b(current_a, stacks.stack_b);
		current_a = current_a->next;
	}
}

static void	steps_to_handle_max(t_stacks stacks)
{
	int		max_b;
	t_node	*current_a;

	add_index(stacks.stack_b);
	max_b = find_max_num(stacks.stack_b);
	current_a = stacks.stack_a->head;
	while (current_a)
	{
		if (current_a->data > max_b)
			steps_max_to_top_of_b(current_a, stacks.stack_b);
		current_a = current_a->next;
	}
}

static void	steps_circular_ascending(t_stacks stacks)
{
	t_node	*current_a;

	add_index(stacks.stack_b);
	current_a = stacks.stack_a->head;
	while (current_a)
	{
		steps_big_top_small_bottom(current_a, stacks.stack_b);
		current_a = current_a->next;
	}
}

void	count_ascending_steps(t_linked_list *stack_a, t_linked_list *stack_b)
{
	t_node	*current_a;

	current_a = stack_a->head;
	while (current_a)
	{
		current_a->steps = (t_steps){0};
		current_a = current_a->next;
	}
	steps_to_top_of_a(stack_a);
	steps_to_handle_max((t_stacks){stack_a, stack_b});
	steps_to_handle_min((t_stacks){stack_a, stack_b});
	steps_circular_ascending((t_stacks){stack_a, stack_b});
	steps_for_rr_rrr(stack_a);
}
