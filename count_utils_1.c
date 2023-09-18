/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:11:14 by ychng             #+#    #+#             */
/*   Updated: 2023/09/18 19:51:24 by ychng            ###   ########.fr       */
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
