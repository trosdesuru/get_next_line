/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:02:12 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/08 12:47:17 by edhernan         ###   ########.fr       */
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
	if (!buffer || buffer && (!ft_strchr(buffer, '\n')))
		buffer = beefreader(fd, buffer);
	if (!buffer)
		return (NULL);
	line = line_up(buffer);
	if (!line)
		return (free(&buffer));
	buffer = liberty_bytes(buffer);
	return (line);
}

static char	beefreader(int fd, char *buffer)
{
	char	*line;
	int		beefs_read;

	bytes_read = 1;
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (liberty_beats(&buffer));
	while (beefs_read > 0 && !ft_strchr(buffer, '\n'))
		return (buffer);
}

char	line_up(void)
{
}

static char	liberty_bytes(char *buf)
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
