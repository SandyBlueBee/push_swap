/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:37:19 by syukna            #+#    #+#             */
/*   Updated: 2025/02/25 19:01:43 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	view_data(t_program_data *data)
{
	t_node *temp;
	ft_printf("********************************************\n");
	ft_printf("*    DATA PRINTCARD                        *\n");
	
	if (data->stack_a->first != NULL)
	{
		ft_printf("*                                          *\n");
		ft_printf("*  Stack A: num, rank, upts, dpts, score   *\n", data->stack_a->size);
		temp = data->stack_a->first;
		int i = 0;
		while (i < data->stack_a->size)
		{
			ft_printf("*              %d    %d    %d    %d   %d        *\n", temp->value, temp->rank, temp->upts, temp->dpts, temp->score);
			temp = temp->next;
			i++;
		}
	}
	if (data->stack_b->first != NULL)
	{
		ft_printf("*                                          *\n");
		ft_printf("*  Stack B: num, rank, upts, dpts, score   *\n", data->stack_b->size);
		temp = data->stack_b->first;
		int i = 0;
		while (i < data->stack_b->size)
		{
			ft_printf("*              %d    %d    %d    %d   %d        *\n", temp->value, temp->rank, temp->upts, temp->dpts, temp->score);
			temp = temp->next;
			i++;
		}
	}
	
	ft_printf("********************************************\n");
}

void	print_functs(t_program_data *data)
{
	if (data->funct_list->funct_name)
	{
		t_funct *current_funct;
		
		current_funct = data->funct_list;
		while (current_funct)
		{
			ft_printf("%s\n", current_funct->funct_name);
			current_funct = current_funct->next;
		}
		
	}
}