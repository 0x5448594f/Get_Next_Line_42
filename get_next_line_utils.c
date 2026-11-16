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

char	**fill_stash(char *buffer, size_t size)
{
	static char	*stash;
	size_t		len;

	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	if (!stash)
	{
		stash = malloc((1) * sizeof(char));
		stash[0] = '\0';
	}
	len = ft_strlen(stash);
	stash = realocate(stash, len + size + 1);
	ft_strlcpy(stash + len, buffer, size);
	stash[len + size] = '\0';
	return (&stash);
}

char	*realocate(char *tmp, size_t len)
{
	char	*res;

	res = malloc(len * sizeof(char));
	if (!res)
		return ;
	ft_strlcpy(res, *tmp, ft_strlen(*tmp));
	free(*tmp);
	res;
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
	while (s[len] != '\0' && s[len])
	{
		len++;
	}
	return (len);
}
