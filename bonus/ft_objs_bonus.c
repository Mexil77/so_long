/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objs_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:16:37 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/23 18:25:59 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
			if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E' ||
					map[i][j] == 'X')
				count++;
		j = -1;
	}
	return (count);
}

t_img	ft_iniobj(size_t y, size_t x, char type)
{
	t_img	obj;

	obj.x = x;
	obj.y = y;
	obj.sprite = 0;
	obj.type = type;
	return (obj);
}

void	ft_dropobjs(char **map, t_img *objs)
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
				objs[k++] = ft_iniobj(i, j, map[i][j]);
			else if (map[i][j] == 'P')
				objs[k++] = ft_iniobj(i, j, map[i][j]);
			else if (map[i][j] == 'E')
				objs[k++] = ft_iniobj(i, j, map[i][j]);
			else if (map[i][j] == 'X')
				objs[k++] = ft_iniobj(i, j, map[i][j]);
		}
		j = -1;
	}
}

t_img	*ft_makeobjs(char **map)
{
	t_img	*objs;
	size_t	numobjs;

	numobjs = ft_countobjs(map);
	objs = malloc(sizeof(t_img) * (numobjs + 1));
	if (!objs)
		return (NULL);
	objs[numobjs].type = '\0';
	ft_dropobjs(map, objs);
	return (objs);
}

void	ft_validobjs(t_img *objs, t_vars vars)
{
	size_t	i;
	size_t	p;
	size_t	c;
	size_t	e;

	i = -1;
	p = 0;
	c = 0;
	e = 0;
	if (!objs)
		ft_error("Objetos no se han creado.", vars);
	while (objs[++i].type)
	{
		if (objs[i].type == 'P')
			p++;
		if (objs[i].type == 'C')
			c++;
		if (objs[i].type == 'E')
			e++;
	}
	if (p != 1 || e != 1 || c == 0)
		ft_error("No. Elementos incorrecto.", vars);
}