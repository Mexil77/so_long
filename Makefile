# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 15:42:35 by emgarcia          #+#    #+#              #
#    Updated: 2021/09/13 16:58:55 by emgarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c
LIBFT	= libft/libft.a
OBJS	= ${SRCS:.c=.o}
NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@make -C libft
	@${CC} ${CFLAGS} ${LIBFT} ${OBJS} -o ${NAME}

clean:
	@cd libft ; make fclean
	@${RM} ${OBJS}

fclean: clean
	@cd libft : make fclean
	@${RM} ${NAME}

re: fclean all