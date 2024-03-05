/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:02:12 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/05 11:31:17 by edhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	static char		*line;

	/*
	 * Seteamos line para el input, reservando espacio para NULL con malloc
	 * Proteccion de line, BUFFER_SIZE & fd por si falla, 'return NULL'
	 * */
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if ((fd < 0) || (buffer == NULL) || (BUFFER_SIZE <= 0))
	{
		free(buffer);
		return (NULL);
	}
	/*
	 * Llama a la funcion 'reader' para leer el fd("file.txt")
	 * La ft 'reader' debe leer y copiar la informacion en el 'line'
	 * La ft 'reader' = return (line)
	 *
	 * */
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	//Agregamos el carácter nulo al final para formar una cadena C válida
	buffer[bytes_read] = '\0';
	return (buffer);
}

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
/*
char	reader(void)
{
}

char	line_buffer(void)
{
}
*/
