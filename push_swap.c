/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:48:10 by ychng             #+#    #+#             */
/*   Updated: 2023/09/14 15:29:01 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicate_stack(t_linked_list *src, t_linked_list *dest)
{
	t_node	*current;
	t_node	*newnode;

	current = src->head;
	while (current)
	{
		newnode = create_node(current->data);
		if (!newnode)
			exit_error(src, "Error\n");
		link_list(dest, newnode, 0);
		current = current->next;
	}
}

void	move_to_top(t_linked_list *temp_a)
{
	int		size;
	t_node	*current;

	size = count_size(temp_a);
	current = temp_a->head;
	while (current)
	{
		if (current->index > (size / 2))
			current->steps.rra += (size - current->index);
		else
			current->steps.ra += current->index;
		current = current->next;
	}
}

int	find_min(t_linked_list *temp_b)
{
	int		min;
	t_node	*current;

	min = temp_b->head->data;
	current = temp_b->head;
	while (current)
	{
		if (min > current->data)
			min = current->data;
		current = current->next;
	}
	return (min);
}

int	find_max(t_linked_list *temp_b)
{
	int		max;
	t_node	*current;

	max = temp_b->head->data;
	current = temp_b->head;
	while (current)
	{
		if (max < current->data)
			max = current->data;
		current = current->next;
	}
	return (max);
}

static void	move_max_to_top(t_node *current_a, t_linked_list *temp_b)
{
	int		size;
	int		max_b;
	t_node	*current_b;

	size = (count_size(temp_b) / 2);
	max_b = find_max(temp_b);
	current_b = temp_b->head;
	while (current_b)
	{
		if (current_b->data != max_b)
			continue ;
		if (current_b->index > (size / 2))
			current_a->steps.rrb += (size - current_b->index);
		else
			current_a->steps.rb += (current_b->index);
		current_b = current_b->next;
	}
}

void	move_min_or_max(t_linked_list *temp_a, t_linked_list *temp_b)
{
	int		min_b;
	t_node	*current;

	min_b = find_min(temp_b);
	current = temp_a->head;
	while (current)
	{
		if (current->data < min_b)
			move_max_to_top(current, temp_b);
		current = current->next;
	}
}

void	find_smaller_top_bigger_bottom(t_node *current_a, t_linked_list *temp_b)
{
	int		data;
	int		size;
	t_node	*current_b;

	data = current_a->data;
	size = count_size(temp_b);
	current_b = temp_b->head;
	while (current_b->next)
	{
		if (!(data > current_b->data && data < current_b->next->data))
			continue ;
		if (current_b->next->index > (size / 2))
			current_a->steps.rrb += (size - current_b->next->index);
		else
			current_a->steps.rb += (current_b->next->index);
		current_b = current_b->next;
	}
}

void	move_in_between(t_linked_list *temp_a, t_linked_list *temp_b)
{
	t_node	*current;

	current = temp_a->head;
	while (current)
	{
		find_smaller_top_bigger_bottom(current, temp_b);
		current = current->next;
	}
}

void	count_steps(t_linked_list *stack_a)
{
	t_linked_list	temp_a;
	t_linked_list	temp_b;

	temp_a = (t_linked_list){0};
	temp_b = (t_linked_list){0};
	duplicate_stack(stack_a, &temp_a);
	duplicate_stack(stack_a, &temp_b);
	pb(&temp_a, &temp_b, NULL);
	pb(&temp_a, &temp_b, NULL);
	move_to_top(&temp_a);
	move_min_or_max(&temp_a, &temp_b);
	move_in_between(&temp_b, &temp_b);
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
		count_steps(&stack_a);
		show_list(&stack_a);
	}
}
