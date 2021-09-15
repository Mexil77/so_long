/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:14 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/15 23:24:51 by emgarcia         ###   ########.fr       */
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
	}
	if (keycode || vars)
	{
		printf("keycode : %d\n", keycode);
		printf("Hello from key_hook!\n");
	}
	return (0);
}

void	ft_drawsquare(t_data img, size_t y, size_t x, int col)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = (50 * y);
	j = (50 * x);
	k = (50 * y) + 50;
	l = (50 * x) + 50;
	printf("i : %zu\n", i);
	printf("j : %zu\n", j);
	printf("k : %zu\n", k);
	printf("l : %zu\n", l);
	printf("col : %d\n", col);
	while (i < k)
	{
		while (j < l)
		{
			my_mlx_pixel_put(&img, i, j, 0x00A239CC);
			j++;
		}
		j = (50 * y);
		i++;
	}
}

void	ft_drawmap(char **map, t_vars vars, size_t w, size_t h)
{
	size_t	i;
	size_t	j;
	t_data	img;

	i = -1;
	j = -1;
	img.img = mlx_new_image(vars.mlx, w + 100, h + 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (++i < h)
	{
		while (++j < w)
		{
			if (map[i][j] == '1')
				ft_drawsquare(img, i, j, 0x00A239CC);
			if (map[i][j] == '0')
				ft_drawsquare(img, i, j, 0x00A2FFFF);
			if (map[i][j] == 'C')
				ft_drawsquare(img, i, j, 0x00A2AAAA);
			if (map[i][j] == 'P')
				ft_drawsquare(img, i, j, 0x00A2AFBF);
			if (map[i][j] == 'E')
				ft_drawsquare(img, i, j, 0x00A2ABCDE);
		}
		j = -1;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}

int	main(int argc, char const *argv[])
{
	char	**map;
	t_vars	vars;
	size_t	w;
	size_t	h;

	atexit (leak);
	if (argc != 2)
		return (ft_error());
	map = ft_makemap(argv[1]);
	if (!map)
		return (ft_error());
	w = ft_strlen(map[0]) * 50;
	h = ft_getheight(map) * 50;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, w + 1000, h + 1000, "so_long");
	if (!vars.win)
		return (ft_error());
	ft_drawmap(map, vars, ft_strlen(map[0]), ft_getheight(map));
	mlx_key_hook(vars.win, ft_keyhook, &vars);
	mlx_loop(vars.mlx);
	printf("Hola\n");
	ft_printmap(map);
	ft_freemap(map);
	return (0);
}
