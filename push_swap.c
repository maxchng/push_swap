/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:48:10 by ychng             #+#    #+#             */
/*   Updated: 2023/09/17 13:44:53 by ychng            ###   ########.fr       */
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

void	steps_to_handle_min_max(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int		min_b;
	int		max_b;
	t_node	*current_a;

	add_index(stack_b);
	min_b = find_min_num(stack_b);
	max_b = find_max_num(stack_b);
	current_a = stack_a->head;
	while (current_a)
	{
		if (current_a->data < min_b || current_a->data > max_b)
			steps_max_to_top_of_b(current_a, stack_b);
		current_a = current_a->next;
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

void	steps_for_other_numbers(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int		min_b;
	int		max_b;
	t_node	*current_a;

	add_index(stack_b);
	min_b = find_min_num(stack_b);
	max_b = find_max_num(stack_b);
	current_a = stack_a->head;
	while (current_a)
	{
		if (!(current_a->data < min_b || current_a->data > max_b))
			steps_small_top_big_bottom(current_a, stack_b);
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
	steps_to_handle_min_max(stack_a, stack_b);
	steps_for_other_numbers(stack_a, stack_b);
	steps_for_rr_rrr(stack_a);
}

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

void	run_steps(t_node *current_a, t_stacks *stacks)
{
	while (current_a->steps.ra--)
		ra(stacks->stack_a);
	while (current_a->steps.rb--)
		rb(stacks->stack_a);
	while (current_a->steps.rr--)
		rr(stacks->stack_a, stacks->stack_a);
	while (current_a->steps.rra--)
		rra(stacks->stack_a);
	while (current_a->steps.rrb--)
		rrb(stacks->stack_a);
	while (current_a->steps.rrr--)
		rrr(stacks->stack_a, stacks->stack_a);
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
			rrb(stack);
		else
			rb(stack);
		current = stack->head;
	}
}

void	empty_stack_b(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int	size_b;

	size_b = count_stack_size(stack_b);
	while (size_b--)
		pa(stack_a, stack_b);
}

void	sort_big(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int		size_a;
	t_node	*current_a;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	size_a = count_stack_size(stack_a);
	while (size_a--)
	{
		count_sorting_steps(stack_a, stack_b);
		current_a = stack_a->head;
		while (current_a)
		{
			if (current_a->index == find_min_steps_index(stack_a))
			{
				run_steps(current_a, &(t_stacks){stack_a, stack_b});
				pb(stack_a, stack_b);
				break ;
			}
			current_a = current_a->next;
		}
	}
	sort_descending(stack_b);
	empty_stack_b(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_linked_list	stack_a;
	t_linked_list	stack_b;

	stack_a = (t_linked_list){0};
	stack_b = (t_linked_list){0};
	if (argc >= 2)
	{
		parse_argv(&stack_a, argc, argv);
		sort_big(&stack_a, &stack_b);
	}
}
