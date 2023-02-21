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

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 32

char *get_next_line(int fd);

int main()
{
    char *line = NULL;
    while ((line = get_next_line(STDIN_FILENO)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    if (line == NULL) {
        printf("Fin de la entrada o error de lectura.\n");
    }

    return 0;
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int buffer_pos = 0;
    static int bytes_in_buffer = 0;
    char *line = NULL;
    int line_pos = 0;
    int read_bytes = 0;
    int end_of_file = 0;

    while (!end_of_file) {
        // Si el buffer está vacío, lee del archivo
        if (buffer_pos >= bytes_in_buffer) {
            read_bytes = read(fd, buffer, BUFFER_SIZE);
            if (read_bytes <= 0) {
                end_of_file = 1;
                if (line_pos == 0) {
                    return NULL; // No se ha leído nada, devolver NULL
                }
                break; // Se ha leído una línea, salir del bucle
            }
            buffer_pos = 0;
            bytes_in_buffer = read_bytes;
        }

        // Busca el siguiente '\n' en el buffer
        while (buffer_pos < bytes_in_buffer) {
            if (buffer[buffer_pos] == '\n') {
                end_of_file = 1;
                break;
            }
            buffer_pos++;
        }

        // Copia la línea actual en el buffer a la línea que se devuelve
        int line_length = line_pos + buffer_pos;
        line = realloc(line, line_length + 1);
        for (int i = line_pos; i < line_length; i++) {
            line[i] = buffer[i - line_pos];
        }
        line_pos = line_length;

        // Si se ha encontrado un '\n', salir del bucle
        if (end_of_file) {
            buffer_pos++; // Avanzar el puntero del buffer más allá del '\n'
            break;
        }
    }

    line[line_pos] = '\0'; // Terminar la línea con el caracter nulo

    return line;
}


