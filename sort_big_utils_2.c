/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:46:46 by ychng             #+#    #+#             */
/*   Updated: 2023/09/20 00:24:28 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sum_steps(t_node *current_a)
{
	int	total_steps;

	total_steps = 0;
	total_steps += current_a->steps.ra;
	total_steps += current_a->steps.rb;
	total_steps += current_a->steps.rr;
	total_steps += current_a->steps.rra;
	total_steps += current_a->steps.rrb;
	total_steps += current_a->steps.rrr;
	return (total_steps);
}

void	run_steps(t_node *current_a, t_stacks stacks)
{
	while (current_a->steps.ra--)
		ra(stacks.stack_a, 1);
	while (current_a->steps.rb--)
		rb(stacks.stack_b, 1);
	while (current_a->steps.rr--)
		rr(stacks.stack_a, stacks.stack_b, 1);
	while (current_a->steps.rra--)
		rra(stacks.stack_a, 1);
	while (current_a->steps.rrb--)
		rrb(stacks.stack_b, 1);
	while (current_a->steps.rrr--)
		rrr(stacks.stack_a, stacks.stack_b, 1);
}

int	find_min_steps_index(t_linked_list *stack_a)
{
	int		total_steps;
	int		next_total_steps;
	t_node	*current_a;
	t_node	*best_node;

	current_a = stack_a->head;
	best_node = current_a;
	total_steps = sum_steps(current_a);
	while (current_a->next)
	{
		next_total_steps = sum_steps(current_a->next);
		if (total_steps > next_total_steps)
		{
			total_steps = next_total_steps;
			best_node = current_a->next;
		}
		current_a = current_a->next;
	}
	return (best_node->index);
}

void	sort_descending(t_linked_list *stack)
{
	int		size;
	int		max_num;
	int		max_index;
	t_node	*current;

	size = count_stack_size(stack);
	max_num = find_max_num(stack);
	max_index = find_max_index(stack);
	current = stack->head;
	while (current->data != max_num)
	{
		if (max_index > (size / 2))
			rrb(stack, 1);
		else
			rb(stack, 1);
		current = stack->head;
	}
}
