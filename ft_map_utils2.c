/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:21:07 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/17 20:33:55 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_countobjs(char **map)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
			if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				count++;
		j = -1;
	}
	return (count);
}

void	ft_dropobjs(char **map, t_img *objs, t_vars vars)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = -1;
	j = -1;
	k = 0;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				objs[k++] = ft_drawobj(vars, i, j, map[i][j]);
			else if (map[i][j] == 'P')
				objs[k++] = ft_drawobj(vars, i, j, map[i][j]);
			else if (map[i][j] == 'E')
				objs[k++] = ft_drawobj(vars, i, j, map[i][j]);
		}
		j = -1;
	}
}
