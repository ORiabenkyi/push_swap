/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ls_util_02.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:05:15 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/28 15:02:20 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int number);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstaddone(t_node *lst, t_node *new);

t_node	*ft_lstnew(int number)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(1 * sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->number = number;
	new_node->prev = new_node;
	new_node->next = new_node;
	new_node->begin = 1;
	return (new_node);
}

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*first;

	if (!lst)
		return (0);
	first = lst;
	while (1)
	{
		if (!first->begin)
			first = first->next;
	}
	return (first->prev);
}

void	ft_lstaddone(t_node *first_member, t_node *add_member)
{
	t_node	*temp;

	if (!add_member)
		error("Wrong node add. Unknown new member");
	if (!first_member)
	{
		first_member = add_member;
		return ;
	}
	temp = first_member->prev;
	if (!temp)
		error("Wrong node to add. Wrong record");
	temp->next->prev = add_member;
	add_member->next = temp->next;
	add_member->prev = temp;
	temp->next = add_member;
}
