/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:05:22 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/28 15:59:03 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		bitwise_check(int a, int pow);
int		is_sorted(t_stack *stack);
void	sort_stack(t_stack *stacka, t_stack *stackb, t_stack *command);
int		pow_of_two(size_t pow);
int 	how_many_one_in_range(t_stack *stack, int pow);

int	pow_of_two(size_t pow)
{
	if (pow <= 0)
		return (1);
	return (2 * pow_of_two(pow - 1));
}

int	bitwise_check(int a, int two_in_pow)
{
	return (a & two_in_pow);
}

int how_many_one_in_range(t_stack *stack, int pow)
{
	int		counter;
	t_node	*temp_node;
	int		res;

	counter = stack->size;
	temp_node = stack->begin;
	res = 0;
	while (counter--)
	{
		res+=bitwise_check(temp_node->sort_number, pow_of_two(pow));
		temp_node = temp_node->next;
	}
	return (res);
}

int	is_sorted(t_stack *stack)
{
	t_node	*temp_node;

	if (!stack || !stack->begin)
		return (0);
	temp_node = stack->begin;
	if (temp_node->next == temp_node)
		return (1);
	while (temp_node->next != stack->begin)
	{
		if (temp_node->number > temp_node->next->number)
			return (0);
		temp_node = temp_node->next;
	}
	ft_putendl_fd("List sorted", 1);
	return (1);
}


void	sort_stack(t_stack *st_a, t_stack *st_b, t_stack *cmd)
{
	int	num;
	int	counter;
	int	count_number;

	num = 0;
	if (is_sorted(st_a))
		return ;
	while ((unsigned int)pow_of_two(num) <= st_a->big_number)
	{
		counter = st_a->size;
		count_number = how_many_one_in_range(st_a, num);
		while (counter-- && count_number)
		{
			if ((!bitwise_check(st_a->begin->sort_number, pow_of_two(num))
					&& add_number_in_stack(cmd, command_pb(st_a, st_b))))
				continue ;
			add_number_in_stack(cmd, command_ra(st_a));
		}
		if (!bitwise_check(st_a->begin->sort_number, pow_of_two(num)))
			add_number_in_stack(cmd, command_pb(st_a, st_b));
		while (st_b->size)
			add_number_in_stack(cmd, command_pa(st_a, st_b));
		num++;
	}
}
