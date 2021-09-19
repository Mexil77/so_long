/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:14 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/19 18:18:42 by emgarcia         ###   ########.fr       */
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

int	ft_keyhook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 46)
		ft_printmap(vars->map);
	if (keycode == 31)
		ft_printobjs(vars->objs);
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		ft_moveplayer(*vars, keycode);
	return (0);
}

void	leak(void)
{
	system("leaks so_long");
}

int	main(int argc, char const *argv[])
{
	t_vars	vars;
	size_t	w;
	size_t	h;
	size_t	i;

	//atexit(leak);
	if (argc != 2)
		return (ft_error());
	vars.map = ft_makemap(argv[1]);
	if (!vars.map)
		return (ft_error());
	w = ft_strlen(vars.map[0]) * TILE;
	h = ft_getheight(vars.map) * TILE;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, w, h, "so_long");
	if (!vars.win)
		return (ft_error());
	ft_drawmap(vars.map, vars);
	vars.objs = ft_makeobjs(vars.map, vars);
	if (!vars.objs)
		return (ft_error());
	i = -1;
	vars.steps = calloc(sizeof(size_t), 1);
	vars.score = calloc(sizeof(size_t), 1);
	vars.allitems = calloc(sizeof(size_t), 1);
	printf("item : %zu\n", *vars.allitems);
	if (vars.score && vars.score && vars.allitems)
		while (vars.objs[++i].type)
			if (vars.objs[i].type == 'C')
				*vars.allitems += 1;
	mlx_key_hook(vars.win, ft_keyhook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
