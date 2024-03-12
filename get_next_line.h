/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:17:33 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/12 09:35:30 by edhernan         ###   ########.fr       */
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

char			*get_next_line(int fd);
char			get_next_free(char **buffer);
static char		*beefreader(int fd, char *bf);
static char		*liberty_buffs(char *buf);
static char		*line_up(char *bfr);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *str, int c);
char			*ft_strjoin(char *strdest, const char *strjoin);

#endif
