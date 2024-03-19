/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:53:30 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/19 09:53:39 by edhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

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
	int		i;
	int		j;

	if (!strdest)
		return (ft_empty_file(strjoin));
	strline = (char *)malloc(sizeof(char) * ft_strlen(strdest)
			+ ft_strlen(strjoin) + 1);
	if (!strline)
		return (ft_free(strdest, 0));
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
	}
	strline[i] = '\0';
	free(strdest);
	return (strline);
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
