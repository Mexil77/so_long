/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:47 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/23 22:01:57 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>
# include <time.h>

# ifndef TILE
#  define TILE 32
# endif

typedef struct s_img {
	size_t	x;
	size_t	y;
	size_t	sprite;
	char	type;
}				t_img;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	size_t	*steps;
	size_t	*score;
	size_t	*allitems;
	t_img	*objs;
}				t_vars;

void	ft_error(char *str, t_vars vars);
void	ft_freeall(t_vars vars);
char	**ft_makemap(char const *file);
size_t	ft_getheight(char **map);
void	ft_drawmap(char **map, t_vars vars);
void	ft_makeobjs(t_vars *vars);
size_t	ft_countobjs(char **map);
void	ft_drawsquare(t_vars vars, size_t y, size_t x, char *imgname);
void	ft_drawobj(t_vars vars, t_img *objs);
void	ft_moveplayer(t_vars vars, int move);
size_t	ft_getplayerx(t_img *objs);
size_t	ft_getplayery(t_img *objs);
size_t	ft_getplayerindex(t_img *objs);
size_t	ft_isitem(size_t x, size_t y, t_img *objs);
size_t	ft_isexit(size_t x, size_t y, t_img *objs);
void	ft_printboards(t_vars vars, size_t flag, size_t h);
void	ft_isenemi(size_t x, size_t y, t_img *objs, t_vars vars);
void	ft_moveenemi(t_vars vars);
void	ft_validmap(t_vars vars, char **map);
void	ft_validobjs(t_img *objs, t_vars vars);
void	ft_win(t_vars vars);

void	ft_isenemi(size_t x, size_t y, t_img *objs, t_vars vars);
void	ft_isplayer(size_t x, size_t y, t_img *objs, t_vars vars);
size_t	ft_getenemyx(t_img *objs);
size_t	ft_getenemyy(t_img *objs);
size_t	ft_getenemyindex(t_img *objs);
int		ft_automove(t_vars *vars);
void	ft_drawboard(char **map, t_vars vars);

void	ft_printmap(char **map);
void	ft_printobjs(t_img *objs);
void	leak(void);

#endif