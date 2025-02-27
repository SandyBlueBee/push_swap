/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:41:37 by syukna            #+#    #+#             */
/*   Updated: 2025/02/27 16:58:21 by syukna           ###   ########.fr       */
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
void	send_node_back_up_unique(t_program_data *data, t_node *chosen)
{
	while(chosen->upts > 1)
	{
		rb(data);
		add_score(data->stack_b);
	}
	pa(data);
}

void	send_node_back_up(t_program_data *data, t_node *chosen)
{
	int	go;
	t_node	*node;
	t_node	*second;

	go = 1;
	node = data->stack_b->first;
	second = node;
	while (node != data->stack_b->first || go == 1)
	{
		if (node->rank == chosen->rank - 1)
			second = node;ga 
		// printf("back currentnode = %d %d %d\n", node->rank, node->upts,node->dpts);
		node = node->next;
		go = 0;
	}
	if (second->upts < chosen->upts)
	{
			// printf("\n\nback CHOSEN = %d %d %d\n", chosen->rank, chosen->upts,chosen->dpts);
			// printf("back SECOND = %d %d %d\n\n", second->rank, second->upts,second->dpts);
		send_node_back_up_unique(data, second);
		send_node_back_up_unique(data, chosen);
		sa(data);
	}
	else
		send_node_back_up_unique(data, chosen);
}

void	send_node_back(t_program_data *data, t_node *chosen)
{
	add_score(data->stack_b);
	if (chosen->upts <= chosen->dpts)
		send_node_back_up(data, chosen);
	else
	{
		while(chosen->dpts > 2)
		{
			rrb(data);
			add_score(data->stack_b);
		}
		rrb(data);
		pa(data);	
	}
}

void	send_back(t_program_data *data)
{
	int	max;
	int	i;
	t_node	*node;
	t_node	*chosen;

	max = find_max_back(data->stack_b);
	// printf("MAX IS = %d\n", max);
	i = 0;
	while (data->stack_b->size)
	{
		i = 0;
		node = data->stack_b->first;
		while (i < data->stack_b->size)
		{
			if (node->rank == max)
			{
				chosen = node;
				send_node_back(data, chosen);
			}
			node = node->next;
			i++;
		}
		max--;
	}
}