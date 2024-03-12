/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:02:12 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/12 10:29:45 by edhernan         ###   ########.fr       */
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
		return (get_next_free(&buffer));
	buffer = liberty_buffs(buffer);
	return (line);
}

char	*beefreader(int fd, char *bf)
{
	char	*line;
	int		beefs_read;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (get_next_free(&line));
	beefs_read = 1;
	while (beefs_read > 0 && !ft_strchr(line, '\n'))
	{
		beefs_read = read(fd, line, BUFFER_SIZE);
		if (beefs_read < 0)
			return (free(line), liberty_buffs(bf));
		if (beefs_read == 0 && !bf)
			return (free(line), NULL);
		line[beefs_read] = '\0';
		bf = ft_strjoin(bf, line);
		if (!bf)
			return (free(line), NULL);
	}
	free(line);
	return (bf);
}

char	*line_up(char *bfr)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!bfr || bfr[i] == '\0')
		return (NULL);
	while (bfr[i] != '\n' || bfr[i] != '\0')
		i++;
	if (bfr[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (bfr[i] != '\n' != bfr[i] != '\0')
	{
		line[i] = bfr[i];
		i++;
	}
	if (bfr[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*liberty_buffs(char *buf)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] != '\n' || buf[i] != '\0')
		i++;
	if (buf[i] == '\n')
		i++;
	if (!buf)
		return (get_next_free(&buf));
	str = malloc(sizeof(char) * ((ft_strlen(buf) - i) + 1));
	if (!str)
		return (get_next_free(&buf));
	while (buf[i] == '\n' || buf[i] != '\0')
	{
		str[j] = buf[i];
		j++;
		i++;
	}
	str[j] = '\0';
	get_next_free(&buf);
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