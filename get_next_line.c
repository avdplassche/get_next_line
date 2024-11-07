/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:54:31 by alvan-de          #+#    #+#             */
/*   Updated: 2024/11/07 17:50:56 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

// a faire sur sketche
#include "get_next_line.h"

char	*set_line(int fd, char *buffer, char *left_c)
{
	char	*temp;
	int		count;

	count = 1;
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (NULL);
		if (count == 0)
			break ;
		buffer[count] = '\0';
		if (!left_c)
			left_c = "";
		temp = ft_strjoin(left_c, buffer);
		left_c = ft_strdup(temp);
		free(temp);
		if (ft_strchr(left_c, '\n'))
			break ;
	}
	return (left_c);
}

char	*set_leftover(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	return (ft_substr(line, i + 1, ft_strlen(line) - i));
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*buffer;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = set_line(fd, buffer, left_c);
	left_c = set_leftover(line);
	free(buffer);
	while (left_c[i] != '\n')
		i++;
	return (ft_substr(line, 0, i - 1));
}
