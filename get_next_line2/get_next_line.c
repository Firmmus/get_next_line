/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarcon <falarcon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:31:32 by falarcon          #+#    #+#             */
/*   Updated: 2023/03/07 12:19:13 by falarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_search_line(buffer);
	buffer = ft_updatebuffer(buffer);
	return (line);
}

char	*ft_read_buffer(int fd, char *buff)
{
	char	*str;
	int		bytes_read;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && ft_strchr(buff, '\n') == 0)
	{
		bytes_read = read(fd, str, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(str);
			return (NULL);
		}
		str[bytes_read] = '\0';
		buff = ft_strjoin(buff, str);
	}
	free(str);
	return (buff);
}

char	*ft_search_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	line = (char *) malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_updatebuffer(char *buff)
{
	char	*upbuff;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	upbuff = (char *) malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!upbuff)
		return (NULL);
	i++;
	while (buff[i] != '\0')
		upbuff[x++] = buff[i++];
	upbuff[x] = '\0';
	free(buff);
	return (upbuff);
}
