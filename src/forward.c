/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:39:22 by syukna            #+#    #+#             */
/*   Updated: 2025/03/01 14:42:47 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	send_node_forward_up(t_program_data *data, t_node *chosen)
{
	add_score(data->stack_a);
	while (chosen->upts > 1)
	{
		if (chosen->upts == 2)
		{
			// printf("first rank A %d second rank A %d = %d\n", data->stack_b->first->rank, data->stack_b->first->next->rank, data->stack_b->first->rank < data->stack_b->first->next->rank);
			if (data->stack_b->size >=2)
				if (data->stack_b->first->rank < data->stack_b->first->next->rank)
				{
					sb(data);
					// printf("Does this eveer happen?\n");
				}
			sa(data);
			return ;
		}
		else
			ra(data);
		add_score(data->stack_a);
		if (data->stack_b->size > 2 && data->stack_b->first->rank < data->stack_b->size / 2)
			rb(data);
	}
}

void	send_node_forward_down(t_program_data *data, t_node *chosen)
{
	add_score(data->stack_a);
	while (chosen->dpts > 2)
	{
		rra(data);
		add_score(data->stack_a);
	}
	rra(data);
}

void	send_node_forward(t_program_data *data, t_node *chosen)
{
	if (chosen->upts <= chosen->dpts)
		send_node_forward_up(data, chosen);
	else
		send_node_forward_down(data, chosen);
	pb(data);
}

void	send_forward(t_program_data *data)
{
	int	min_score;
	t_node	*node;
	t_node	*chosen;

	while (data->stack_a->size > 3)
	{
		min_score = data->stack_a->size;
		add_score(data->stack_a);
		node = data->stack_a->first;
		chosen = node;
		while (node != data->stack_a->first || min_score == data->stack_a->size)
		{
			if (node->score < min_score)
			{
				min_score = node->score;
				chosen = node;
			}
			node = node->next;
		}
		send_node_forward(data, chosen);
	}
	sort_three_a(data);
}