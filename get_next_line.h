/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:17:33 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/16 12:08:12 by edhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char		*get_next_line(int fd);
char		*beefreader(int fd, char *buffer);
char		*line_up(char *buffer);
char		*next_line(char *buffer);
char		*liberty_buffs(char *buf);
size_t		ft_strlen(const char *str);
//char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char *strdest, char *strjoin);
char		*get_next_free(char **buffer);
int ft_strchr(const char *str, int c);
char *ft_free(char *buffer, char *buf);
#endif
