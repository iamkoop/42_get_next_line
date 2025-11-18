/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:55:13 by nildruon          #+#    #+#             */
/*   Updated: 2025/11/18 18:34:31 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t		i;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (SIZE_MAX / size <= nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		ptr[i] = '\0';
		i++;
	}
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