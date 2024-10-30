/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:49:41 by alvan-de          #+#    #+#             */
/*   Updated: 2024/10/30 23:35:07 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	int			count;
	
	while (!ft_strchr(buffer, '\n'))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		temp = line;
		free(line);
		if (!temp)
			line = ft_strdup(buffer);
		else
		{
			line = ft_strjoin(temp, buffer);
			free (temp);
		}
	} 
	
	return (line);
}
