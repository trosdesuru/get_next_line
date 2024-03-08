/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:02:12 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/08 11:37:23 by edhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer
	char			*line = NULL;
	/* 
	 * Declaramos el puntero de char *buffer como NULL.
	 * En cada llamada a buffer, se inicia con el valor de NULL.
	 * Declaramos *line, que es el valor de retorno de la función 'get_next_line.c'.
	 * La primera condición dentro de la función 'if' asegura la
	 * protección de 'fd' y 'BUFFER_SIZE'.
	 * */
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	/*
	 * La siguiente condición: si no existe buffer o no hay un salto de
	 * línea en el buffer, continúas leyendo el 'fd'.
	 * Llama a la función 'reader' para leer el fd, "archivo.txt" en mi caso.
	 * */
	if (!buffer || buffer && (!ft_strchr(buffer, '\n')))
		buffer = reader(fd, buffer);
	/*
	 * Protección de buffer.
	 */
	if (!buffer)
		return (NULL);
	/*
	 * La línea recoge la información obtenida de la llamada a la función 
	 * 'line_up' con el buffer como parámetro.
	 * Si buffer no devuelve nada, lo liberamos.
	 */
	line = line_up(buffer);
	if (!line)
		return = (free(&buffer));
	buffer = liberty_city(buffer);
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

static char	liberty_beats(char *buf)
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
