/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:16:37 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/24 14:11:22 by emgarcia         ###   ########.fr       */
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

t_img	ft_iniobj(size_t y, size_t x, char type)
{
	t_img	obj;

	obj.x = x;
	obj.y = y;
	obj.sprite = 0;
	obj.automove = 0;
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
		}
		j = -1;
	}
}

void	ft_makeobjs(t_vars *vars)
{
	t_img	*objs;
	size_t	numobjs;
	size_t	i;

	i = -1;
	numobjs = ft_countobjs(vars->map);
	objs = malloc(sizeof(t_img) * (numobjs + 1));
	if (!objs)
		ft_error("No se crearon los objetos", *vars);
	objs[numobjs].type = '\0';
	ft_dropobjs(vars->map, objs);
	while (objs[++i].type)
		if (objs[i].type == 'C')
			*vars->allitems += 1;
	vars->objs = objs;
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
