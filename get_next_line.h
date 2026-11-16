/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderive </var/spool/mail/tderive>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:55:53 by tderive           #+#    #+#             */
/*   Updated: 2026/11/14 09:10:59 by tderive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);

void		realocate(char **tmp, size_t len);
char		**fill_stash(char *buffer, size_t size);
int			contains(char *s, char c);

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *src);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
#endif
