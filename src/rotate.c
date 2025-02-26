/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:38:53 by syukna            #+#    #+#             */
/*   Updated: 2025/02/25 18:40:02 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_program_data *data)
{
	t_stack	*stack_a;

	stack_a = data->stack_a;
	if (stack_a->first == NULL)
		return ;
	stack_a = data->stack_a;
	stack_a->last = stack_a->first;
	stack_a->first = stack_a->first->next;
	funct_add_back(data, "ra");
}

void	rb(t_program_data *data)
{
	t_stack	*stack_b;

	stack_b = data->stack_b;
	if (stack_b->first == NULL)
		return ;
	stack_b = data->stack_b;
	stack_b->last = stack_b->first;
	stack_b->first = stack_b->first->next;
	funct_add_back(data, "rb");
}

void	rra(t_program_data *data)
{
	t_stack	*stack_a;

	stack_a = data->stack_a;
	if (stack_a->first == NULL)
		return ;
	stack_a = data->stack_a;
	stack_a->first = stack_a->first->prev;
	stack_a->last = stack_a->first->prev;
	funct_add_back(data, "rra");
}

void	rrb(t_program_data *data)
{
	t_stack	*stack_b;

	stack_b = data->stack_b;
	if (stack_b->first == NULL)
		return ;
	stack_b = data->stack_b;
	stack_b->first = stack_b->first->prev;
	stack_b->last = stack_b->first->prev;
	funct_add_back(data, "rrb");
}