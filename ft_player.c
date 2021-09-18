/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:26:40 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/18 21:15:00 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_isvalidmove(t_vars vars, int move)
{
	size_t	x;
	size_t	y;

	x = ft_getplayerx(vars.objs);
	y = ft_getplayery(vars.objs);
	if (move == 0)
		if (vars.map[y][x - 1] == '1')
			return (0);
	if (move == 1)
		if (vars.map[y + 1][x] == '1')
			return (0);
	if (move == 2)
		if (vars.map[y][x + 1] == '1')
			return (0);
	if (move == 13)
		if (vars.map[y - 1][x] == '1')
			return (0);
	return (1);
}

void	ft_move(t_vars vars, int move, size_t x, size_t y)
{
	size_t	i;

	i = ft_getplayerindex(vars.objs);
	vars.map[y][x] = '0';
	if (move == 0)
	{
		vars.map[y][x - 1] = 'P';
		vars.objs[i].x = x - 1;
	}
	if (move == 1)
	{
		vars.map[y + 1][x] = 'P';
		vars.objs[i].y = y + 1;
	}
	if (move == 2)
	{
		vars.map[y][x + 1] = 'P';
		vars.objs[i].x = x + 1;
	}
	if (move == 13)
	{
		vars.map[y - 1][x] = 'P';
		vars.objs[i].y = y - 1;
	}
}

void	ft_moveplayer(t_vars vars, int move)
{
	size_t	i;
	size_t	j;

	if (ft_isvalidmove(vars, move))
	{
		j = ft_getplayerx(vars.objs);
		i = ft_getplayery(vars.objs);
		ft_drawsquare(vars, i, j, "./img/grass32.XPM");
		ft_move(vars, move, j, i);
		j = ft_getplayerx(vars.objs);
		i = ft_getplayery(vars.objs);
		ft_drawsquare(vars, i, j, "./img/worker12x16.XPM");
		printf("Te puedes mover\n");
	}
}
