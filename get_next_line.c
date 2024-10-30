/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:49:41 by alvan-de          #+#    #+#             */
/*   Updated: 2024/10/30 15:06:02 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	int			count;
	
	if (!ft_strchr_gnl(temp, '\n'))
		line = ft_strdup(buffer);
	count = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr_gnl(temp, '\n'))
	{
		temp = line;
		if (!line)
			line = ft_strdup(buffer);
		else
		{
			line = ft_strjoin(temp, buffer);
			free (temp);
		}
	}
	return (line);
}
