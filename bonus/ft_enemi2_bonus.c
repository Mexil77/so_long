/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemi2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:33:00 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/24 15:25:24 by emgarcia         ###   ########.fr       */
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
