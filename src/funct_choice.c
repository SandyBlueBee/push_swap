/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_choice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:33:15 by syukna            #+#    #+#             */
/*   Updated: 2025/02/25 16:04:53 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_funct	*funct_init(void)
{
	t_funct	*new_funct_list;
	
	new_funct_list = malloc(sizeof(t_funct));
	if (!new_funct_list)
		return (NULL);
	new_funct_list->funct_name = NULL;
	new_funct_list->next = NULL;
	return (new_funct_list);
}
void	funct_add_back(t_program_data *data, char *funct_name)
{
	t_funct	*list;
	
	list = data->funct_list;
	if (list->funct_name == NULL)
	{
		list->funct_name = funct_name;
	}
	else
	{
		t_funct	*new_funct;

		new_funct = malloc(sizeof(t_funct));
		new_funct->funct_name = funct_name;
		while (list->next)
			list = list->next;
		list->next = new_funct;
		new_funct->next = NULL;
	}
}
