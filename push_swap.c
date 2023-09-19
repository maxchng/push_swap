/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:48:10 by ychng             #+#    #+#             */
/*   Updated: 2023/09/19 21:20:59 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_not_sorted(t_linked_list *stack_a)
{
	t_node	*current_a;

	current_a = stack_a->head;
	while (current_a->next)
	{
		if (current_a->data > current_a->next->data)
			return (1);
		current_a = current_a->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int				size_a;
	t_linked_list	stack_a;
	t_linked_list	stack_b;

	stack_a = (t_linked_list){0};
	stack_b = (t_linked_list){0};
	if (argc >= 2)
	{
		parse_argv(&stack_a, argc, argv);
		
		if (is_not_sorted(&stack_a))
		{
			size_a = count_stack_size(&stack_a);
			if (size_a == 2)
				sort_two(&stack_a);
			else if (size_a == 3)
				sort_three(&stack_a, &stack_b);
			else if (size_a == 5)
				sort_five(&stack_a, &stack_b);
			else if (size_a > 10)
				sort_big(&stack_a, &stack_b);
		}
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
}
