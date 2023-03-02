/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarcon <falarcon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:53:10 by falarcon          #+#    #+#             */
/*   Updated: 2023/03/02 12:41:34 by falarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		idx++;
	}
	return (idx);
}

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	d;
	size_t	s;

	d = ft_strlen(dest);
	s = 0;
	if (len <= ft_strlen(dest))
		return (ft_strlen(src) + len);
	while (src[s] && d + 1 < len)
	{
		dest[d] = src[s];
		d++;
		s++;
	}
	dest[d] = '\0';
	return (d + ft_strlen(&src[s]));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		len;

	len = 0;
	i = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && (char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free((char *)s1);
	return (str);
}
