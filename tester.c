/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:03:02 by alvan-de          #+#    #+#             */
/*   Updated: 2024/11/03 17:58:37 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int	i;

	i = 0;
	fd = open("aaaa.txt", O_RDONLY, 0);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
