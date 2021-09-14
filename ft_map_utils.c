/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:55:39 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/14 19:25:41 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_calchighval(int fd)
{
	char	*line;
	size_t	h;
	size_t	w;
	size_t	aux;

	h = 0;
	line = get_next_line(fd);
	w = ft_strlen(line);
	if (ft_findchar(line, '\n'))
		w--;
	aux = w;
	while (line && ++h)
	{
		free (line);
		if (aux != w)
			return (0);
		line = get_next_line(fd);
		aux = ft_strlen(line);
		if (ft_findchar(line, '\n'))
			aux--;
	}
	if (h < 3 || w < 3)
		return (0);
	return (h);
}

char	*ft_dropstr(char *str)
{
	char	*res;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(str);
	if (!ft_findchar(str, '\n'))
		size++;
	res = malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	size--;
	res[size] = '\0';
	while (++i < size)
		res[i] = str[i];
	return (res);
}

char	**ft_dropmap(int fd, size_t h)
{
	char	**map;
	char	*line;
	size_t	i;

	map = malloc(sizeof(char *) * (h + 1));
	if (!map)
		return (NULL);
	i = -1;
	line = get_next_line(fd);
	while (line && ++i < h)
	{
		map[i] = ft_dropstr(line);
		free (line);
		if (!map[i])
			return (NULL);
		line = get_next_line(fd);
	}
	map[h] = NULL;
	return (map);
}

char	**ft_makemap(char const *file)
{
	char	**map;
	size_t	h;
	int		fd;

	fd = open(file, O_RDWR);
	if (fd < 0)
		return (NULL);
	h = ft_calchighval(fd);
	close (fd);
	if (!h)
		return (NULL);
	fd = open(file, O_RDWR);
	if (fd < 0)
		return (NULL);
	map = ft_dropmap(fd, h);
	close (fd);
	return (map);
}
