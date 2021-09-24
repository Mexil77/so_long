/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 20:40:43 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/24 15:43:32 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_drawsquare(t_vars vars, size_t y, size_t x, char *imgname)
{
	size_t	i;
	size_t	j;
	void	*img;
	int		tile;

	tile = TILE;
	i = (tile * y);
	j = (tile * x);
	img = mlx_xpm_file_to_image(vars.mlx, imgname, &tile, &tile);
	mlx_put_image_to_window(vars.mlx, vars.win, img, j, i);
	mlx_destroy_image(vars.mlx, img);
}

void	ft_drawobj(t_vars vars, t_img *objs)
{
	char	*name;
	size_t	i;

	i = -1;
	while (objs[++i].type)
	{
		if (objs[i].type == 'C')
			name = "./img/item32.XPM";
		if (objs[i].type == 'P')
			name = "./img/player1r32.XPM";
		if (objs[i].type == 'E')
			name = "./img/house32.XPM";
		if (objs[i].type == 'X')
			name = "./img/enemy1l32.XPM";
		ft_drawsquare(vars, objs[i].y, objs[i].x, name);
	}
}

void	ft_drawmap(char **map, t_vars vars)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	while (++i < ft_getheight(map))
	{
		while (++j < ft_strlen(map[0]))
		{
			if (map[i][j] == '1')
				ft_drawsquare(vars, i, j, "./img/stone32.XPM");
			else if (map[i][j] != '0' && map[i][j] != 'P'
					&& map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'X')
				ft_error("Caracter inadecuado", vars);
			else
				ft_drawsquare(vars, i, j, "./img/grass32.XPM");
		}
		j = -1;
	}
}

void	ft_drawboard(char **map, t_vars vars)
{
	size_t	i;
	size_t	h;

	h = ft_getheight(vars.map);
	i = -1;
	while (++i < ft_strlen(map[0]))
	{
		ft_drawsquare(vars, h, i, "./img/ground32.XPM");
		ft_drawsquare(vars, h + 1, i, "./img/ground32.XPM");
	}
}

void	ft_drawall(t_vars vars)
{
	ft_drawmap(vars.map, vars);
	ft_drawboard(vars.map, vars);
	ft_drawobj(vars, vars.objs);
}
