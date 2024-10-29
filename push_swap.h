/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:05:28 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/28 15:57:03 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# define PUSH_SWAP_H

typedef struct s_node
{
	int				number;
	unsigned int	sort_number;
	struct s_node	*next;
	struct s_node	*prev;
	int				begin;
}	t_node;

typedef struct s_stack
{
	int				size;
	int				delta;
	unsigned int	big_number;
	int				ready_to_sort;
	struct s_node	*begin;
}	t_stack;

enum e_command_id
{
	sa = 1,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	eid_max
};

int		bitwise_check(int a, int pow);
void	sort_stack(t_stack *stacka, t_stack *stackb, t_stack *command);

void	load_string_in_stack(t_stack *stack, char *string);
void	load_array_in_stack(t_stack *stack, char **string, int position);

int		add_number_in_stack(t_stack *stack, int number);
void	add_node_in_stack(t_stack *stack, t_node *node);
void	modify_stack(t_stack *stack);

void	error(char *error_string);

t_node	*ft_lstnew(int number);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstaddone(t_node *lst, t_node *new);
void	ft_printlist_command(t_stack *lst, int fd);
void	print_instructions(int instr, int fd);

void	ft_lstmap(t_node *lst, void *(*fun)(void *));
void	ft_printlist(t_stack *lst, int fd);
void	prinfbin(unsigned int n, int fd);

int		command_sa(t_stack *stack);
int		command_sb(t_stack *stack);
int		command_ss(t_stack *stack_a, t_stack *stack_b);
int		command_pa(t_stack *stack_a, t_stack *stack_b);
int		command_pb(t_stack *stack_a, t_stack *stack_b);

int		command_ra(t_stack *stack);
int		command_rb(t_stack *stack);
int		command_rr(t_stack *stack_a, t_stack *stack_b);

int		command_rra(t_stack *stack);
int		command_rrb(t_stack *stack);
int		command_rrr(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);

#endif