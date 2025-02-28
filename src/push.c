/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:38:24 by syukna            #+#    #+#             */
/*   Updated: 2025/02/28 13:16:06 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_program_data *data)
{
	int	value;
	int rank;
	t_node	*node;

	if (!data->stack_b || !data->stack_b->first) 
		return ;
	value = data->stack_b->first->value;
	rank = data->stack_b->first->rank;
	node = node_init(value);
	node->rank = rank;
	dll_add_front(data->stack_a, node);
	dll_remove_node(data->stack_b);
	funct_add_back(data, "pa");
}

void	pb(t_program_data *data)
{
	int	value;
	int rank;
	t_node	*node;

	if (!data->stack_a || !data->stack_a->first) 
		return ;
	value = data->stack_a->first->value;
	rank = data->stack_a->first->rank;
	node = node_init(value);
	node->rank = rank;
	dll_add_front(data->stack_b, node);
	dll_remove_node(data->stack_a);
	funct_add_back(data, "pb");
}