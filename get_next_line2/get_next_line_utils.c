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

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{	
	size_t		idx;
	size_t		src_idx;
	size_t		value;

	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize < ft_strlen(dest))
		value = ft_strlen(src) + dstsize;
	else
		value = ft_strlen(src) + ft_strlen(dest);
	idx = 0;
	while (dest[idx] != '\0')
		idx++;
	src_idx = 0;
	while (src[src_idx] != '\0' && idx + 1 < dstsize)
	{
		dest[idx] = src[src_idx];
		src_idx++;
		idx++;
	}
	dest[idx] = '\0';
	return (value);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		len;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
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
<<<<<<< HEAD
	int	i;
	
	i = ft_strlen(s) + 1;
	if (!s)
		return (NULL);
	while (i--)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	return (0);
}

=======
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
>>>>>>> 96bd0bc3af999586baf9a801afcd39637ec4b558

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(sizeof(char) * len);

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, len);
	ft_strlcpy(new + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (new);
}
<<<<<<< HEAD


=======
>>>>>>> 96bd0bc3af999586baf9a801afcd39637ec4b558
