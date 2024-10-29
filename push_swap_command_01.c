/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ORiabenkyi <o.riabenkyi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:05:15 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/27 18:57:25 by ORiabenkyi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		command_sa(t_stack *stack);
int		command_sb(t_stack *stack);
int		command_ss(t_stack *stack_a, t_stack *stack_b);
int		command_pa(t_stack *stack_a, t_stack *stack_b);
int		command_pb(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);

int	command_sa(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	if (!stack || !stack->begin)
		return (0);
	node1 = stack->begin;
	node2 = node1->next;
	if (node1 == node2)
		return (0);
	node1->next = node2->next;
	node2->next->prev = node1;
	node1->next = node2->next;
	node2->next->prev = node1;
	node2->prev = node1->prev;
	node1->prev->next = node2;
	node1->prev = node2;
	node2->next = node1;
	stack->begin = node2;
	return (1);
}

int	command_sb(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	if (!stack || !stack->begin)
		return (0);
	node1 = stack->begin;
	node2 = node1->next;
	if (node1 == node2)
		return (0);
	node1->next = node2->next;
	node2->next->prev = node1;
	node1->next = node2->next;
	node2->next->prev = node1;
	node2->prev = node1->prev;
	node1->prev->next = node2;
	node1->prev = node2;
	node2->next = node1;
	stack->begin = node2;
	return (2);
}

int	command_ss(t_stack *stack_a, t_stack *stack_b)
{
	int	result;

	result = command_sa(stack_a) + command_sb(stack_b);
	if (result > 0)
		return (3);
	return (0);
}

int	command_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_b || !stack_b->begin)
		return (0);
	temp = pop(stack_b);
	push(stack_a, temp);
	return (4);
}

int	command_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_a || !stack_a->begin)
		return (0);
	temp = pop(stack_a);
	push(stack_b, temp);
	return (5);
}
