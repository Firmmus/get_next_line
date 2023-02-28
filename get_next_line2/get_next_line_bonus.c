#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 4096)
		return (NULL);
	buffer[fd] = ft_read_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_search_line(buffer[fd]);
	buffer[fd] = ft_updatebuffer(buffer[fd]);
	return (line);
}

char	*ft_read_buffer(int fd, char *buff)
{
	char	*str;
	ssize_t	bytes_read;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && ft_strchr(buff, '\n') == 0)
	{
		bytes_read = read(fd, str, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(str);
			free(buff);
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
	while (buff[i] && buff[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, buff, i + 1);
	if (buff[i] == '\n')
		line[i] = buff[i];
	i++;
	line[i] = '\0';
	return (line);
}

char	*ft_updatebuffer(char *buff)
{
	char	*newbuff;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	newbuff = (char *)malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!newbuff)
		return (NULL);
	i++;
	while (buff[i])
		newbuff[x++] = buff[i++];
	newbuff[x] = '\0';
	free(buff);
	return (newbuff);
}

