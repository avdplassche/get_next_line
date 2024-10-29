/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:03:02 by alvan-de          #+#    #+#             */
/*   Updated: 2024/10/29 17:03:35 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*s;
	char	*pathname;

	pathname = "aaaa.txt";
	fd = open(pathname, O_RDONLY);
	read(fd, s, 10);
	printf("%s", s);
	return (0);
}
