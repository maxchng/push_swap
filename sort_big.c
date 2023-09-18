/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:46:10 by ychng             #+#    #+#             */
/*   Updated: 2023/09/18 19:51:44 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_steps_index(t_linked_list *stack_a)
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

static void	sort_descending(t_linked_list *stack)
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
			rrb(stack);
		else
			rb(stack);
		current = stack->head;
	}
}

void	sort_descending_steps(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int		size_a;
	int		half_of_size_a;
	t_node	*current_a;

	size_a = count_stack_size(stack_a);
	half_of_size_a = size_a / 2;
	while (size_a-- > half_of_size_a)
	{
		count_descending_steps(stack_a, stack_b);
		current_a = stack_a->head;
		while (current_a)
		{
			if (current_a->index == find_min_steps_index(stack_a))
			{
				run_steps(current_a, (t_stacks){stack_a, stack_b});
				pb(stack_a, stack_b);
				break ;
			}
			current_a = current_a->next;
		}
	}
	sort_descending(stack_b);
}

void	sort_ascending_steps(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int		size_a;
	t_node	*current_a;

	size_a = count_stack_size(stack_a);
	while (size_a--)
	{
		count_ascending_steps(stack_a, stack_b);
		current_a = stack_a->head;
		while (current_a)
		{
			if (current_a->index == find_min_steps_index(stack_a))
			{
				run_steps(current_a, (t_stacks){stack_a, stack_b});
				pb(stack_a, stack_b);
				break ;
			}
			current_a = current_a->next;
		}
	}
	sort_descending(stack_b);
}

void	sort_big(t_linked_list *stack_a, t_linked_list *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_descending_steps(stack_a, stack_b);
	sort_ascending_steps(stack_a, stack_b);
}
