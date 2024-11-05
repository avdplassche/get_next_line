/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:49:41 by alvan-de          #+#    #+#             */
/*   Updated: 2024/11/05 23:06:46 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(int fd, char *buffer, char *remainder)
{
	char	*line;
	char	*temp;
	int		i;

	line = ft_strdup(remainder);
	while (!ft_strchr(buffer, '\n'))
	{
		read(fd, buffer, BUFFER_SIZE);
		if (!ft_strchr(buffer, '\n'))
		{
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
		else
		{
			while (buffer[i] != '\n' && buffer[i] != '\0')
				i++;
			temp = ft_strjoin(line, ft_substr(buffer, 0, i - 1));
			free(line);
			line = ft_strdup (temp);
			if (buffer[i] != '\0')
				remainder = ft_substr(buffer, i + 1, ft_strlen(buffer));
		}
	}
	return (line);
}
/*
char	*fill_remainder(char *buffer, char *remainder, char *joint)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	line = ft_strjoin(joint, ft_substr(buffer, 0, i));
	remainder = ft_substr(buffer, i, ft_strlen(buffer));
	return (line);
}
*/

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	static char	*remainder;

	if (!remainder)
		remainder = ft_strdup("\0");
	if (fd < 0)
		return (NULL);
	buffer[0] = '\0';    //* */mettre peut etre en commentaire
	line = fill_line(fd, buffer, remainder);
	return (line);
}
