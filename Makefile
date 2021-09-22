# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 15:42:35 by emgarcia          #+#    #+#              #
#    Updated: 2021/09/22 20:44:26 by emgarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_objs.c ft_boards.c ft_player2.c ft_player.c ft_draw.c ft_map_utils2.c ft_map_utils.c main.c ft_prints.c
SRCS_B	= ft_enemi_bonus.c ft_enemi2_bonus.c
LIBFT	= libft/libft.a
OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}
NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Imlx
RM		= rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@make -C libft
	@${CC} ${CFLAGS} ${LIBFT} ${OBJS} -Iincludes -lmlx -framework OpenGL -framework AppKit -o ${NAME}

bonus: ${OBJS_B} ${OBJS}
	@make -C libft
	@${CC} ${CFLAGS} ${LIBFT} ${OBJS} ${OBJS_B} -Iincludes -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	@cd libft ; make fclean
	@${RM} ${OBJS} ${OBJS_B}

fclean: clean
	@cd libft : make fclean
	@${RM} ${NAME}

re: fclean all