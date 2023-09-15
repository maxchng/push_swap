/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:48:10 by ychng             #+#    #+#             */
/*   Updated: 2023/09/15 15:46:42 by ychng            ###   ########.fr       */
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

int	count_size(t_linked_list *stack)
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

void	move_to_top(t_linked_list *stack_a)
{
	int		size;
	t_node	*current;

	size = count_size(stack_a);
	current = stack_a->head;
	while (current)
	{
		if (current->index > (size / 2))
			current->steps.rra += (size - current->index);
		else
			current->steps.ra += current->index;
		current = current->next;
	}
}

int	find_min(t_linked_list *stack_b)
{
	int		min;
	t_node	*current;

	min = stack_b->head->data;
	current = stack_b->head;
	while (current)
	{
		if (min > current->data)
			min = current->data;
		current = current->next;
	}
	return (min);
}

int	find_max(t_linked_list *stack_b)
{
	int		max;
	t_node	*current;

	max = stack_b->head->data;
	current = stack_b->head;
	while (current)
	{
		if (max < current->data)
			max = current->data;
		current = current->next;
	}
	return (max);
}

static void	move_max_to_top(t_node *current_a, t_linked_list *stack_b)
{
	int		size;
	int		max_b;
	t_node	*current_b;

	size = count_size(stack_b);
	max_b = find_max(stack_b);
	current_b = stack_b->head;
	while (current_b)
	{
		if (current_b->data == max_b)
		{
			if (current_b->index > (size / 2))
				current_a->steps.rrb += (size - current_b->index);
			else
				current_a->steps.rb += (current_b->index);
		}
		current_b = current_b->next;
	}
}

void	move_min_or_max(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int		min_b;
	int		max_b;
	t_node	*current;

	add_index(stack_b);
	min_b = find_min(stack_b);
	max_b = find_max(stack_b);
	current = stack_a->head;
	while (current)
	{
		if (current->data < min_b || current->data > max_b)
			move_max_to_top(current, stack_b);
		current = current->next;
	}
}

void	set_steps(t_node *current_a, t_node *current_b, t_linked_list *stack_b)
{
	int	size;

	size = count_size(stack_b);
	if (current_b->next->index > (size / 2))
		current_a->steps.rrb = (size - current_b->next->index);
	else
		current_a->steps.rb = current_b->next->index;
}

void	find_small_top_big_bottom(t_node *current_a, t_linked_list *stack_b)
{
	int		size;
	t_node	*tail_b;
	t_node	*current_b;

	size = count_size(stack_b);
	tail_b = stack_b->tail;
	current_b = stack_b->head;
	if (current_a->data > current_b->data && current_a->data < tail_b->data)
		return ;
	while (current_b->index < (size - 1))
	{
		if (current_a->data > current_b->next->data
			&& current_a->data < current_b->data)
			set_steps(current_a, current_b, stack_b);
		current_b = current_b->next;
	}
}

void	move_in_between(t_linked_list *stack_a, t_linked_list *stack_b)
{
	t_node	*current;

	add_index(stack_b);
	current = stack_a->head;
	while (current)
	{
		find_small_top_big_bottom(current, stack_b);
		current = current->next;
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
		printf("pa: %d  ", current->steps.pa);
		printf("pb: %d  ", current->steps.pb);
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

void	calc_rr_and_rrr(t_linked_list *stack_a)
{
	t_node	*current;

	current = stack_a->head;
	while (current)
	{
		if (current->steps.ra && current->steps.rb)
		{
			current->steps.ra--;
			current->steps.rb--;
			current->steps.rr++;
		}
		if (current->steps.rra && current->steps.rrb)
		{
			current->steps.rra--;
			current->steps.rrb--;
			current->steps.rrr++;
		}
		current = current->next;
	}
}

void	count_steps(t_linked_list *stack_a, t_linked_list *stack_b)
{
	stack_a->head->steps = (t_steps){0};
	add_index(stack_a);
	move_to_top(stack_a);
	move_min_or_max(stack_a, stack_b);
	move_in_between(stack_a, stack_b);
	calc_rr_and_rrr(stack_a);
}

int	sum_steps(t_node *current)
{
	int	total_steps;

	total_steps = 0;
	total_steps += current->steps.sa;
	total_steps += current->steps.sb;
	total_steps += current->steps.ss;
	total_steps += current->steps.pa;
	total_steps += current->steps.pb;
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
	while (current->steps.sa--)
		sa(stack_a);
	while (current->steps.sb--)
		sb(stack_b);
	while (current->steps.ss--)
		ss(stack_a, stack_b);
	while (current->steps.pa--)
		pa(stack_a, stack_b);
	while (current->steps.pb--)
		pb(stack_a, stack_b);
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

void	sort_big(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int		size;
	t_node	*current;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	size = count_size(stack_a);
	while (size--)
	{
		count_steps(stack_a, stack_b);
		current = stack_a->head;
		while (current)
		{
			if (current->index == find_min_steps_index(stack_a))
			{
				run_steps(current, stack_a, stack_b);
				pb(stack_a, stack_b);
				break ;
			}
			current = current->next;
		}
	}
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
		show_steps(&stack_a);
		show_list(&stack_a);
		printf("\nThis is b\n");
		show_list(&stack_a);
	}
}
