/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:41:37 by syukna            #+#    #+#             */
/*   Updated: 2025/02/26 21:00:30 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_max_back(t_stack *stack_b)
{
	if (!stack_b || !stack_b->first)
		return 0;
	
	int	max;
	t_node *node;

	max = 0;
	node = stack_b->first;
	while (node != stack_b->first || max == 0)
	{
		if (node->rank > max)
			max = node->rank;
		node = node->next;
	}
	return (max);
}

void	send_back(t_program_data *data)
{
	int	max;

	max = find_max_back(data->stack_b);
	printf("MAX IS = %d\n", max);
}