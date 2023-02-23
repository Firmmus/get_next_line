# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_buffer(int fd, char *buffer);
char	*ft_search_line(char *buffer);
char	*ft_updatebuffer(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t len);
size_t	ft_strlcat(char *dest, const char *src, size_t len);

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
	int		cread;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	cread = 1;
	while (cread != 0 && ft_strchr(buff, '\n') == 0)
	{
		cread = read(fd, str, BUFFER_SIZE);
		if (cread == -1)
		{
			free(str);
			return (NULL);
		}
		str[cread] = '\0';
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		len;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, len);
	ft_strlcpy(new + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (len > 0)
	{
		i = 0;
		while (src[i] != '\0' && i < (len - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_size);
}

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	if (len <= ft_strlen(dest))
		return (ft_strlen(src) + len);
	while (src[j] && i + 1 < len)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (i + ft_strlen(&src[j]));
}


