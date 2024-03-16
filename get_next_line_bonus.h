/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:53:23 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/16 21:53:29 by edhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

char		*get_next_line(int fd);
char		*beefreader(int fd, char *buffer);
char		*line_up(char *buffer);
char		*next_line(char *buffer);
int			ft_strlen(const char *str);
char		*ft_strjoin(char *strdest, char *strjoin);
int			ft_strchr(const char *str, int c);
char		*ft_free(char *buffer, char *buf);
char		*ft_read_file(int fd, char *res);
char		*ft_next_line(char *buffer);

#endif
