/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:56:37 by syukna            #+#    #+#             */
/*   Updated: 2025/02/25 13:48:36 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_duplicate(t_stack *stack)
{
	t_node *current_node;
	t_node *next_node;
	int i;
	
	i = 0;
	current_node = stack->first;
	next_node = current_node->next;
	while (i < stack->size)
	{
		while (next_node != stack->first)
		{
			if (current_node->value == next_node->value)
				return (1);
			next_node = next_node->next;
		}
		current_node = current_node->next;
		next_node = current_node->next;
		i++;
	}
	return (0);
}

int	dll_sorted(t_stack *stack)
{
	t_node	*node;
	int i;

	if (!stack || stack->size < 2)
		return (1);
	node = stack->first;
	i = 0;
	while (i < stack->size - 1)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

void	check_sequence_error(t_stack *stack)
{
	if (is_duplicate(stack))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}