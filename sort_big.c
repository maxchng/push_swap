/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:46:10 by ychng             #+#    #+#             */
/*   Updated: 2023/09/18 17:46:53 by ychng            ###   ########.fr       */
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

void	steps_to_handle_max(t_stacks stacks)
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

void	steps_to_handle_min(t_stacks stacks)
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

void	steps_big_top_small_bottom(t_node *current_a, t_linked_list *stack_b)
{
	int		a_data;
	int		b_data;
	int		next_b_data;
	t_node	*current_b;

	a_data = current_a->data;
	b_data = stack_b->head->data;
	if (a_data < b_data && a_data > stack_b->tail->data)
		return ;
	current_b = stack_b->head;
	while (current_b->next)
	{
		next_b_data = current_b->next->data;
		if (a_data > b_data && a_data < next_b_data)
			set_steps(current_a, current_b, stack_b);
		current_b = current_b->next;
		b_data = current_b->data;
	}
}

void	count_optimize_steps(t_linked_list *stack_a, t_linked_list *stack_b)
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
	current_a = stack_a->head;
	while (current_a)
	{
		steps_big_top_small_bottom(current_a, stack_b);
		current_a = current_a->next;
	}
	steps_for_rr_rrr(stack_a);
}

void	optimize_sort_big(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int		size_a;
	t_node	*current_a;

	size_a = count_stack_size(stack_a);
	while (size_a--)
	{
		count_optimize_steps(stack_a, stack_b);
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
	int		size_a;
	int		half_of_size_a;
	t_node	*current_a;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	size_a = count_stack_size(stack_a);
	half_of_size_a = size_a / 2;
	while (size_a-- > half_of_size_a)
	{
		count_sorting_steps(stack_a, stack_b);
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
	optimize_sort_big(stack_a, stack_b);
}
