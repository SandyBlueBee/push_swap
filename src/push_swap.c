/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:21:30 by syukna            #+#    #+#             */
/*   Updated: 2025/03/01 16:31:11 by syukna           ###   ########.fr       */
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
	optimize_funct(&data);
	print_functs(&data);
	free_all(&data);
	// view_data(&data);
	return (0);
}