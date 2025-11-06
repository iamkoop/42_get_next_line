/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nildruon <nildruon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:55:28 by nildruon          #+#    #+#             */
/*   Updated: 2025/11/06 15:43:15 by nildruon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *get_next_line(int fd);

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif