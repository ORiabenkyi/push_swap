/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_03.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:05:15 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/28 15:11:49 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		command_rra(t_stack *stack);
int		command_rrb(t_stack *stack);
int		command_rrr(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);

int	command_rra(t_stack *stack)
{
	if (!stack || !stack->begin)
		return (0);
	if (stack->begin == stack->begin->next)
		return (0);
	stack->begin = stack->begin->prev;
	return (9);
}

int	command_rrb(t_stack *stack)
{
	if (!stack || !stack->begin)
		return (0);
	if (stack->begin == stack->begin->next)
		return (0);
	stack->begin = stack->begin->prev;
	return (10);
}

int	command_rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	result;

	result = command_rra(stack_a) + command_rrb(stack_b);
	if (result == 0)
		return (0);
	return (11);
}

void	push(t_stack *stack, t_node *node)
{
	add_node_in_stack(stack, node);
}

t_node	*pop(t_stack *stack)
{
	t_node	*temp;

	if (stack->size == 0)
		return (NULL);
	if (stack->size == 1)
	{
		temp = stack->begin;
		stack->size = 0;
		stack->begin = NULL;
		return (temp);
	}
	temp = stack->begin;
	stack->begin = temp->next;
	stack->begin->prev = temp->prev;
	temp->prev->next = stack->begin;
	stack->size--;
	temp->prev = temp;
	temp->next = temp;
	return (temp);
}
