/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 20:40:43 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/18 19:17:12 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_img	ft_drawobj(t_vars vars, size_t y, size_t x, char type)
{
	t_img	imgs;
	char	*name;

	imgs.x = x;
	imgs.y = y;
	imgs.type = type;
	if (type == 'C')
		name = "./img/cookie15x16.XPM";
	if (type == 'P')
		name = "./img/worker12x16.XPM";
	if (type == 'E')
		name = "./img/ground32.XPM";
	ft_drawsquare(vars, y, x, name);
	return (imgs);
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
			else
				ft_drawsquare(vars, i, j, "./img/grass32.XPM");
		}
		j = -1;
	}
}

t_img	*ft_makeobjs(char **map, t_vars vars)
{
	t_img	*objs;
	size_t	numobjs;

	numobjs = ft_countobjs(map);
	objs = malloc(sizeof(t_img) * (numobjs + 1));
	if (!objs)
		return (NULL);
	objs[numobjs].type = '\0';
	ft_dropobjs(map, objs, vars);
	return (objs);
}
