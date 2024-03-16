/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:53:51 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/16 21:54:10 by edhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		*buffer[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (ft_free(buffer[fd], 0));
	line = line_up(buffer[fd]);
	if (!line)
	{
		buffer[fd] = ft_free(buffer[fd], 0);
		return (NULL);
	}
	buffer[fd] = ft_next_line(buffer[fd]);
	return (line);
}

char	*beefreader(int fd, char *buffer)
{
	char	*tmp;
	int		beefs_read;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (ft_free(buffer, 0));
	beefs_read = 1;
	while (beefs_read > 0 && (ft_strchr(buffer, '\n') != 0))
	{
		beefs_read = read(fd, tmp, BUFFER_SIZE);
		if (beefs_read == -1)
			return (ft_free(buffer, tmp));
		if (beefs_read > 0)
		{
			tmp[beefs_read] = 0;
			buffer = ft_strjoin(buffer, tmp);
			if (!buffer)
				return (ft_free(buffer, tmp));
		}
	}
	free(tmp);
	return (buffer);
}

char	*ft_read_file(int fd, char *res)
{
	int		byte_read;
	char	*buffer;

	byte_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buffer)
		return (ft_free(res, 0));
	while (byte_read > 0 && (ft_strchr(res, '\n') != 0))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (ft_free(res, buffer));
		if (byte_read > 0)
		{
			buffer[byte_read] = 0;
			res = ft_strjoin(res, buffer);
			if (!res)
				return (ft_free(res, buffer));
		}
	}
	free(buffer);
	return (res);
}

char	*line_up(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] && buffer[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_next_line(char *buffer)
{
	int		i;
	char	*next_line;
	int		j;
	int		cant;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	cant = ft_strlen(buffer + i);
	if (cant == 0)
		return (ft_free(buffer, 0));
	next_line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i) + 1);
	if (next_line == NULL)
		return (ft_free(buffer, 0));
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	return (next_line);
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
}*/
