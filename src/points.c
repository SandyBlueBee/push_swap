/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:32:34 by syukna            #+#    #+#             */
/*   Updated: 2025/02/26 19:36:29 by syukna           ###   ########.fr       */
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
		node->dpts = count;
		node = node->prev;
		count++;
	}
}

int	define_max_ratio(int size)
{
	int	max;

	if (size > 100)
		max = size / 5;
	else if (size >= 4 && size <= 10)
		max = size - 3;
	else	
		max = size / 4;
	return (max);
}

/**
 * @brief Optimize ratio based on size len
 * @param size Which will be divided
 * @return optimized ratio
 */
int	define_max(t_stack *stack)
{
	int	max;
	int	min;
	int	i;
	t_node	*node;

	min = -1;
	max = define_max_ratio(stack->size);
	// printf("So max is %d\n", max);
	while (max)
	{
		node = stack->first;
		i = 100;
		while (node != stack->first || i == 100)
		{
			
			// printf("node->rank = %d i = %d min = %d\n", node->rank, i, min);
			if (node->rank < i && node->rank > min)
			{
				i = node->rank;
				// printf("i is being changed i = %d\n", i);
			}
			node = node->next;
		}
		min = i;
		max--;
	}
	// printf("So min is %d\n", min);
	return (min);
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
	max = define_max(stack);
	calculate_score(stack, max);
}
