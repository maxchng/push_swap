/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 02:46:48 by ychng             #+#    #+#             */
/*   Updated: 2023/09/19 02:48:06 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_rank(t_linked_list *stack)
{
	int		rank;
	t_node	*current;
	t_node	*compare;

	current = stack->head;
	while (current)
	{
		rank = 1;
		compare = stack->head;
		while (compare)
		{
			if (current->data > compare->data)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

void	set_ra_rra(t_node *current_a, t_linked_list *stack_a)
{
	int	size_a;

	add_index(stack_a);
	size_a = count_stack_size(stack_a);
	if (current_a->index > (size_a / 2))
		current_a->steps.rra += (size_a - current_a->index);
	else
		current_a->steps.ra += current_a->index;
}
