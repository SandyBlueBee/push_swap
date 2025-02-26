/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:39:07 by syukna            #+#    #+#             */
/*   Updated: 2025/02/25 18:35:55 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_program_data *data)
{
	t_stack	*stack_a;

	stack_a = data->stack_a;
	if (stack_a->first == NULL)
		return ;
	int	rank;
	int	value;
	
	rank = stack_a->first->rank;
	value = stack_a->first->value;
	stack_a->first->rank = stack_a->first->next->rank;
	stack_a->first->value = stack_a->first->next->value;
	stack_a->first->next->rank = rank;
	stack_a->first->next->value = value;
	funct_add_back(data, "sa");
}

void	sb(t_program_data *data)
{
	t_stack	*stack_b;

	stack_b = data->stack_b;
	if (stack_b->first == NULL)
		return ;
	int	rank;
	int	value;

	rank = stack_b->first->rank;
	value = stack_b->first->value;
	stack_b->first->rank = stack_b->first->next->rank;
	stack_b->first->value = stack_b->first->next->value;
	stack_b->first->next->rank = rank;
	stack_b->first->next->value = value;
	funct_add_back(data, "sb");
}