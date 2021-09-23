# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 15:42:35 by emgarcia          #+#    #+#              #
#    Updated: 2021/09/23 19:10:57 by emgarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_draw.c \
			ft_finish.c \
			ft_map_utils.c \
			ft_map_utils2.c \
			ft_objs.c \
			ft_player.c \
			ft_player2.c \
			ft_prints.c \
			main.c
SRCS_B	=	bonus/ft_draw_bonus.c \
			bonus/ft_finish_bonus.c \
			bonus/ft_map_utils_bonus.c \
			bonus/ft_map_utils2_bonus.c \
			bonus/ft_objs_bonus.c \
			bonus/ft_player_bonus.c \
			bonus/ft_player2_bonus.c \
			bonus/ft_prints_bonus.c \
			bonus/main_bonus.c \
			bonus/ft_enemi_bonus.c \
			bonus/ft_enemi2_bonus.c \
			bonus/ft_boards_bonus.c
LIBFT	= libft/libft.a
OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}
NAME	= so_long
NAME_B	= so_long_bonus
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Imlx
RM		= rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@make -C libft
	@${CC} ${CFLAGS} ${LIBFT} ${OBJS} -Iincludes -lmlx -framework OpenGL -framework AppKit -o ${NAME}

bonus: ${OBJS_B}
	@make -C libft
	@${CC} ${CFLAGS} ${LIBFT} ${OBJS_B} -Iincludes -lmlx -framework OpenGL -framework AppKit -o ${NAME_B}

clean:
	@cd libft ; make fclean
	@${RM} ${OBJS} ${OBJS_B}

fclean: clean
	@cd libft : make fclean
	@${RM} ${NAME}

re: fclean all