/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:56:52 by ychng             #+#    #+#             */
/*   Updated: 2023/09/19 23:57:07 by ychng            ###   ########.fr       */
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
