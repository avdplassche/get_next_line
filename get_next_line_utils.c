/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvan-de <alvan-de@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:53:13 by alvan-de          #+#    #+#             */
/*   Updated: 2024/11/05 14:11:09 by alvan-de         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, char c)
{
	int		i;

	i = 0;
	if (c == 0)
	{
		while (s[i])
			i++;
		return ((char *)&s[i]);
	}
	else
	{
		while (s[i])
		{
			if (s[i] == c)
				return ((char *)&s[i]);
			i++;
		}
	}
	return (NULL);
}

unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = malloc((sizeof(char)) * (ft_strlen((char *)s1) + 1));
	if (!s2)
		return ("NULL : Malloc Strdup");
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	dest = malloc(sizeof(char) * (i + j + 1));
	if (!dest)
		return (NULL);
	j = -1;
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
		dest[i++] = s2[j];
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = -1;
	if (start >= ft_strlen((char *)s))
	{
		dest = ft_strdup("");
		return (dest);
	}
	if (len > ft_strlen((char *)s) - start)
		dest = malloc(sizeof(char) * (ft_strlen((char *)s) - start + 1));
	else
		dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return ("NULL : Malloc substr");
	while (++i < len && start < ft_strlen((char *)s))
	{
		dest[i] = s[start];
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
