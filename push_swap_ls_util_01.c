/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ls_util_01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:05:15 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/28 15:05:50 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int number);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstmap(t_node *lst, void *(*fun)(void *));
void	ft_printlist(t_stack *lst, int fd);
void	print_instructions(int instr, int fd);
void	ft_printlist_command(t_stack *lst, int fd);

void	ft_lstmap(t_node *lst, void *(*fun)(void *))
{
	t_node	*first;
	void	*temp;

	first = lst;
	if (!lst || !fun)
		return ;
	temp = fun(&lst->number);
	lst = lst->next;
	while (lst != first)
	{
		temp = fun(&lst->number);
		lst = lst->next;
	}
}

void	ft_printlist(t_stack *lst, int fd)
{
	t_node	*first;

	ft_putstr_fd(ft_itoa(lst->begin->number), fd);
	ft_putchar_fd('\n', fd);
	first = lst->begin->next;
	while (first != lst->begin)
	{
		ft_putstr_fd(ft_itoa(first->number), fd);
		ft_putchar_fd('\n', fd);
		first = first->next;
	}
	ft_putstr_fd("End list \n", fd);
}

void	ft_printlist_command(t_stack *lst, int fd)
{
	t_node	*first;
	int		counter;

	counter = lst->size;
	if (!lst || lst->size == 0)
		return ;
	first = lst->begin;
	while (counter--)
	{
		print_instructions(first->number, fd);
		first = first->next;
	}
}

void	prinfbin(unsigned int n, int fd)
{
	if (n > 1)
		prinfbin(n >> 1, fd);
	ft_putchar_fd((n & 1) + '0', fd);
}

void	print_instructions(int instr, int fd)
{
	if (instr == sa)
		ft_putstr_fd("sa\n", fd);
	else if (instr == sb)
		ft_putstr_fd("sb\n", fd);
	else if (instr == ss)
		ft_putstr_fd("ss\n", fd);
	else if (instr == pa)
		ft_putstr_fd("pa\n", fd);
	else if (instr == pb)
		ft_putstr_fd("pb\n", fd);
	else if (instr == ra)
		ft_putstr_fd("ra\n", fd);
	else if (instr == rb)
		ft_putstr_fd("rb\n", fd);
	else if (instr == rr)
		ft_putstr_fd("rr\n", fd);
	else if (instr == rra)
		ft_putstr_fd("rra\n", fd);
	else if (instr == rrb)
		ft_putstr_fd("rrb\n", fd);
	else if (instr == rrr)
		ft_putstr_fd("rrr\n", fd);
}
