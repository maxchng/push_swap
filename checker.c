/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:15:34 by ychng             #+#    #+#             */
/*   Updated: 2023/09/20 00:16:29 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_not_valid(char *input)
{
	if (ft_strncmp(input, "sa\n", ft_strlen(input)) == 0
		|| ft_strncmp(input, "sb\n", ft_strlen(input)) == 0
		|| ft_strncmp(input, "ss\n", ft_strlen(input)) == 0
		|| ft_strncmp(input, "pa\n", ft_strlen(input)) == 0
		|| ft_strncmp(input, "pb\n", ft_strlen(input)) == 0
		|| ft_strncmp(input, "ra\n", ft_strlen(input)) == 0
		|| ft_strncmp(input, "rb\n", ft_strlen(input)) == 0
		|| ft_strncmp(input, "rr\n", ft_strlen(input)) == 0
		|| ft_strncmp(input, "rra\n", ft_strlen(input)) == 0
		|| ft_strncmp(input, "rrb\n", ft_strlen(input)) == 0
		|| ft_strncmp(input, "rrr\n", ft_strlen(input)) == 0)
		return (0);
	return (1);
}

static void	run_input(t_stacks stacks, char *input)
{
	if (ft_strncmp(input, "sa\n", ft_strlen(input)) == 0)
		sa(stacks.stack_a);
	else if (ft_strncmp(input, "sb\n", ft_strlen(input)) == 0)
		sb(stacks.stack_b);
	else if (ft_strncmp(input, "ss\n", ft_strlen(input)) == 0)
		ss(stacks.stack_a, stacks.stack_b);
	else if (ft_strncmp(input, "pa\n", ft_strlen(input)) == 0)
		pa(stacks.stack_a, stacks.stack_b);
	else if (ft_strncmp(input, "pb\n", ft_strlen(input)) == 0)
		pb(stacks.stack_a, stacks.stack_b);
	else if (ft_strncmp(input, "ra\n", ft_strlen(input)) == 0)
		ra(stacks.stack_a);
	else if (ft_strncmp(input, "rb\n", ft_strlen(input)) == 0)
		rb(stacks.stack_b);
	else if (ft_strncmp(input, "rr\n", ft_strlen(input)) == 0)
		rr(stacks.stack_a, stacks.stack_b);
	else if (ft_strncmp(input, "rra\n", ft_strlen(input)) == 0)
		rra(stacks.stack_a);
	else if (ft_strncmp(input, "rrb\n", ft_strlen(input)) == 0)
		rrb(stacks.stack_b);
	else if (ft_strncmp(input, "rrr\n", ft_strlen(input)) == 0)
		rrr(stacks.stack_a, stacks.stack_b);
}

static void	check_input(t_linked_list *stack_a, t_linked_list *stack_b)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (is_not_valid(input))
			break ;
		run_input((t_stacks){stack_a, stack_b}, input);
		free(input);
		input = get_next_line(0);
	}
	free(input);
	if (is_not_sorted(stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
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
		check_input(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
}
