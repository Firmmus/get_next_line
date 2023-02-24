#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42 
#endif

void    *ft_realloc(void *ptr, size_t old_size, size_t new_size);
void    *ft_memcpy(void *dest, const void *src, size_t n);
char    *read_buffer(int fd, char *buffer, int *bytes_read, int *buffer_pos);
int find_newline(char *buffer, int buffer_pos, int bytes_read);
char    *create_line(char *line, int *line_length, char *buffer, int buffer_pos);
char    *get_next_line(int fd);

#endif