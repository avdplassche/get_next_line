/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:49:41 by alvan-de          #+#    #+#             */
/*   Updated: 2024/11/05 11:56:30 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	static char	*temp;
	static int	i;
	int			j;
	static char remainder;

	if (fd < 0)
		return (NULL);
	buffer[0] = '\0';
	if (!remainder)
		read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(buffer, '\n'))
	{
		read(fd, buffer, BUFFER_SIZE);
		if (!line)
			line = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(line, buffer);
			free(line);
			line = ft_strdup(temp);
			free(temp);
		}
	}
	if (ft_strchr(buffer, '\n'))
	{
		if (!line)
		{
			i = 0;
			while (buffer[i] != '\n')
				i++;
			line = ft_substr(buffer, 0, i);
			return (line);
		}
		else
		{
			j = i;
			while (buffer[i] != '\n')
				i++;
			line = ft_substr(buffer, j, i);
			return (line);
		}
	}
	return (line);
}

//	while (buffer[i] != '\n' && buffer[i] != '\0')
//		i++;
//	line = ft_strjoin(temp, ft_substr(buffer, 0, i));
	//free (temp);
	//line[count] = '\0';
