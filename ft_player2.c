/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:14:37 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/19 18:31:40 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_getplayerx(t_img *objs)
{
	size_t	i;

	i = -1;
	while (objs[++i].type)
		if (objs[i].type == 'P')
			return (objs[i].x);
	return (0);
}

size_t	ft_getplayery(t_img *objs)
{
	size_t	i;

	i = -1;
	while (objs[++i].type)
		if (objs[i].type == 'P')
			return (objs[i].y);
	return (0);
}

size_t	ft_getplayerindex(t_img *objs)
{
	size_t	i;

	i = -1;
	while (objs[++i].type)
		if (objs[i].type == 'P')
			return (i);
	return (0);
}

size_t	ft_isitem(size_t x, size_t y, t_img *objs)
{
	size_t	i;

	i = -1;
	while (objs[++i].type)
	{
		if (objs[i].type == 'C' && objs[i].x == x && objs[i].y == y)
		{
			objs[i].x = 0;
			objs[i].y = 0;
			return (1);
		}
	}
	return (0);
}

size_t	ft_isexit(size_t x, size_t y, t_img *objs)
{
	size_t	i;

	i = -1;
	while (objs[++i].type)
	{
		if (objs[i].type == 'E' && objs[i].x == x && objs[i].y == y)
		{
			objs[i].x = 0;
			objs[i].y = 0;
			return (1);
		}
	}
	return (0);
}
