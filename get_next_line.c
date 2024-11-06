/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:49:41 by alvan-de          #+#    #+#             */
/*   Updated: 2024/11/06 18:37:42 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*fill_line(int fd, char *remainder)
{
	char	*str;
	char	*temp;
	char	buffer[BUFFER_SIZE + 1];

	str = ft_strdup(remainder);
	while (!ft_strchr(buffer, '\n') && !ft_strchr(str, '\n'))
	{
		read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr(buffer, '\0') && BUFFER_SIZE != ft_strlen(buffer))
			break ;
		buffer[BUFFER_SIZE] = '\0';
		if (!str)
			str = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str, buffer);
			free(str);
			str = ft_strdup(temp);
			free(temp);
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	int			i;
	static char	*remainder;

	i = 0;
	if (!remainder)
		remainder = "";
	if (fd <= 0)
		return (NULL);
	temp = fill_line(fd, remainder);
//	printf("Temp : |%s|\n", temp);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	line = ft_substr(temp, 0, i);
	if (temp[i] == '\n')
	{
		if (temp[i + 1] == '\0')
			remainder = "";
		else
			remainder = ft_substr(temp, i + 1, ft_strlen(temp) - i);
	}
		//	if (temp[i] == '\0')
//		remainder = NULL;
//		return (NULL);
	free(temp);
	printf("Rem : |%s|\n", remainder);
	return (line);
}
