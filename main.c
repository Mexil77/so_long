/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:14 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/16 22:35:25 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		printf("keycode : %d\n", keycode);
	return (0);
}

int	main(int argc, char const *argv[])
{
	char	**map;
	t_vars	vars;
	size_t	w;
	size_t	h;
	t_img	*objs;

	if (argc != 2)
		return (ft_error());
	map = ft_makemap(argv[1]);
	if (!map)
		return (ft_error());
	ft_printmap(map);
	w = ft_strlen(map[0]) * TILE;
	h = ft_getheight(map) * TILE;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, w, h, "so_long");
	if (!vars.win)
		return (ft_error());
	ft_drawmap(map, vars);
	objs = ft_makeobjs(map);
	if (!objs)
		return (ft_error());
	free (objs);
	mlx_key_hook(vars.win, ft_keyhook, &vars);
	ft_freemap(map);
	mlx_loop(vars.mlx);
	return (0);
}
