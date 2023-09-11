/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:41:57 by ychng             #+#    #+#             */
/*   Updated: 2023/09/11 21:42:33 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_linked_list *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

void	exit_error(t_linked_list *stack, char *msg)
{
	free_stack(stack);
	write(2, msg, ft_strlen(msg));
	exit(1);
}
