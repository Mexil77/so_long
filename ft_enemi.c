/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:14:25 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/20 00:03:38 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_isenemi(size_t x, size_t y, t_img *objs)
{
	size_t	i;

	i = -1;
	while (objs[++i].type)
	{
		if (objs[i].type == 'X' && objs[i].x == x && objs[i].y == y)
		{
			objs[i].x = 0;
			objs[i].y = 0;
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

void	ft_movee(t_vars vars, int move, size_t *x, size_t *y)
{
	size_t	i;

	i = ft_getplayerindex(vars.objs);
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

	x = ft_getplayerx(vars.objs);
	y = ft_getplayery(vars.objs);
	if (move == 0)
		if (vars.map[y][x - 1] != 'P' && vars.map[y][x - 1] != '0')
			return (0);
	return (1);
}

void	ft_moveenemi(t_vars vars)
{
	size_t	i;
	size_t	j;
	int		move;

	move = 0;
	if (ft_isvalidmovee(vars, move))
	{
		j = ft_getenemyx(vars.objs);
		i = ft_getenemyy(vars.objs);
		ft_drawsquare(vars, i, j, "./img/grass32.XPM");
		ft_movee(vars, move, &j, &i);
		ft_drawsquare(vars, i, j, "./img/eleph16.XPM");
	}
}
