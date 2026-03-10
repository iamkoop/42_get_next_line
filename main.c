/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:21:00 by nildruon          #+#    #+#             */
/*   Updated: 2026/03/10 19:21:34 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("test", O_RDONLY);
	i = 0;
	if (fd < 0)
	{
		perror("open failed");
		return (1);
	}
	while (i < 10759)
	{
		line = get_next_line(fd,0);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
