/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderive </var/spool/mail/tderive>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:56:08 by tderive           #+#    #+#             */
/*   Updated: 2026/11/14 09:26:14 by tderive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		**stash;
	char		*result;
	char		*buffer;
	int			contain_value;
	int			size;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	size = read(fd, buffer, BUFFER_SIZE);
	buffer[size] = '\0';
	while (size)
	{
		stash = fill_stash(buffer, size);
		printf("Stash: %s\n", *stash);
		contain_value = contains(*stash, '\n');
		if (contain_value >= 0)
		{
			result = ft_substr(*stash, 0, contain_value + 1);
			*stash += contain_value + 1;
			break ;
		}
		result = ft_strdup(*stash);
		printf("Result: %s\n", result);
		size = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	val;
	unsigned char	*p;

	if (!s)
		return (NULL);
	i = -1;
	val = (unsigned char)c;
	p = (unsigned char *)s;
	while (p[++i] != '\0')
	{
		if (p[i] == val)
			return ((char *)(p) + i);
	}
	if (p[i] == val)
		return ((char *)p + i);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*result;

	len = ft_strlen(src);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, src, len + 1);
	return (result);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (BUFFER_SIZE);
	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (BUFFER_SIZE);
}
