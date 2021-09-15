# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 15:42:35 by emgarcia          #+#    #+#              #
#    Updated: 2021/09/15 19:13:27 by emgarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_mymlx.c ft_map_utils.c main.c
LIBFT	= libft/libft.a
OBJS	= ${SRCS:.c=.o}
NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Imlx
RM		= rm -rf

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJS}
	@make -C libft
	@${CC} ${CFLAGS} ${LIBFT} ${OBJS} -Iincludes -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	@cd libft ; make fclean
	@${RM} ${OBJS}

fclean: clean
	@cd libft : make fclean
	@${RM} ${NAME}

re: fclean all