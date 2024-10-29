/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:08:50 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/26 11:56:42 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

char	**ft_split(char const *str, char c);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strdup(const char *income_str);
char	*ft_itoa(int number);
int		ft_atoi(const char *str);
int		ft_isdigit(int symbol);
size_t	ft_strlen(const char *str);

/* save or show information */

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif