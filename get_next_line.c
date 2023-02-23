* ************************************************************************** */
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

#include "get_next_line.h"

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


