#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*string;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	string = malloc((len1 + len2 + 1) * sizeof(char));
	if (!string)
		return (NULL);
	i = -1;
	while (++i < len1)
		string[i] = s1[i];
	i = -1;
	while (++i < len2)
		string[i + len1] = s2[i];
	string[len1 + len2] = '\0';
	return (string);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	size_t	i;
	char	*result;

	len = ft_strlen(src);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (src[i] && i < len)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	contains(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
