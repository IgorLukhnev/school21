# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loberyn <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/09 17:40:08 by loberyn           #+#    #+#              #
#    Updated: 2021/01/09 18:11:48 by loberyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =	ft_printf.c \
		srcs/ft_putchar.c \
		srcs/ft_putnstr.c \
		srcs/ft_resolve_char.c \
		srcs/ft_resolve_flags.c \
		srcs/ft_resolve_hexa.c \
		srcs/ft_resolve_int.c \
		srcs/ft_resolve_percent.c \
		srcs/ft_resolve_ptr.c \
		srcs/ft_resolve_str.c \
		srcs/ft_resolve_uint.c \
		srcs/ft_resolve_width.c \
		srcs/ft_resolver.c \
		srcs/ft_strtolower.c \
		srcs/ft_uitoa.c \
		srcs/ft_ull_base.c

SURPL_O =	*.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCS = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) bonus -C ./libft
	mv libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

fnorms : 
	norminette -R CheckForbiddenSourceHeader */*.[ch]

fnorm : norms
	norminette -R CheckForbiddenSourceHeader *.[ch]

norms : 
	norminette */*.[ch]

norm : norms
	norminette *.[ch]

.PHONY: all, clean, fclean, re
