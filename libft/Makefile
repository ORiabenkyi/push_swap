# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 13:59:55 by oriabenk          #+#    #+#              #
#    Updated: 2024/10/28 15:13:56 by oriabenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILE = 	cc

FLAGS = 	-Wall -Werror -Wextra

CFILES = 	ft_atoi.c \
			ft_strlen.c \
			ft_itoa.c \
			ft_isdigit.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strdup.c \
			ft_substr.c 

OFILES = $(CFILES:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OFILES)
	@ar rcs $@ $^

%.o: %.c libft.h
	@$(COMPILE) -c $(FLAGS) -o $@ $<

clean:
	@$(RM) $(OFILES)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
