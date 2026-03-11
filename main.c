/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:21:00 by nildruon          #+#    #+#             */
/*   Updated: 2026/03/11 12:07:07 by nildruon         ###   ########.fr       */
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
	while (i < 2)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
		i++;
	}
	get_next_line(-42);
	close(fd);
	return (0);
}
