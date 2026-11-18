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

char	*get_next_line(int fd)
{
	static char	*stash;
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	char	*result;
	int	size;
	int	contain_val;

	size = read(fd, buffer, BUFFER_SIZE);
	buffer[size] = '\0';
	result = NULL;
	while (size > 0)
	{
		stash = ft_strjoin(stash, buffer);
		contain_val = contains(stash, '\n');
		if (contain_val > 0)
		{
			result = ft_substr(stash, 0, contain_val);
			tmp = ft_strdup(stash + contain_val + 1);
			free(stash);
			stash = tmp;
		}
		size = read(fd, buffer, BUFFER_SIZE);
		if (size > 0)
			buffer[size] = '\0';
	}
	return (result);
}

int	contains(char *s, char first_c)
{
	size_t	i;	

	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == first_c)
			return (i);
		i++;
	}
	return (-1);
}
