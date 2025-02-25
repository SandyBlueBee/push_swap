/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:54:30 by syukna            #+#    #+#             */
/*   Updated: 2025/02/24 16:40:56 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*node_init(int content)
{
	t_node	*new_node;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = content;
	new_node->rank = 0;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

t_stack	*stack_init(void)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->first = NULL;
	stack->last = NULL;
	stack->size = 0;
	return (stack);
}

void	dll_add_front(t_stack *stack, t_node *new_node) 
{
	if (!stack || !new_node)
		return ;
	if (stack->first == NULL)
	{
		stack->first = new_node;
		stack->last = new_node;
	}
	else
	{
		new_node->next = stack->first;
		new_node->prev = stack->last;
		stack->first->prev = new_node;
		stack->last->next = new_node;
		stack->first = new_node;
	}
	stack->size++;
}

void	dll_add_back(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack->first == NULL)
	{
		stack->first = new_node;
		stack->last = new_node;
	}
	else
	{
		new_node->next = stack->first;
		new_node->prev = stack->last;
		stack->first->prev = new_node;
		stack->last->next = new_node;
		stack->last = new_node;
	}
	stack->size++;
}

void	dll_remove_node(t_stack *stack) 
{	
	t_node	*node;
	
	if (!stack || !stack->first)
		return ;
	node = stack->first;
	if (stack->size == 1)
	{
		stack->first = NULL;
		stack->last = NULL;
	}
	else
	{
		stack->first = node->next;
		stack->last->next = stack->first;
		stack->first->prev = stack->last;
	}
	free(node);
	stack->size--;
}
