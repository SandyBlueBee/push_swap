/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:26:47 by syukna            #+#    #+#             */
/*   Updated: 2025/02/27 12:16:47 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three_a(t_program_data *data)
{
	int	first;
	int last;
	int mid;

	if (dll_sorted(data->stack_a))
		return ;
	first = data->stack_a->first->rank;
	mid = data->stack_a->first->next->rank;
	last = data->stack_a->last->rank;
	if (first > mid && first < last && last > mid)
		sa(data);
	else if (first < mid && first < last && last < mid)
	{
		rra(data);
		sa(data);
	}
	else if (first < mid && first > last && last < mid)
		rra(data);
	else if (first > mid && first > last && last > mid)
		ra(data);
	else if (first > mid && first > last && last < mid)
	{
		sa(data);
		rra(data);
	}
}
// ALL 5 CASE SCENARIOS
// case 1: 1 0 2
// case 2: 0 2 1
// case 3: 1 2 0
// case 4: 2 0 1
// case 5: 2 1 0

void	sort(t_program_data *data)
{
	if (dll_sorted(data->stack_a))
		return ;
	send_forward(data);
	send_back(data);
	// view_data(data);
}