/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 20:40:43 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/16 22:30:11 by emgarcia         ###   ########.fr       */
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
			{
				ft_drawsquare(vars, i, j, "./img/grass32.XPM");
				if (map[i][j] == 'P')
					ft_drawsquare(vars, i, j, "./img/worker12x16.XPM");
				if (map[i][j] == 'C')
					ft_drawsquare(vars, i, j, "./img/cookie15x16.XPM");
			}
		}
		j = -1;
	}
}

t_img	*ft_makeobjs(char **map)
{
	t_img	*objs;
	size_t	numobjs;

	numobjs = ft_countobjs(map);
	printf("numobjs : %zu\n", numobjs);
	objs = malloc(sizeof(t_img) * (numobjs + 1));
	if (!objs)
		return (NULL);
	return (objs);
}
