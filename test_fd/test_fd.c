/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:00:00 by alvan-de          #+#    #+#             */
/*   Updated: 2024/11/05 11:03:16 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main (void)
{
	int		fd;
	char	*buffer;

	fd = open ("a.txt", O_RDONLY, 0);
	read(fd, buffer, 10);
	printf("%s", buffer);
	close(fd);
	return (0);
}
