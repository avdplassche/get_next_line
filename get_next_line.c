/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:49:41 by alvan-de          #+#    #+#             */
/*   Updated: 2024/11/05 18:39:21 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(int fd, char *buffer, char *remainder)
{
	char	*line;
	char	*temp;

	while (!ft_strchr(buffer, '\n'))
	{
		read (fd, buffer, BUFFER_SIZE);
		if ()
		if (!ft_strchr(remainder, '\n'))
			temp = ft_strdup(remainder);
		line = ft_strjoin(line, buffer);
	}
	return (line);
}

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
	line = fill_line(buffer, remainder);

	return (line);
}
