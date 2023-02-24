char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int buffer_pos = 0;
    static int bytes_read = 0;
    char *line = NULL;
    int line_length = 0;
    int newline_pos = -1;

    while (newline_pos == -1)
    {
        if (buffer_pos >= bytes_read)
            if (!(read_buffer(fd, buffer, &bytes_read, &buffer_pos)))
                return (line);
        newline_pos = find_newline(buffer, buffer_pos, bytes_read);
        if (newline_pos == -1)
            if (!(line = create_line(line, &line_length, buffer, bytes_read)))
                return (NULL);
        else
            if (!(line = create_line(line, &line_length, buffer, newline_pos + 1)))
                return (NULL);
        buffer_pos = (newline_pos != -1 ? newline_pos + 1 : buffer_pos);
    }

    return (line);
}

char *read_buffer(int fd, char *buffer, int *bytes_read, int *buffer_pos)
{
    *buffer_pos = 0;
    *bytes_read = read(fd, buffer, BUFFER_SIZE);
    return (bytes_read > 0 ? buffer : NULL);
}

int find_newline(char *buffer, int buffer_pos, int bytes_read)
{
    while (buffer_pos < bytes_read && buffer[buffer_pos] != '\n')
        buffer_pos++;
    return (buffer_pos < bytes_read ? buffer_pos : -1);
}

char *create_line(char *line, int *line_length, char *buffer, int buffer_pos)
{
    char *new_line;
    int len;

    len = (line ? *line_length : 0) + buffer_pos;
    new_line = ft_realloc(line, *line_length, len + 1);
    if (!new_line)
        return (NULL);
    ft_memcpy(new_line + *line_length, buffer, buffer_pos);
    new_line[len] = '\0';
    *line_length = len;
    return (new_line);
}