/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:05:22 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/28 15:07:32 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int quantity, char **command_string)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_stack	command;

	stack_a.size = 0;
	stack_a.begin = NULL;
	stack_b.size = 0;
	stack_b.begin = NULL;
	command.size = 0;
	command.begin = NULL;
	if (quantity < 2)
		return (0);
	if (quantity == 2)
		load_string_in_stack(&stack_a, command_string[1]);
	else
		load_array_in_stack(&stack_a, command_string, 1);
	sort_stack(&stack_a, &stack_b, &command);
	ft_printlist_command(&command, 1);
	return (0);
}

void	error(char *error_string)
{
	ft_putendl_fd(error_string, STDERR_FILENO);
	exit(1);
}
