/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:03:02 by alvan-de          #+#    #+#             */
/*   Updated: 2024/11/04 18:29:27 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open("aaaa.txt", O_RDONLY, 0);
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
