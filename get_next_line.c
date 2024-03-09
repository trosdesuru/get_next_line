/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:02:12 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/09 22:13:28 by edhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		return (NULL);
	buffer = beefreader(fd, buffer);
	while (buffer && !ft_strchr(buffer, '\n'))
		return (buffer);
	line = line_up(buffer);
	if (!line)
		return (free(&buffer));
	buffer = liberty_bytes(buffer);
	return (line);
}

static char	*beefreader(int fd, char *buffer)
{
	char	*line;
	int		beefs_read;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (liberty_bytes(&line));
	beefs_read = 1;
	while (beefs_read > 0 && !ft_strchr(line, '\n'))
	{
		if (beefs_read < 0)
			return (free(line), ft_free(&buf));
		if (beefs_read = 0 && !buffer)
			return (free(line), NULL);
		beefs_read = read(fd, line, BUFFER_SIZE);
		line[beefs_read] = '\0';
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		buffer = ft_strjoin(buffer, line);
		if (!buf)
			return (free(line), NULL);
	}
	free(line);
	return (buffer);
}

static char	*line_up(void)
{
}

static char	*liberty_bytes(char *buf)
{
}

/*int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("file.txt", O_RDWR);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		printf("[%d] : %s\n", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}*/
