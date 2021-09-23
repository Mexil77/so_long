/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemi2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:33:00 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/23 18:25:43 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
