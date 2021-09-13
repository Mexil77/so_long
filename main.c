/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:14 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/13 20:47:04 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leak(void)
{
	system("leaks so_long");
}

int	main(int argc, char const *argv[])
{
	int		fd;
	char	*line;
	size_t	i;

	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		printf("fd : %d\n", fd);
	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		printf("/* %zu */%s", i, line);
		free (line);
		line = get_next_line(fd);
		i++;
	}
	close (fd);
	printf("/* %zu */%s", i, line);
	printf("%d\n", argc);
	//atexit (leak);
	return (0);
}
