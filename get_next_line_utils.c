/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhernan <edhernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:03:55 by edhernan          #+#    #+#             */
/*   Updated: 2024/03/07 18:02:18 by edhernan         ###   ########.fr       */
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
	
	i = 0;
	j = 0;
	if (!strdest && !strjoin)
		return (NULL);

	strdest = malloc((ft_strlen(strdest) +1) * sizeof(char));
	strjoin = malloc((ft_strlen(strjoin) + 1) * sizeof(char));
	strline = malloc(ft_strlen(strdest) + (ft_strlen(strjoin) + 1) * (sizeof(char)));
}

int main (void)
{
	char	*str;

	str = ft_strchr("My \n name is \n Edu", '\n');
	return (0);
}
