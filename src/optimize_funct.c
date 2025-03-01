/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:29:18 by syukna            #+#    #+#             */
/*   Updated: 2025/02/28 16:26:58 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	remove_double_swap(t_funct *funct)
{
	t_funct	*next;
	
	next = funct->next;
	funct->funct_name = "ss";
	funct->next = next->next;
	free(next);
}

void	optimize_funct(t_program_data *data)
{
	t_funct *funct;

	funct = data->funct_list;
	while (funct->next)
	{
		if (!ft_strncmp(funct->funct_name, "sb", 2) && !ft_strncmp(funct->next->funct_name, "sa", 2))
			remove_double_swap(funct);
		// else if (!ft_strncmp(funct->funct_name, "pa", 2) && !ft_strncmp(funct->next->funct_name, "pb", 2))
		// 	printf("FOUND ONE!");
		funct = funct->next;
	}
}
