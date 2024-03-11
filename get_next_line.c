/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:02:12 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/11 11:28:19 by edhernan         ###   ########.fr       */
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
		beefs_read = read(fd, line, BUFFER_SIZE);
		if (beefs_read < 0)
			return (free(line), liberty_bytes(&buf));
		if (beefs_read = 0 && !buffer)
			return (free(line), NULL);
		line[beefs_read] = '\0';
		buffer = ft_strjoin(buffer, line);
		if (!buf)
			return (free(line), NULL);
	}
	free(line);
	return (buffer);
}

static char	*line_up(*buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n' || buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL)
	i = 0;
	while (!buffer[i] != '\n' || buffer[i] != '\0')
		i++;
	if (buffer == '\n')
		i++;
	while (buffer != '\n' != buffer != '\0')
	{
		line[i] == buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*liberty_beefs(char *buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' || buffer != '\0')
		i++;
	if (buffer == '\n')
		i++;
	if (!buffer)
		buffer = liberty_beefs(&buffer);
	str = malloc(sizeof(char) * ((ft_strlen(buffer) - i) + 1));
	if (!line)
		return (&buffer);
	while (buffer[i] == '\n' || buffer[i] != '\0')
	{
		str[j] = buffer[i];
		j++;
		i++;
	}
	str[j] = '\0';
	buffer = liberty_beefs(&buffer);
	return (str);
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
