/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:21:30 by syukna            #+#    #+#             */
/*   Updated: 2025/02/25 18:42:20 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_program_data	data;

	data.argc = argc;
	data.argv = argv;
	data.stack_a = stack_init();
	data.stack_b = stack_init();
	data.funct_list = funct_init();
	parse_argv(&data);
	sort(&data);
	// view_data(&data);
	print_functs(&data);
	// ft_printf("yolo main %d %s", argc, data.argv[1]);
	return (0);
}