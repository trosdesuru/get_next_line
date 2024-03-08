/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:15:20 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/08 16:56:47 by edhernan         ###   ########.fr       */
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

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while ((str[i] != (char)c) && (str[i] != '\0'))
		i++;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *strdest, const char *strjoin)
{
	char	*strline;
	size_t	i;
	size_t	j;
	
	strline = malloc(ft_strlen(strdest) + ft_strlen(strjoin) + 1);
	if (!strdest && !strjoin)
		return (NULL);
	i = 0;
	while (strdest[i])
	{
		strline[i] = strdest[i];
		i++;
	}
	j = 0;
	while (strjoin[j])
	{
		strline[i + j] = strjoin[j];
		j++;
	}
	strline[i + j] = '\0';
	free(strdest);
	return (strline);
}

int main (void) //Function string character(ft_strchr) TEST.
{
	char	*str;
	char	c;

	c = '\n';
	str = ft_strchr("My \n name is \n Edu", '\n');
	printf("Busca el caracter = %s\n"ft_strchr(str, c))
	return (0);
}
