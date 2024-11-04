/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:49:41 by alvan-de          #+#    #+#             */
/*   Updated: 2024/11/04 14:22:02 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

//ESSAYER POUR 1 LIGNE POUR L'INSTANT

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	static char	*temp;
	int			i;
//	int			count;

	i = 0;
	if (fd < 0)
		return (NULL);
	buffer[0] = '\0';
	if (!temp)
		temp = ft_strdup("");
	while (!ft_strchr(buffer, '\n'))
	{
		read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		if (!ft_strchr(buffer, '\n'))
		{
			line = ft_strjoin(temp, buffer);
			free (temp);
			temp = ft_strdup(line);
			free (line);
		}
	}
	if (buffer[i])
	{
		while (buffer[i] != '\n')
			i++;
		line = ft_strjoin(temp, ft_substr(buffer, 0, i));
		free(temp);
		temp = ft_substr(buffer, i, ft_strlen(buffer));
	}
	return (line);
}

//	while (buffer[i] != '\n' && buffer[i] != '\0')
//		i++;
//	line = ft_strjoin(temp, ft_substr(buffer, 0, i));
	//free (temp);
	//line[count] = '\0';
