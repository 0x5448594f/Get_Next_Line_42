/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderive </var/spool/mail/tderive>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:06:38 by tderive           #+#    #+#             */
/*   Updated: 2026/11/14 09:25:57 by tderive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	**fill_stash(char *buffer, size_t size)
{
	static char	*stash;
	size_t		i;

	if (!buffer)
		return (NULL);
	if (!stash)
		stash = buffer;
	i = 0;
	while (i < size && buffer[i])
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			break ;
		i++;
	}
	stash = realocate(stash, ft_strlen(stash) + size + 1);
	ft_strlcpy(stash + ft_strlen(stash), buffer, size + 1);
	return (&stash);
}

char	*realocate(char *tmp, size_t len)
{
	char	*res;

	res = malloc(len * sizeof(char));
	ft_strlcpy(res, tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (res);
}

int	contains(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c) return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*result;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	index = -1;
	while (++index < len)
		result[index] = s[index + start];
	result[len] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\0')
	{
		len++;
	}
	return (len);
}
