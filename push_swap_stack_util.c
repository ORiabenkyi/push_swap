/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:59:04 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/28 15:56:38 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		add_number_in_stack(t_stack *stack, int number);
void	modify_stack(t_stack *stack);
void	add_node_in_stack(t_stack *stack, t_node *node);
void	prepare_to_sort(t_stack *stack);

int	add_number_in_stack(t_stack *stack, int number)
{
	t_node	*temp_node;

	if (!stack)
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		if (!stack)
			error("Create stack error.");
	}
	if (!stack->begin)
	{
		temp_node = ft_lstnew(number);
		if (!temp_node)
			error("Create node error.");
		stack->begin = temp_node;
		stack->size = 1;
	}
	else
	{
		temp_node = ft_lstnew(number);
		ft_lstaddone(stack->begin, temp_node);
		stack->size++;
	}
	return (1);
}

void	add_node_in_stack(t_stack *stack, t_node *node)
{
	if (!stack)
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		if (!stack)
			error("Create stack error.");
	}
	if (!stack->begin)
	{
		stack->begin = node;
		stack->size = 1;
	}
	else
	{
		node->next = stack->begin;
		node->prev = stack->begin->prev;
		node->prev->next = node;
		stack->begin->prev = node;
		stack->begin = node;
		stack->size++;
	}
}

void	modify_stack(t_stack *stack)
{
	t_node	*temp_node;

	if (stack->delta < 0)
		error("Second change? NO!");
	stack->delta = 0;
	temp_node = stack->begin;
	if (temp_node->number < 0)
		stack->delta = temp_node->number;
	temp_node = temp_node->next;
	while (temp_node != stack->begin)
	{
		if (temp_node->number < stack->delta)
			stack->delta = temp_node->number;
		temp_node = temp_node->next;
	}
	prepare_to_sort(stack);
}

void	prepare_to_sort(t_stack *stack)
{
	t_node	*temp_node;
	int		counter;

	counter = 1;
	temp_node = stack->begin;
	temp_node->sort_number = temp_node->number - stack->delta;
	stack->big_number = temp_node->sort_number;
	temp_node = temp_node->next;
	while (temp_node != stack->begin)
	{
		temp_node->sort_number = temp_node->number - stack->delta;
		if (stack->big_number < temp_node->sort_number)
			stack->big_number = temp_node->sort_number;
		temp_node = temp_node->next;
	}
	stack->ready_to_sort = 1;
}
