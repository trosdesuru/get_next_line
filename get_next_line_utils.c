/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:15:20 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/16 12:37:02 by edhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_empty_file(char *buff)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strlen(buff);
	if (!buff || len <= 0)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * len + 1);
	if (!temp)
		return (NULL);
	while (i < len)
	{
		temp[i] = buff[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char *strdest, char *strjoin)
{
	char	*strline;
	size_t	i;
	size_t	j;


	if (!strdest)
	{
		return (ft_empty_file(strjoin));
	}
	strline = (char *)malloc(ft_strlen(strdest) + ft_strlen(strjoin) + 1);
	if (!strline)
	{
		return (get_next_free((char **)&strdest));
	}
	i = 0;
	while (strdest[i])
	{
		strline[i] = strdest[i];
		i++;
	}
	j = 0;
	while (strjoin[j] != '\0')
	{
		strline[i++] = strjoin[j++];
		//j++;
	}
//	write(1, "q", 1);
	strline[i] = '\0';
	free(strdest);
	return (strline);
}

char	*get_next_free(char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

char	*ft_free(char *buffer, char *buf)
{
	if (buffer)
		free(buffer);
	buffer = NULL;
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	return (NULL);
}
/*
int	main(void) //Function string character(ft_strchr) TEST.
{
	char	*str;
	char	c;

	c = '\n';
	str = ft_strchr("My \n name is \n Edu", '\n');
	printf("Busca el caracter = %s\n"ft_strchr(str, c));
	return (0);
}*/
