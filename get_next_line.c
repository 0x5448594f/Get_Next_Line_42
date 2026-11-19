/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thyo <derive.theo@proton.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:42:06 by thyo              #+#    #+#             */
/*   Updated: 2026/11/18 18:49:18 by thyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(stash, fd);
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	result = get_line(stash);
	if (!result)
	{
		free(stash);
		return (NULL);
	}
	stash = resize_stash(stash);
	return (result);
}

char	*read_line(char *s, int fd)
{
	char		*buff;
	char		*tmp;
	ssize_t	size;
	
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	size = read(fd, buff, BUFFER_SIZE);
	while (size > 0)
	{
		buff[size] = '\0';
		tmp = ft_strjoin(s, buff);
		free(s);
		if(!tmp)
			return (NULL);
		s = tmp;
		if (contains(buff, '\n'))
			break ;
		size = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (s);
}

char	*get_line(char *s)
{
	char	*result;
	int	i;
	int	len;

	if (!s[0])
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	len = i;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

char	*resize_stash(char *s)
{
	char	*new_stash;
	int	i;
	int	j;

	i = 0;
	if (!s[0] || !s)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i])
		i++;
	new_stash = malloc((ft_strlen(s) - i + 1) * sizeof(char));
	if (!new_stash)
		return (NULL);
	j = 0;
	while (s[i] != '\0' && i < (int)ft_strlen(s))
	{
		new_stash[j] = s[i];
		i++;
		j++;
	}
	new_stash[j] = '\0';
	free(s);
	return (new_stash);
}
