/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:48:10 by ychng             #+#    #+#             */
/*   Updated: 2023/09/11 18:32:53 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_linked_list	stack_a;
	t_linked_list	stack_b;
	t_steps			steps;

	stack_a = (t_linked_list){0};
	stack_b = (t_linked_list){0};
	steps = (t_steps){0};
	if (argc >= 2)
	{
		link_list(&stack_a, create_node(1), 0);
		link_list(&stack_a, create_node(2), 0);
		link_list(&stack_b, create_node(3), 0);
		link_list(&stack_b, create_node(4), 0);
		show_list(&stack_a);
	}
}
