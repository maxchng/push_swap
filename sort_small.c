/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 02:46:45 by ychng             #+#    #+#             */
/*   Updated: 2023/09/19 02:47:31 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int	fir_rank;
	int	lst_rank;

	add_rank(stack_a);
	fir_rank = stack_a->head->rank;
	lst_rank = stack_a->tail->rank;
	if (fir_rank == 1 && lst_rank == 2)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (fir_rank == 2 && lst_rank == 3)
		sa(stack_a);
	else if (fir_rank == 2 && lst_rank == 1)
		rra(stack_a);
	else if (fir_rank == 3 && lst_rank == 2)
		ra(stack_a);
	else if (fir_rank == 3 && lst_rank == 1)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_five(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int		size_a;
	t_node	*current_a;

	size_a = count_stack_size(stack_a);
	while (size_a-- > 3)
	{
		add_rank(stack_a);
		current_a = stack_a->head;
		while (current_a)
		{
			if (current_a->rank == 1)
			{
				set_ra_rra(current_a, stack_a);
				break ;
			}
			current_a = current_a->next;
		}
		run_steps(current_a, (t_stacks){stack_a, stack_b});
		pb(stack_a, stack_b);
	}
	sort_three(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
