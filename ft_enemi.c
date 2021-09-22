/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:14:25 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/22 17:40:53 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_isenemi(size_t x, size_t y, t_img *objs, t_vars vars)
{
	size_t	i;

	i = -1;
	while (objs[++i].type)
	{
		if (objs[i].type == 'X' && objs[i].x == x && objs[i].y == y)
		{
			objs[i].x = 0;
			objs[i].y = 0;
			ft_freeall(vars);
			exit(0);
		}
	}
}

void	ft_isplayer(size_t x, size_t y, t_img *objs, t_vars vars)
{
	size_t	i;

	i = -1;
	while (objs[++i].type)
	{
		if (objs[i].type == 'P' && objs[i].x == x && objs[i].y == y)
		{
			objs[i].x = 0;
			objs[i].y = 0;
			ft_freeall(vars);
			exit(0);
		}
	}
}

size_t	ft_getenemyx(t_img *objs)
{
	size_t	i;

	i = -1;
	while (objs[++i].type)
		if (objs[i].type == 'X')
			return (objs[i].x);
	return (0);
}

size_t	ft_getenemyy(t_img *objs)
{
	size_t	i;

	i = -1;
	while (objs[++i].type)
		if (objs[i].type == 'X')
			return (objs[i].y);
	return (0);
}

size_t	ft_getenemyindex(t_img *objs)
{
	size_t	i;

	i = -1;
	while (objs[++i].type)
		if (objs[i].type == 'X')
			return (i);
	return (0);
}

void	ft_movee(t_vars vars, int move, size_t *x, size_t *y)
{
	size_t	i;

	i = ft_getenemyindex(vars.objs);
	vars.map[*y][*x] = '0';
	if (move == 0)
		*x -= 1;
	if (move == 1)
		*y += 1;
	if (move == 2)
		*x += 1;
	if (move == 13)
		*y -= 1;
	if (move % 2 == 0)
		vars.objs[i].x = *x;
	else
		vars.objs[i].y = *y;
	vars.map[*y][*x] = 'X';
}

size_t	ft_isvalidmovee(t_vars vars, int move)
{
	size_t	x;
	size_t	y;

	x = ft_getenemyx(vars.objs);
	y = ft_getenemyy(vars.objs);
	if (move == 0)
		if (vars.map[y][x - 1] != 'P' && vars.map[y][x - 1] != '0')
			return (0);
	if (move == 1)
		if (vars.map[y + 1][x] != 'P' && vars.map[y + 1][x] != '0')
			return (0);
	if (move == 2)
		if (vars.map[y][x + 1] != 'P' && vars.map[y][x + 1] != '0')
			return (0);
	if (move == 13)
		if (vars.map[y + 13][x] != 'P' && vars.map[y + 13][x] != '0')
			return (0);
	return (1);
}

void	ft_nextspritee(t_vars vars, size_t x, size_t y, int move)
{
	size_t	i;

	i = ft_getplayerindex(vars.objs);
	if (move != 0)
	{
		if (vars.objs[i].sprite == 0)
			ft_drawsquare(vars, x, y, "./img/enemy2r32.XPM");
		else
			ft_drawsquare(vars, x, y, "./img/enemy1r32.XPM");
		if (vars.objs[i].sprite == 0)
			vars.objs[i].sprite = 1;
		else
			vars.objs[i].sprite = 0;
	}
	else
	{
		if (vars.objs[i].sprite == 0)
			ft_drawsquare(vars, x, y, "./img/enemy2l32.XPM");
		else
			ft_drawsquare(vars, x, y, "./img/enemy1l32.XPM");
		if (vars.objs[i].sprite == 0)
			vars.objs[i].sprite = 1;
		else
			vars.objs[i].sprite = 0;
	}
}

void	ft_moveenemi(t_vars vars)
{
	size_t		i;
	size_t		j;
	static int	move = 0;

	if (ft_isvalidmovee(vars, move))
	{
		j = ft_getenemyx(vars.objs);
		i = ft_getenemyy(vars.objs);
		ft_drawsquare(vars, i, j, "./img/grass32.XPM");
		ft_movee(vars, move, &j, &i);
		ft_nextspritee(vars, i, j, move);
		ft_isplayer(j, i, vars.objs, vars);
	}
	else
	{
		if (move)
			move = 0;
		else
			move = 2;
	}
}
