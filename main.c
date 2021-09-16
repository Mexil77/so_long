/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:14 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/16 19:47:09 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leak(void)
{
	system("leaks so_long");
}

int	ft_error(void)
{
	printf("Error\n");
	return (0);
}

void	ft_freemap(char **map)
{
	size_t	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_printmap(char **map)
{
	size_t	i;

	i = -1;
	while (map[++i])
		printf("map[%zu] : %s\n", i, map[i]);
}

int	ft_keyhook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode || vars)
	{
		printf("keycode : %d\n", keycode);
		printf("Hello from key_hook!\n");
	}
	return (0);
}

void	ft_drawsquare(t_vars vars, size_t y, size_t x, char *imgname, int tile)
{
	size_t	i;
	size_t	j;
	void	*img;

	i = (tile * y);
	j = (tile * x);
	img = mlx_xpm_file_to_image(vars.mlx, imgname, &tile, &tile);
	mlx_put_image_to_window(vars.mlx, vars.win, img, j, i);
}

void	ft_drawmap(char **map, int tile, t_vars vars, size_t w, size_t h)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	while (++i < h)
	{
		while (++j < w)
		{
			if (map[i][j] == '1')
				ft_drawsquare(vars, i, j, "./stone32.XPM", tile);
			if (map[i][j] == '0')
				ft_drawsquare(vars, i, j, "./grass32.XPM", tile);
			if (map[i][j] == 'P')
				ft_drawsquare(vars, i, j, "./ground32.XPM", tile);
			if (map[i][j] == 'E')
				ft_drawsquare(vars, i, j, "./water32.XPM", tile);
		}
		j = -1;
	}
}

int	main(int argc, char const *argv[])
{
	char	**map;
	t_vars	vars;
	size_t	w;
	size_t	h;
	int		tile;

	tile = 32;
	atexit (leak);
	if (argc != 2)
		return (ft_error());
	map = ft_makemap(argv[1]);
	if (!map)
		return (ft_error());
	ft_printmap(map);
	w = ft_strlen(map[0]) * tile;
	h = ft_getheight(map) * tile;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, w, h, "so_long");
	if (!vars.win)
		return (ft_error());
	ft_drawmap(map, tile, vars, ft_strlen(map[0]), ft_getheight(map));
	mlx_key_hook(vars.win, ft_keyhook, &vars);
	ft_freemap(map);
	mlx_loop(vars.mlx);
	return (0);
}
