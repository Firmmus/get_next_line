#include "get_next_line.h"

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