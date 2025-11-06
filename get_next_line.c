/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:55:16 by nildruon          #+#    #+#             */
/*   Updated: 2025/11/06 17:16:00 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *nxt_line;
	char buff[BUFFER_SIZE];

	if(read(fd, buff, BUFFER_SIZE) < 0)
		return (NULL);
	
	return(nxt_line);
}