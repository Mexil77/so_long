/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:47 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/15 20:18:42 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

char	**ft_makemap(char const *file);
size_t	ft_getheight(char **map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif