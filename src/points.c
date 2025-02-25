/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:32:34 by syukna            #+#    #+#             */
/*   Updated: 2025/02/25 17:32:36 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	add_points(t_stack *stack)
{
	if (stack->first == NULL)
		return ;
	t_node	*node;
	int	count;

	count = 1;
	node = stack->first;
	while (node != stack->first || count == 1)
	{
		node->upts = count++;
		node = node->next;
	}
	count = 2;
	node = stack->last;
	while (node != stack->last || count == 2)
	{
		node->dpts = count++;
		node = node->prev;
	}
}
/**
 * @brief Optimize ratio based on size len
 * @param size Which will be divided
 * @return optimized ratio
 */
int	define_max(int	size)
{
	if (size > 100)
		return (size/4);
	else
		return (size/3);
}

void	calculate_score(t_stack *stack, int max)
{
	if (stack->first == NULL)
		return ;
	t_node	*node;
	int	go;
	
	go = 1;
	node = stack->first;
	while (node != stack->first || go == 1)
	{
		if (node->rank > max)
			node->score = 100;
		else if (node->upts <= node->dpts)
		{
			node->score = node->upts;
			node->dpts = 100;
		}
		else if (node->dpts <= node->upts)
		{
			node->score = node->dpts;
			node->upts = 100;
		}
		node = node->next;
		go = 0;
	}
}

void	add_score(t_stack *stack)
{
	int	max;
	
	add_points(stack);
	max = define_max(stack->size);
	calculate_score(stack, max);
}
