/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:55:16 by nildruon          #+#    #+#             */
/*   Updated: 2025/11/18 18:28:36 by nildruon         ###   ########.fr       */
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
	if (buffer[i] == '\n')
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

int alloc_for_gnl_return_help(char **buffer, ssize_t *reader, int fd)
{	
	char *tmp_buffer;
	
	tmp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp_buffer)
		return (0);
	*reader = read(fd, tmp_buffer, BUFFER_SIZE);
	if (*reader == -1)
	{
		free(*buffer);
		free(tmp_buffer);
		return (-1);
	}
	tmp_buffer[*reader] = '\0';
	*buffer = update_buffer(*buffer, tmp_buffer);
	free(tmp_buffer);
	if (*reader == 0)
		return (0);
	return (1);
}

char	*alloc_for_gnl_return(char **remainder, int fd)
{
	ssize_t	reader;
	char 	*currentbuffer;
	char	*line;
	int		status;

	reader = 1;
	currentbuffer = ft_calloc(1, sizeof(char));
	if (!currentbuffer)
		return (NULL);
	while (!(line = scan_for_new_l(currentbuffer, remainder, ft_strlen(currentbuffer))))
	{
		status = alloc_for_gnl_return_help(&currentbuffer, &reader, fd);
		if(status == 0)
			return(currentbuffer);
		if(status == -1)
			return (NULL);
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