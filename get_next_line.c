/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:49:41 by alvan-de          #+#    #+#             */
/*   Updated: 2024/10/31 16:30:10 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

//ESSAYER POUR 1 LIGNE POUR L'INSTANT

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	static char	*line;
	char	*temp;
	int		i;
	int		count;

	if (fd < 0)
		return (NULL);
	/*if (!read(fd, buffer, BUFFER_SIZE))*/
	/*	return (NULL);*/
	count = 0;
	i = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		count += read(fd, buffer, BUFFER_SIZE);
		if (!ft_strchr(buffer, '\n'))
			line = ft_strjoin(line, buffer);
		else if (ft_strchr(buffer, '\n') || ft_strchr(buffer, '\0'))
			break ;
	}
//	while (buffer[i] != '\n' && buffer[i] != '\0')
//		i++;
//	temp = ft_substr(line, count - BUFFER_SIZE, i);
//	line = ft_strjoin(line, temp);
	//free(temp);
	return (line);
}
