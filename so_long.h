/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:47 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/16 22:32:12 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>

# ifndef TILE
#  define TILE 32
# endif

typedef struct s_img {
	void	*img;
	size_t	x;
	size_t	y;
}				t_img;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

char	**ft_makemap(char const *file);
size_t	ft_getheight(char **map);
void	ft_drawmap(char **map, t_vars vars);
t_img	*ft_makeobjs(char **map);
size_t	ft_countobjs(char **map);

#endif