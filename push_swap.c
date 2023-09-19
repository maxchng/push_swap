/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:48:10 by ychng             #+#    #+#             */
/*   Updated: 2023/09/19 23:57:04 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_sort(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int	size_a;

	size_a = count_stack_size(stack_a);
	if (size_a == 2)
		sort_two(stack_a);
	else if (size_a == 3)
		sort_three(stack_a, stack_b);
	else if (size_a == 3)
		sort_four(stack_a, stack_b);
	else if (size_a == 5)
		sort_five(stack_a, stack_b);
	else if (size_a > 5)
		sort_big(stack_a, stack_b);
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
		if (is_not_sorted(&stack_a))
			handle_sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
}
