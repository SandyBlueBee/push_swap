/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:01:06 by syukna            #+#    #+#             */
/*   Updated: 2025/03/01 16:32:41 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_all_digit(char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '-' && ft_isdigit(arg[i + 1]))
		i++;
	while(arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	is_int(long int num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

long int	check_individual_error(t_program_data *data, char *arg)
{
	int	check;
	long long int num;

	check = 1;
	if (!is_all_digit(arg))
		check = 0;
	num = ft_atoi(arg);
	if (!is_int(num))
		check = 0;
	if (check == 0)
	{
		write(2, "Error\n", 6);
		free_all(data);
		exit(EXIT_FAILURE);
	}
	return (num);
}