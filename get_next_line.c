/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:54:31 by alvan-de          #+#    #+#             */
/*   Updated: 2024/11/08 16:50:20 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

// a faire sur sketche
#include "get_next_line.h"

static char	*hard_free(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

static int	tests(int fd, char *buffer, int b_size, char *leftover)
{
	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || BUFFER_SIZE <= 0 || fd < 0)
	{
		free (buffer);
		return (0);
	}
	if (!leftover)
	{
		leftover = ft_strdup("");
		if (!leftover)
		{
			free(buffer);
			return (0);
		}
	}
	return (1);
}

static char	*set_line(char *leftover)
{
	int	i;

	i = 0;
	while (leftover[i] != '\n')
		i++;
	return (ft_substr(leftover, 0, i));
}

static char	*set_left(char *leftover)
{
	int	i;

	i = 0;
	while (leftover[i] != '\n' && leftover[i] != '\0')
		i++;
	return (ft_substr(leftover, i + 1, ft_strlen(leftover) - i));
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*buffer;
	char		*line;
	char		*temp;
	int			count;

	if (!tests(fd, buffer, BUFFER_SIZE, leftover))
		return (NULL);
	while (1)
	{
		if (!leftover || ft_strchr(leftover, '\n') == 1)  //? pour premier 
			break ;
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0 || (count == 0 && !leftover))
			return (hard_free(buffer), hard_free(leftover), NULL);
		if (count == 0)
			break ;
		buffer[count] = '\0';
		temp = ft_strjoin(leftover, buffer);
		if (!temp)
			return (hard_free(buffer));
		free(leftover);
		leftover = ft_strdup(temp);
		free(temp);
	}
	line = set_line(leftover);
	leftover = set_left(leftover);
	if (!line || !leftover) // && ?
		return (NULL);
	return (line);
}
