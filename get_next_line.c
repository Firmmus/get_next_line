/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarcon <falarcon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:58:29 by falarcon          #+#    #+#             */
/*   Updated: 2023/02/15 10:58:29 by falarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 42

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void    *ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*read_next_line(int fd, char *buffer, char **line, int *bytes_read);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*new_line_ptr;
	int			bytes_read;

	line = ft_strdup("");
	if (!line)
		return (NULL);
	new_line_ptr = ft_strchr(buffer, '\n');
	while (new_line_ptr == NULL)
	{
		line = read_next_line(fd, buffer, &line, &bytes_read);
		if (!line || bytes_read <= 0)
			break ;
		new_line_ptr = ft_strchr(buffer, '\n');
	}
	if (bytes_read < 0 || !line)
	{
		free(line);
		return (NULL);
	}
	if (new_line_ptr == NULL && buffer[0] != '\0')
	{
		line = ft_strjoin(line, buffer);
		buffer[0] = '\0';
	}
	else if (new_line_ptr != NULL)
	{
		*new_line_ptr = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		new_line_ptr++;
		ft_memcpy(buffer, new_line_ptr, ft_strlen(new_line_ptr) + 1);
	}
	else
	{
		free(line);
		line = NULL;
	}
	return (line);
}

size_t	ft_strlen(const char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		idx++;
	}
	return (idx);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		idx;

	idx = 0;
	if (dest == src || !n)
		return (dest);
	while (idx < n)
	{
		*((char *)dest + idx) = *((char *)src + idx);
		idx++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, s1_len);
	ft_memcpy(new_str + s1_len, s2, s2_len);
	new_str[s1_len + s2_len] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s1, len);
	copy[len] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*read_next_line(int fd, char *buffer, char **line, int *bytes_read)
{
	char	*new_line_ptr;
	char	*temp;

	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read <= 0)
		return (NULL);
	buffer[*bytes_read] = '\0';
	new_line_ptr = ft_strchr(buffer, '\n');
	if (new_line_ptr != NULL)
	{
		*new_line_ptr = '\0';
		*line = ft_strjoin(*line, buffer);
		temp = ft_strdup(new_line_ptr + 1);
		ft_memcpy(buffer, temp, ft_strlen(temp) + 1);
		free(temp);
	}
	else
	{
		*line = ft_strjoin(*line, buffer);
		buffer[0] = '\0';
	}
	if (*line == NULL)
		return (NULL);
	return (*line);
}

