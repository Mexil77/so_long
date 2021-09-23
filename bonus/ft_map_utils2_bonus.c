/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:21:07 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/23 18:25:56 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_validmap(t_vars vars, char **map)
{
	size_t	i;
	size_t	j;

	if (!map)
		ft_error("Mapa no se ha creado.", vars);
	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (i == 0 || j == 0 || j == ft_strlen(map[0]) - 1
				|| i == ft_getheight(map) - 1)
				if (map[i][j] != '1')
					ft_error("Mapa invalido.", vars);
		}
		j = -1;
	}
}
