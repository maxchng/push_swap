/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:48:10 by ychng             #+#    #+#             */
/*   Updated: 2023/09/16 20:12:05 by ychng            ###   ########.fr       */
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
	int		min;
	t_node	*current;

	min = stack->head->data;
	current = stack->head;
	while (current)
	{
		if (min > current->data)
			min = current->data;
		current = current->next;
	}
	return (min);
}

int	find_max_num(t_linked_list *stack)
{
	int		max;
	t_node	*current;

	max = stack->head->data;
	current = stack->head;
	while (current)
	{
		if (max < current->data)
			max = current->data;
		current = current->next;
	}
	return (max);
}

void	steps_max_to_top_of_b(t_node *current_a, t_linked_list *stack_b)
{
	int		max_b;
	int		size_b;
	t_node	*current_b;

	add_index(stack_b);
	max_b = find_max_num(stack_b);
	size_b = count_stack_size(stack_b);
	current_b = stack_b->head;
	while (current_b)
	{
		if (current_b->data == max_b)
		{
			if (current_b->index > (size_b / 2))
				current_b->steps.rra += (size_b - current_b->index);
			else
				current_b->steps.ra += current_b->index;
		}
		current_b = current_b->next;
	}
}

void	steps_to_handle_min_max(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int		min_b;
	int		max_b;
	t_node	*current_a;

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

	add_index(stack_b);
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
	t_node	*tail_b;
	t_node	*current_b;

	tail_b = stack_b->tail;
	current_b = stack_b->head;
	a_data = current_a->data;
	if (a_data > b_data && a_data < tail_b->data)
		return ;
	while (current_b->next)
	{
		b_data = current_b->data;
		next_b_data = current_b->next->data;
		if (a_data > next_b_data && a_data < b_data)
			set_steps(current_a, current_b, stack_b);
		current_b = current_b->next;
	}
}

void	steps_for_other_numbers(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int		min_b;
	int		max_b;
	t_node	*current_a;

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

void	show_steps(t_linked_list *stack_a)
{
	t_node	*current;

	current = stack_a->head;
	while (current)
	{
		printf("\n\nCurrent number: %d", current->data);
		printf("\n-------------------\n");
		printf("ra: %d  ", current->steps.ra);
		printf("rb: %d  ", current->steps.rb);
		printf("rr: %d  ", current->steps.rr);
		printf("rra: %d  ", current->steps.rra);
		printf("rrb: %d  ", current->steps.rrb);
		printf("rrr: %d  ", current->steps.rrr);
		printf("\n-------------------\n");
		current = current->next;
	}
}

void	calc_combined_steps_of_a(t_linked_list *stack_a)
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
	calc_combined_steps_of_a(stack_a);
}

int	sum_steps(t_node *current)
{
	int	total_steps;

	total_steps = 0;
	total_steps += current->steps.ra;
	total_steps += current->steps.rb;
	total_steps += current->steps.rr;
	total_steps += current->steps.rra;
	total_steps += current->steps.rrb;
	total_steps += current->steps.rrr;
	return (total_steps);
}

int	find_min_steps_index(t_linked_list *stack_a)
{
	int		current_steps;
	int		next_steps;
	t_node	*current;
	t_node	*best_node;

	current = stack_a->head;
	best_node = current;
	current_steps = sum_steps(current);
	while (current->next)
	{
		next_steps = sum_steps(current->next);
		if (current_steps > next_steps)
		{
			current_steps = next_steps;
			best_node = current->next;
		}
		current = current->next;
	}
	return (best_node->index);
}

void	run_steps(t_node *current, t_linked_list *stack_a,
					t_linked_list *stack_b)
{
	while (current->steps.ra--)
		ra(stack_a);
	while (current->steps.rb--)
		rb(stack_b);
	while (current->steps.rr--)
		rr(stack_a, stack_b);
	while (current->steps.rra--)
		rra(stack_a);
	while (current->steps.rrb--)
		rrb(stack_b);
	while (current->steps.rrr--)
		rrr(stack_a, stack_b);
}

int	find_max_index(t_linked_list *stack_b)
{
	int		max;
	t_node	*current;

	add_index(stack_b);
	max = find_max_num(stack_b);
	current = stack_b->head;
	while (current)
	{
		if (current->data == max)
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
				run_steps(current_a, stack_a, stack_b);
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
