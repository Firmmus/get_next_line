/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarcon <falarcon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:04:42 by falarcon          #+#    #+#             */
/*   Updated: 2023/03/02 11:33:07 by falarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = ft_strdup("");
	if (!line)
		return (NULL);
	bytes_read = ft_read_file(fd, buffer, &line);
	if (bytes_read < 0 || !line)
	{
		free(line);
		return (NULL);
	}
	if (bytes_read == 0 && buffer[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	ft_read_file(int fd, char *buffer, char **line)
{	
	char	*new_line_ptr;
	int		bytes_read;

	new_line_ptr = ft_strchr(buffer, '\n');
	while (new_line_ptr == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		*line = ft_strjoin(*line, buffer);
		new_line_ptr = ft_strchr(buffer, '\n');
	}
	if (new_line_ptr != NULL)
	{
		*new_line_ptr = '\0';
		*line = ft_strjoin(*line, buffer);
		if (!*line)
			return (-1);
		new_line_ptr++;
		ft_memcpy(buffer, new_line_ptr, ft_strlen(new_line_ptr) + 1);
	}
	return (bytes_read);
}

char	*ft_read_next_line(int fd, char *buffer, char **line, int *bytes_read)
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
