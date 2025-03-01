/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:29:59 by syukna            #+#    #+#             */
/*   Updated: 2025/03/01 15:02:19 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	free_stack(t_stack	*stack)
// {
// 	t_node	*last;
// 	t_node	*prev;
	
// 	if (stack && stack->first != NULL)
// 	{
// 		last = stack->last;
// 		while (last != stack->first)
// 		{
// 			prev = last->prev;
// 			free(last);
// 			last = prev;
// 		}
// 		free(last);
// 	}
// 	free(stack);
// 	stack = NULL;
// }

void	free_stack(t_stack	*stack)
{
	
	while (stack->size)
		dll_remove_node(stack);
	free(stack);
	stack = NULL;
}

void	free_funct(t_funct	*funct)
{
	if (!funct)
		return ;
	t_funct	*prev;

	while (funct)
	{
		prev = funct;
		funct = funct->next;
		free(prev);
	}
}

void	free_all(t_program_data *data)
{
	if (!data)
		return ;
	free_stack(data->stack_a);
	free_stack(data->stack_b);
	free_funct(data->funct_list);
	// free(data);
}