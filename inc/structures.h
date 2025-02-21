/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:45:23 by syukna            #+#    #+#             */
/*   Updated: 2025/02/21 14:33:41 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/* ************************************************************************** */
/* ******************************STRUCTURES********************************** */
/* ************************************************************************** */

typedef struct s_node
{
	int	value;
	int	rank;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node	*first;
	t_node	*last;
	int		size;
}				t_stack;

typedef struct s_program_data
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				argc;
	char			**argv;
	
}				t_program_data;

#endif