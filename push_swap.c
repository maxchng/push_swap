/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:48:10 by ychng             #+#    #+#             */
/*   Updated: 2023/09/11 21:38:50 by ychng            ###   ########.fr       */
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
		parse_argv(&stack_a, argc, argv);
		show_list(&stack_a);
	}
}
