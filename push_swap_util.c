/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:59:04 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/27 13:13:30 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_string_in_stack(t_stack *stack, char *string);
void	load_array_in_stack(t_stack *stack, char **string, int position);

void	load_string_in_stack(t_stack *stack, char *string)
{
	char	**array;
	int		counter;

	array = ft_split((const char *)string, ' ');
	load_array_in_stack(stack, array, 0);
	counter = 0;
	while (array[counter] != 0)
	{
		free(array[counter]);
		array[counter] = NULL;
		counter++;
	}
	free(array);
}

void	load_array_in_stack(t_stack *stack, char **string, int position)
{
	int	counter;
	int	result;

	counter = position;
	while (string[counter] != 0)
	{
		result = ft_atoi(string[counter]);
		counter++;
		add_number_in_stack(stack, result);
	}
	modify_stack(stack);
}
