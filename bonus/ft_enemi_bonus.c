/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemi_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:14:25 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/24 14:53:12 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_movee(t_vars vars, t_img *enemi, size_t *x, size_t *y)
{
	vars.map[*y][*x] = '0';
	if (enemi->automove == 0)
		*x -= 1;
	if (enemi->automove == 1)
		*y += 1;
	if (enemi->automove == 2)
		*x += 1;
	if (enemi->automove == 13)
		*y -= 1;
	if (enemi->automove % 2 == 0)
		enemi->x = *x;
	else
		enemi->y = *y;
	vars.map[*y][*x] = 'X';
}

size_t	ft_isvalidmovee(t_vars vars, t_img enemi)
{
	size_t	x;
	size_t	y;

	x = enemi.x;
	y = enemi.y;
	if (enemi.automove == 0)
		if (vars.map[y][x - 1] != 'P' && vars.map[y][x - 1] != '0')
			return (0);
	if (enemi.automove == 1)
		if (vars.map[y + 1][x] != 'P' && vars.map[y + 1][x] != '0')
			return (0);
	if (enemi.automove == 2)
		if (vars.map[y][x + 1] != 'P' && vars.map[y][x + 1] != '0')
			return (0);
	if (enemi.automove == 13)
		if (vars.map[y + 13][x] != 'P' && vars.map[y + 13][x] != '0')
			return (0);
	return (1);
}

void	ft_nextspritee(t_vars vars, size_t x, size_t y, t_img enemi)
{
	if (enemi.automove != 0)
	{
		if (enemi.sprite == 0)
			ft_drawsquare(vars, x, y, "./img/enemy2r32.XPM");
		else
			ft_drawsquare(vars, x, y, "./img/enemy1r32.XPM");
		if (enemi.sprite == 0)
			enemi.sprite = 1;
		else
			enemi.sprite = 0;
	}
	else
	{
		if (enemi.sprite == 0)
			ft_drawsquare(vars, x, y, "./img/enemy2l32.XPM");
		else
			ft_drawsquare(vars, x, y, "./img/enemy1l32.XPM");
		if (enemi.sprite == 0)
			enemi.sprite = 1;
		else
			enemi.sprite = 0;
	}
}

void	ft_moveenemi(t_vars vars)
{
	size_t		i;
	size_t		j;
	size_t		k;

	k = -1;
	while (vars.objs[++k].type)
	{
		if (vars.objs[k].type == 'X' && ft_isvalidmovee(vars, vars.objs[k]))
		{
			j = vars.objs[k].x;
			i = vars.objs[k].y;
			ft_drawsquare(vars, i, j, "./img/grass32.XPM");
			ft_movee(vars, &vars.objs[k], &j, &i);
			ft_nextspritee(vars, i, j, vars.objs[k]);
			ft_isplayer(j, i, vars.objs, vars);
		}
		else
		{
			if (vars.objs[k].automove)
				vars.objs[k].automove = 0;
			else
				vars.objs[k].automove = 2;
		}
	}
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
