/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:39:22 by syukna            #+#    #+#             */
/*   Updated: 2025/02/26 20:39:57 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	send_node_forward_up(t_program_data *data, t_node *chosen)
{
	while (chosen->upts > 1)
	{
		// printf("Where is loop??\n");
		if (chosen->upts == 2)
		{
			if (data->stack_a->first->rank < data->stack_a->first->next->rank)
			{
				if (data->stack_b->first->rank > data->stack_b->first->next->rank)
					sb(data);
				sa(data);
			}
			else
				ra(data);
		}
		else
			ra(data);
		add_score(data->stack_a);
	}
}


void	send_node_forward_down(t_program_data *data, t_node *chosen);

void	send_node_forward(t_program_data *data, t_node *chosen)
{
	if (chosen->upts <= chosen->dpts)
		send_node_forward_up(data, chosen);
	else
	{
		while (chosen->dpts > 2)
		{
			rra(data);
			add_score(data->stack_a);
		}
		rra(data);
	}
	pb(data);
}

void	send_forward(t_program_data *data)
{
	int	min_score;
	t_node	*node;
	t_node	*chosen;

	while (data->stack_a->size > 3)
	{
		min_score = 100;
		add_score(data->stack_a);
		// view_data(data);
		node = data->stack_a->first;
		chosen = node;
		while (node != data->stack_a->first || min_score == 100)
		{
			if (node->score < min_score)
			{
				min_score = node->score;
				chosen = node;
				// printf("LOOP TIME  \n");
			}
			node = node->next;
		}
		// printf("CHOSEN = %d %d %d %d %d\n", chosen->value, chosen->rank, chosen->upts, chosen->dpts, chosen->score);
		send_node_forward(data, chosen);
	}
	sort_three_a(data);
}