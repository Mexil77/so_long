/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:14 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/24 15:20:46 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freeall(t_vars vars)
{
	size_t	i;

	if (vars.map)
	{
		i = -1;
		while (vars.map[++i])
			free(vars.map[i]);
		free(vars.map);
	}
	if (vars.objs)
		free(vars.objs);
	if (vars.allitems)
		free(vars.allitems);
	if (vars.score)
		free(vars.score);
	if (vars.steps)
		free(vars.steps);
	if (vars.mlx && vars.win)
	{
		mlx_clear_window(vars.mlx, vars.win);
		mlx_destroy_window(vars.mlx, vars.win);
	}
}

int	ft_keyhook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		ft_freeall(*vars);
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
	vars->mlx = NULL;
	vars->win = NULL;
	vars->steps = calloc(sizeof(size_t), 1);
	vars->score = calloc(sizeof(size_t), 1);
	vars->allitems = calloc(sizeof(size_t), 1);
	if (!vars->score || !vars->score || !vars->allitems)
		ft_error("valores iniciales error.", *vars);
}

int	ft_closeredcros(t_vars *vars)
{
	ft_freeall(*vars);
	exit(0);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_vars	vars;
	size_t	w;
	size_t	h;

	ft_inivals(&vars);
	if (argc != 2 || !ft_valname(argv[1]))
		ft_error("Nombre incorrecto.", vars);
	vars.map = ft_makemap(argv[1]);
	ft_validmap(vars, vars.map);
	w = ft_strlen(vars.map[0]) * TILE;
	h = ft_getheight(vars.map) * TILE;
	ft_makeobjs(&vars);
	ft_validobjs(vars.objs, vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, w, h, "so_long");
	if (!vars.win)
		ft_error("Fallo al crear la ventana", vars);
	ft_drawmap(vars.map, vars);
	ft_drawobj(vars, vars.objs);
	mlx_hook(vars.win, 17, 1L << 17, ft_closeredcros, &vars);
	mlx_key_hook(vars.win, ft_keyhook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
