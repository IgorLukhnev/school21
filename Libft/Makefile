# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loberyn <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 15:41:02 by loberyn           #+#    #+#              #
#    Updated: 2020/11/12 19:02:19 by loberyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c
BONUS	= main_bonus.c
BOBJS	= ${BONUS:.c=.o}
LOC		= ./libft
NAME	= test
NAMEB	= test_bonus
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIBNAME	= -lft

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: 	${OBJS}
			${CC} -o ${NAME} ${OBJS} -L ${LOC} ${LIBNAME}

bonus:		${BOBJS}
			${CC} -o ${NAMEB} ${BOBJS} -L ${LOC} ${LIBNAME}

clean:
				rm -f ${OBJS}

fclean: clean
				rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all re
