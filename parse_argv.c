/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:37:52 by ychng             #+#    #+#             */
/*   Updated: 2023/09/12 18:40:59 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_not_empty(t_linked_list *stack_a, char *str)
{
	int	i;
	int	is_empty;

	i = 0;
	is_empty = 1;
	if (str[i] == '\0')
		exit_error(stack_a, "Error\n");
	while (str[i])
	{
		if (str[i] != ' ')
		{
			is_empty = 0;
			break ;
		}
		i++;
	}
	if (is_empty == 1)
		exit_error(stack_a, "Error\n");
	return (1);
}

static int	is_not_numeric(char *token)
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

static void	validate_and_insert(t_linked_list *stack_a, char *token)
{
	long	num;
	t_node	*newnode;

	if (is_not_numeric(token))
		exit_error(stack_a, "Error\n");
	num = ps_atoi(token);
	if (num < INT_MIN || num > INT_MAX)
		exit_error(stack_a, "Error\n");
	if (is_duplicate(stack_a, num))
		exit_error(stack_a, "Error\n");
	newnode = create_node(num);
	if (!newnode)
		exit_error(stack_a, "Error\n");
	link_list(stack_a, newnode, 0);
}

void	parse_argv(t_linked_list *stack_a, int argc, char **argv)
{
	int		i;
	char	*token;
	t_node	*newnode;

	i = 1;
	while (i < argc)
	{
		is_not_empty(stack_a, argv[i]);
		token = ft_strtok(argv[i], " ");
		while (token)
		{
			validate_and_insert(stack_a, token);
			token = ft_strtok(NULL, " ");
		}
		i++;
	}
}
