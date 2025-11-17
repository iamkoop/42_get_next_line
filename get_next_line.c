/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:55:16 by nildruon          #+#    #+#             */
/*   Updated: 2025/11/17 22:33:22 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*scan_for_new_l(char *buffer, char **remainder, int buff_size)
{
	int		i;
	int		r;
	char	*line;

	i = 0;
	r = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (NULL);
	*remainder = malloc((buff_size - i) + 1);
	if (!*remainder)
		return (NULL);
	line = malloc(i + 2);
	if (!line)
	{
		free(*remainder);
		return (NULL);
	}
	while (r < i)
	{
		line[r] = buffer[r];
		r++;
	}
	if(buffer[i] == '\n')
	{
		line[r] = '\n';
		r++;
	}
	line[r] = '\0';
	r = 0;
	i++;
	while (buffer[i])
		(*remainder)[r++] = buffer[i++];
	(*remainder)[r] = '\0';
	return (line);
}

char	*alloc_for_gnl_return(char **remainder, int fd)
{
	int		bytes;
	ssize_t	reader;
	char 	*currentbuffer;
	char 	*temp_buffer;
	char	*line;

	reader = 1;
	bytes = BUFFER_SIZE;
	currentbuffer = ft_calloc(bytes + 1, sizeof(char));
	if (!currentbuffer)
		return (NULL);
	while (!(line = scan_for_new_l(currentbuffer, remainder, bytes)))
	{
		temp_buffer = ft_calloc(bytes + 1, sizeof(char));
		if (!temp_buffer)
			return (NULL);
		reader = read(fd, temp_buffer, bytes);
		if (reader == -1)
		{
			free(currentbuffer);
			free(temp_buffer);
			return (NULL);
		}
		temp_buffer[reader] = '\0';
		currentbuffer = update_buffer(currentbuffer, temp_buffer);
		free(temp_buffer);
		if (reader == 0)
			return (currentbuffer);
		bytes *= 2;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char *line;
	if(remainder)
	{
		line = scan_for_new_l(remainder, &remainder, ft_strlen(remainder));
		return (line);
	}
	return (alloc_for_gnl_return(&remainder, fd));
}
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test", O_RDONLY);
    int i = 0;

    if (fd < 0)
    {
        perror("open failed");
        return 1;
    }

    while (i < 6)
    {
        char *line = get_next_line(fd);
        if (!line)
            break;
        printf("%s", line);
        free(line);
        i++;
    }

    close(fd);
    return 0;
}