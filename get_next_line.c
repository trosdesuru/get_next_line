/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:02:12 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:59:09 by edhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = beefreader(fd, buffer);
	if (!buffer)
		return (NULL);
	line = line_up(buffer);
	if (!line)
		return (get_next_free(&buffer));
	buffer = liberty_buffs(buffer);
	if (!buffer)
		return (NULL);
	return (line);
}

char	*beefreader(int fd, char *buffer)
{
	char	*tmp;
	int		beefs_read;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (get_next_free(&tmp));
	beefs_read = 1;
	while (beefs_read > 0 && !ft_strchr(tmp, '\n'))
	{
		beefs_read = read(fd, tmp, BUFFER_SIZE);
		if (beefs_read < 0)
			return (free(tmp), liberty_buffs(buffer));
		if (beefs_read == 0 && !buffer)
			return (free(tmp), NULL);
		tmp[beefs_read] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (!buffer)
			return (free(tmp), NULL);
	}
	free(tmp);
	return (buffer);
}

char	*line_up(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = buffer[i];
	line[++i] = '\0';
	return (line);
}

char	*liberty_buffs(char *buf)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\n')
		i++;
	if (!buf)
		return (get_next_free(&buf));
	str = malloc(sizeof(char) * ((ft_strlen(buf) - i) + 1));
	if (!str)
		return (get_next_free(&buf));
	while (buf[i] != '\0')
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

/*void	print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
}

int main(void)
{
    int fd;
    char *line;
    int count;

    count = 0;
    fd = open("oneline.txt", O_RDONLY);
	if (fd < 0)
	{
		print_error("No se pudo abrir el archivo");
		return 1;
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		count++;
		printf("[%d] : %s\n", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return 0;
}*/


int main(void)
{
	int fd;
	char *line;
	int count;
	
	count = 0;
	fd = open("oneline.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return 1;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		printf("[%d] : %s", count, line);
		free(line);
	//	line = NULL;
	}
	if (!line)
	{
		count++;
		printf("[%d] : %s", count, line);
	}
	close(fd);
	return 0;
}
