/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:26:40 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/23 20:30:17 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_isvalidmove(t_vars vars, int move)
{
	size_t	x;
	size_t	y;

	x = ft_getplayerx(vars.objs);
	y = ft_getplayery(vars.objs);
	if (move == 0)
		if (vars.map[y][x - 1] == '1' ||
			(vars.map[y][x - 1] == 'E' && *vars.score < *vars.allitems))
			return (0);
	if (move == 1)
		if (vars.map[y + 1][x] == '1' ||
			(vars.map[y + 1][x] == 'E' && *vars.score < *vars.allitems))
			return (0);
	if (move == 2)
		if (vars.map[y][x + 1] == '1' ||
			(vars.map[y][x + 1] == 'E' && *vars.score < *vars.allitems))
			return (0);
	if (move == 13)
		if (vars.map[y - 1][x] == '1' ||
			(vars.map[y - 1][x] == 'E' && *vars.score < *vars.allitems))
			return (0);
	return (1);
}

void	ft_move(t_vars vars, int move, size_t *x, size_t *y)
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
	vars.map[*y][*x] = 'P';
}

void	ft_destroyitem(t_vars vars, size_t i, size_t j)
{
	*vars.score += 1;
	ft_drawsquare(vars, i, j, "./img/grass32.XPM");
	ft_drawsquare(vars, ft_getheight(vars.map) + 1, 2, "./img/ground32.XPM");
	ft_printboards(vars, 2, ft_getheight(vars.map));
}

void	ft_nextspritep(t_vars vars, size_t x, size_t y, int move)
{
	size_t	i;

	i = ft_getplayerindex(vars.objs);
	if (move != 0)
	{
		if (vars.objs[i].sprite == 0)
			ft_drawsquare(vars, x, y, "./img/player2r32.XPM");
		else
			ft_drawsquare(vars, x, y, "./img/player1r32.XPM");
		if (vars.objs[i].sprite == 0)
			vars.objs[i].sprite = 1;
		else
			vars.objs[i].sprite = 0;
	}
	else
	{
		if (vars.objs[i].sprite == 0)
			ft_drawsquare(vars, x, y, "./img/player2l32.XPM");
		else
			ft_drawsquare(vars, x, y, "./img/player1l32.XPM");
		if (vars.objs[i].sprite == 0)
			vars.objs[i].sprite = 1;
		else
			vars.objs[i].sprite = 0;
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
		ft_move(vars, move, &j, &i);
		if (ft_isitem(j, i, vars.objs))
			ft_destroyitem(vars, i, j);
		ft_isenemi(j, i, vars.objs, vars);
		ft_nextspritep(vars, i, j, move);
		*vars.steps += 1;
		ft_drawsquare(vars, ft_getheight(vars.map), 2, "./img/ground32.XPM");
		ft_printboards(vars, 1, ft_getheight(vars.map));
		if (ft_isexit(j, i, vars.objs))
			ft_win(vars);
	}
}
