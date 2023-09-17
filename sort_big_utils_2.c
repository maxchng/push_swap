/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:46:46 by ychng             #+#    #+#             */
/*   Updated: 2023/09/17 17:09:54 by ychng            ###   ########.fr       */
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
		ra(stacks.stack_a);
	while (current_a->steps.rb--)
		rb(stacks.stack_b);
	while (current_a->steps.rr--)
		rr(stacks.stack_a, stacks.stack_b);
	while (current_a->steps.rra--)
		rra(stacks.stack_a);
	while (current_a->steps.rrb--)
		rrb(stacks.stack_b);
	while (current_a->steps.rrr--)
		rrr(stacks.stack_a, stacks.stack_b);
}
