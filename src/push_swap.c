/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:21:30 by syukna            #+#    #+#             */
/*   Updated: 2025/02/21 14:33:58 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_program_data	data;
	data.argc = argc;
	data.argv = argv;
	ft_printf("yolo %d %s", argc, data.argv[1]);
	check_argv(&data);
	return (0);
}