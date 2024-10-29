/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_02.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:05:15 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/28 15:08:24 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		command_ra(t_stack *stack);
int		command_rb(t_stack *stack);
int		command_rr(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);

int	command_ra(t_stack *stack)
{
	if (!stack || !stack->begin)
		return (0);
	if (stack->begin == stack->begin->next)
		return (0);
	stack->begin = stack->begin->next;
	return (6);
}

int	command_rb(t_stack *stack)
{
	if (!stack || !stack->begin)
		return (0);
	if (stack->begin == stack->begin->next)
		return (0);
	stack->begin = stack->begin->next;
	return (7);
}

int	command_rr(t_stack *stack_a, t_stack *stack_b)
{
	int	result;

	result = command_ra(stack_a) + command_rb(stack_b);
	if (result == 0)
		return (0);
	return (8);
}
