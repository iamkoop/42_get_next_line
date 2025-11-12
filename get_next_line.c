/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:55:16 by nildruon          #+#    #+#             */
/*   Updated: 2025/11/12 18:27:49 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char	*save_into_buff(int fd, char	**remainder, int *buff_size)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp_buff;
	ssize_t	reader;
	int		i;

	i = 0;
	temp_buff = malloc(BUFFER_SIZE * (*buff_size) + 1);
	if(!temp_buff)
		return(NULL);
	reader = read(fd, buffer, BUFFER_SIZE);
	while(reader != 0)
	{
		free(temp_buff);
		temp_buff = malloc(BUFFER_SIZE * (*buff_size) + 1);
		if(!temp_buff)
			return(NULL);
		while(i < *buff_size)
		{
			temp_buff[i] = buffer[i];
			i++;
		}
		reader = read(fd, buffer, BUFFER_SIZE);
		*buff_size *= 2;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	static char		*current_pos;
	char			*nxt_line;
	int				*buff_size;
	int				bool_end_of_line;

	bool_end_of_line = 0;
	buff_size = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!bool_end_of_line)
	{
		nxt_line = save_into_buff(fd, &current_pos,
		 &bool_end_of_line, &buff_size);
		if(!nxt_line)
			return (NULL);
		buff_size++;
	}
	return (nxt_line);
} */

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
	line = malloc(i + 1);
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
	line[r] = '\0';
	r = 0;
	while (buffer[i])
		(*remainder)[r++] = buffer[i++];
	(*remainder)[r] = '\0';
	return (line);
}


#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[] = "Hello world\nThis is a test\nAnother line";
    char *remainder = NULL;
    char *line;

    int buff_size = strlen(buffer);

    // First line
    line = scan_for_new_l(buffer, &remainder, buff_size);
    if (line)
    {
        printf("Line 1: %s\n", line);
        printf("Remainder 1: %s\n", remainder ? remainder : "(null)\n");
        free(line);
    }
    return 0;
}