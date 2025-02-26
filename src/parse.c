/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:22:28 by syukna            #+#    #+#             */
/*   Updated: 2025/02/25 17:34:05 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Split the argv if all in one string
 * @param argc Which will be updated to the amount of numbers
 * @param argv Which will either be split of brought down to first position
 * @return splitted array
 */
char	**split_or_no_split(int *argc, char **argv)
{
	char **splitted_array;

	if (*argc < 2)
		exit(EXIT_FAILURE);
	if (*argc == 2)
	{
		int i;

		i = 0;
		splitted_array = ft_split(argv[1], ' ');
		if (!splitted_array || !splitted_array[0])
		{
			write(2, "Error", 6);
			exit(EXIT_FAILURE);
		}
		while (splitted_array[i] != NULL)
			i++;
		*argc = i;
	}
	else
	{
		splitted_array = &argv[1];
		*argc -= 1;
	}
	return (splitted_array);
}

void	add_rank(t_stack *stack)
{
	t_node	*current_node;
	t_node	*next_node;
	int	i;
	int	count;
	
	i = 0;
	current_node = stack->first;
	next_node = current_node->next;
	while (i < stack->size)
	{
		count = 0;
		while (next_node != current_node)
		{
			if (current_node->value > next_node->value)
				count++;
			next_node = next_node->next;
		}
		current_node->rank = count;
		current_node = current_node->next;
		next_node = current_node->next;
		i++;
	}
}

/**
 * @brief Will parse the elements in argv to stack A from data program
 * @param data all data
 */
int	parse_argv(t_program_data *data)
{
	int	i;
	int	num;
	t_node	*new_node;
	
	data->argv = split_or_no_split(&data->argc, data->argv);
	i = 0;
	while (data->argv[i] != NULL)
	{
		num = check_individual_error(data->argv[i]);
		new_node = node_init(num);
		dll_add_back(data->stack_a, new_node);
		i++;
	}
	check_sequence_error(data->stack_a);
	add_rank(data->stack_a);
	return (0);
}