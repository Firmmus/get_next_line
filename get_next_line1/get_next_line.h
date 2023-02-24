#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42 
#endif

char	*get_next_line(int fd);
char	*read_next_line(int fd, char *buffer, char **line, int *bytes_read);
int read_file(int fd, char *buffer, char **line);
size_t	ft_strlen(const char *s);
void    *ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

#endif
