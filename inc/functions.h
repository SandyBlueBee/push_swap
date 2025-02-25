/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:07:56 by syukna            #+#    #+#             */
/*   Updated: 2025/02/25 14:00:46 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "push_swap.h"

/* ************************************************************************** */
/* *******************************FUNCTIONS********************************** */
/* ************************************************************************** */

int		parse_argv(t_program_data *data);
void	add_rank(t_stack *stack);

long int	check_individual_error(char *arg);

t_node	*node_init(int content);
t_stack	*stack_init(void);
void	dll_add_front(t_stack *stack, t_node *new_node);
void	dll_add_back(t_stack *stack, t_node *new_node);
void	dll_remove_node(t_stack *stack);

void	view_data(t_program_data *data);

int		is_duplicate(t_stack *stack);
void	check_sequence_error(t_stack *stack);

#endif