/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:49:41 by alvan-de          #+#    #+#             */
/*   Updated: 2024/11/03 17:56:23 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

//ESSAYER POUR 1 LIGNE POUR L'INSTANT

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*line;
	char		*temp;
	int			i;
	int			count;

	if (fd < 0)
		return ("NULL : fd");
	count = read(fd, buffer, BUFFER_SIZE);
	i = 0;
	if (!ft_strchr(buffer, '\n'))
		temp = ft_strdup(buffer);
	else 
	{
		while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
	// static = substr buffer, i, until != \0
		return (ft_substr(buffer, 0, i));
	}
	while (!ft_strchr(buffer, '\n'))
	{
		count += read(fd, buffer, BUFFER_SIZE);
		if(!ft_strchr(buffer, '\n'))
		{
			line = ft_strjoin(temp, buffer);
			free (temp);
			temp = ft_strdup(line);
			free (line);
		}
	}
//	while (buffer[i] != '\n' && buffer[i] != '\0')
//		i++;
//	line = ft_strjoin(temp, ft_substr(buffer, 0, i));
	//free (temp);
	//line[count] = '\0';
	return (temp);
}
