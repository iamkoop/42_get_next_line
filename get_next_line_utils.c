/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilsdruon <nilsdruon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:55:13 by nildruon          #+#    #+#             */
/*   Updated: 2025/11/17 20:35:30 by nilsdruon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_bzero(void *s, size_t n)
{
    size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}


void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ft_bzero(ptr, 1);
		return (ptr);
	}
	if (SIZE_MAX / size <= nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
	{
		size++;
	}
	return (size);
}

char* update_buffer(char *buffer ,char *temp_buffer)
{
	char *updated_buffer;
	int buffer_len;
	int temp_buffer_len;
	int i;

	buffer_len = ft_strlen(buffer);
	temp_buffer_len = ft_strlen(temp_buffer);
	updated_buffer = ft_calloc(sizeof(char), buffer_len + temp_buffer_len + 1);
	if(!updated_buffer)
		return (NULL);
	i = 0;
	while(i < buffer_len)
	{
		updated_buffer[i] = buffer[i];
		i++;
	}
	free(buffer);
	while (i < buffer_len + temp_buffer_len)
	{
		updated_buffer[i] = temp_buffer[i - buffer_len];
		i++;	
	}
	return (updated_buffer);
}