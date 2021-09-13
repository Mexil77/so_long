/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:14 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/13 23:12:10 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leak(void)
{
	system("leaks so_long");
}

size_t	ft_calcareaval(int fd)
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
		if (aux != w && line)
			return (0);
		free (line);
		line = get_next_line(fd);
		aux = ft_strlen(line);
		if (ft_findchar(line, '\n'))
			aux--;
	}
	if (h < 3 || w < 3)
		return (0);
	return (h * w);
}

int	main(int argc, char const *argv[])
{
	size_t	area;
	int		fd;
	//char	**mapa;

	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		printf("Error de lectura\n");
	area = ft_calcareaval(fd);
	close (fd);
	if (!area)
	{
		printf("Error\n");
		return (0);
	}
	printf("%zu\n", area);
	//atexit (leak);
	return (0);
}
