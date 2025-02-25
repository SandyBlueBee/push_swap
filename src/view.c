/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:37:19 by syukna            #+#    #+#             */
/*   Updated: 2025/02/25 14:01:25 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	view_data(t_program_data *data)
{
	t_node *temp;
	ft_printf("********************************************\n");
	ft_printf("*    DATA PRINTCARD                        *\n");
	ft_printf("*                                          *\n");
	ft_printf("*    Stack A:                              *\n");
	if (data->stack_a->first)
	{
		temp = data->stack_a->first;
		int i = 0;
		while (i < data->stack_a->size)
		{
			ft_printf("*    %d                                    *\n", temp->rank);
			temp = temp->next;
			i++;
		}
	}
	// if (data->stack_b->first)
	// {
	// 	temp = data->stack_b->first;
	// 	int i = 0;
	// 	while (i < data->stack_b->size)
	// 	{
	// 		ft_printf("*    %d                                    *\n", data->stack_b->first->value);
	// 		temp = temp->next;
	// 		i++;
	// 	}
	// }
	ft_printf("********************************************\n");
}