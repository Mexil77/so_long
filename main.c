/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:14 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/21 20:59:25 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit(0);
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

void	ft_inivals(t_vars *vars)
{
	size_t	i;

	i = -1;
	vars->steps = calloc(sizeof(size_t), 1);
	vars->score = calloc(sizeof(size_t), 1);
	vars->allitems = calloc(sizeof(size_t), 1);
	if (vars->score && vars->score && vars->allitems)
		while (vars->objs[++i].type)
			if (vars->objs[i].type == 'C')
				*vars->allitems += 1;
}

int	ft_automove(t_vars *vars)
{
	time_t			c;
	static time_t	ini = 0;

	c = time(NULL);
	if (c != ini)
	{
		ft_moveenemi(*vars);
		ini = c;
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_vars	vars;
	size_t	w;
	size_t	h;

	if (argc != 2)
		ft_error("Argumento invalido");
	vars.map = ft_makemap(argv[1]);
	ft_validmap(vars.map);
	w = ft_strlen(vars.map[0]) * TILE;
	h = ft_getheight(vars.map) * TILE;
	vars.objs = ft_makeobjs(vars.map);
	ft_validobjs(vars.objs);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, w, h, "so_long");
	if (!vars.win)
		ft_error("Fallo al crear la ventana");
	ft_drawmap(vars.map, vars);
	ft_drawobj(vars, vars.objs);
	ft_inivals(&vars);
	ft_printboards(vars);
	mlx_key_hook(vars.win, ft_keyhook, &vars);
	mlx_loop_hook(vars.mlx, ft_automove, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
