/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarcon <falarcon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:28:47 by falarcon          #+#    #+#             */
/*   Updated: 2023/03/02 12:41:21 by falarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_read_buffer(int fd, char *buffer);
char	*ft_search_line(char *buffer);
char	*ft_updatebuffer(char *buffer);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t len);
char	*ft_strjoin(char *s1, char *s2);
<<<<<<< HEAD
char	*ft_strchr(const char *s, int c);
=======
char	*ft_strchr(char *s, int c);
>>>>>>> 96bd0bc3af999586baf9a801afcd39637ec4b558

#endif
