/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:37:52 by ychng             #+#    #+#             */
/*   Updated: 2023/09/11 22:12:40 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	not_valid_num(char *token)
{
	int	i;

	i = 0;
	if (token[i] == '-' || token[i] == '+')
		i++;
	if (token[i] == '\0')
		return (1);
	while (token[i])
	{
		if (!(token[i] >= '0' && token[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static int	not_valid_int(long num)
{
	return (num < INT_MIN || num > INT_MAX);
}

static int	is_duplicate(t_linked_list *stack_a, int num)
{
	t_node	*current;

	current = stack_a->head;
	while (current)
	{
		if (current->data == num)
			return (1);
		current = current->next;
	}
	return (0);
}

void	parse_argv(t_linked_list *stack_a, int argc, char **argv)
{
	int		i;
	long	num;
	char	*token;
	t_node	*newnode;

	i = 1;
	while (i < argc)
	{
		token = ft_strtok(argv[i++], " ");
		while (token)
		{
			if (not_valid_num(token))
				exit_error(stack_a, "Error\n");
			num = ps_atoi(token);
			if (not_valid_int(num))
				exit_error(stack_a, "Error\n");
			if (is_duplicate(stack_a, num))
				exit_error(stack_a, "Error\n");
			newnode = create_node(num);
			if (!newnode)
				exit_error(stack_a, "Error\n");
			link_list(stack_a, newnode, 0);
			token = ft_strtok(NULL, " ");
		}
	}
}
