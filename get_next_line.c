/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:02:12 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/06 15:45:24 by edhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer = NULL;
	char			*line;
	/* 
	 * Declaramos el puntero de char *buffer a NULL.
	 * En cada llamada de buffer se inicie en el valor de NULL. 
	 * Declaramos *line, es el return value de la funcion 'get_next_line.c'.
	 * Primera condicion dentro de la funcion 'if' para asegurar la
	 * proteccion de 'fd' & 'BUFFER_SIZE'.
	 */
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	/*
	 * La siguiente condicion: si no existe buffer o no hay un salto de
	 * linea en buffer, sigues leyendo el 'fd'.
	 * Llama a la funcion 'reader' para leer el fd, "file.txt" en mi caso.
	 */
	if (!buffer || buffer && (!ft_strchr(buffer, '\n')))
		buffer = reader(fd, buffer);
	/*
	 * Proteccion de buffer.
	 */
	if (!buffer)
		return (NULL);
	/*
	 *
	 */
	line = line_up(buffer);
	if (!line)
		return = (free(&buffer));
	buffer = cleaner(buffer);
	return (line);
}
/*
int	main(void)
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
*/
char	reader(int fd, char *line)
{
	char	*buffer;
	int		bytes_read;

	buffer = ((char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			 return (NULL);
		buffer[bytes_read] = '\0';
		/*
		 */
		line = line_up(buffer, line);
	}
	return (line);
}

char	line_up(void)
{
}
