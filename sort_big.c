/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:46:10 by ychng             #+#    #+#             */
/*   Updated: 2023/09/20 00:24:14 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	descending_order(t_linked_list *stack_a, t_linked_list *stack_b)
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
				pb(stack_a, stack_b, 1);
				break ;
			}
			current_a = current_a->next;
		}
	}
	sort_descending(stack_b);
}

static void	ascending_order(t_linked_list *stack_a, t_linked_list *stack_b)
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
				pb(stack_a, stack_b, 1);
				break ;
			}
			current_a = current_a->next;
		}
	}
	sort_descending(stack_b);
}

static void	empty_stack_b(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int	size_b;

	size_b = count_stack_size(stack_b);
	while (size_b--)
	{
		if (stack_b->head->data < stack_b->tail->data)
			rrb(stack_b, 1);
		pa(stack_a, stack_b, 1);
	}
}

void	sort_big(t_linked_list *stack_a, t_linked_list *stack_b)
{
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	descending_order(stack_a, stack_b);
	ascending_order(stack_a, stack_b);
	empty_stack_b(stack_a, stack_b);
}
