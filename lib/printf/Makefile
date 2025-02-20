# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 22:10:43 by dsayumi-          #+#    #+#              #
#    Updated: 2023/08/17 22:11:10 by dsayumi-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCS		= ft_printf.h
SRCS		= ft_printf.c \
			ft_putchar.c \
			ft_puthex_lower.c \
			ft_puthex_upper.c \
			ft_putnbr.c \
			ft_putptr.c \
			ft_putstr.c \
			ft_putunsign.c \
			ft_strlen.c
OBJS		= $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS) $(INCS)
	ar -rcs	$(NAME) $(OBJS)

.c.o: 		
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus: all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
