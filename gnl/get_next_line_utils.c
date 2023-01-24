/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:02:05 by makbas            #+#    #+#             */
/*   Updated: 2022/12/27 14:49:03 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gstrlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_gstrchr(char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_gstrlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_gstrjoin(char *str, char *buff)
{
	size_t	c;
	size_t	i;
	char	*new_str;

	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	new_str = malloc(sizeof(char) * ((ft_gstrlen(str)) + ft_gstrlen(buff) + 1));
	if (new_str == NULL)
		return (NULL);
	c = -1;
	i = 0;
	if (str)
		while (str[++c] != '\0')
			new_str[c] = str[c];
	while (buff[i] != '\0')
		new_str[c++] = buff[i++];
	new_str[c] = '\0';
	free(str);
	return (new_str);
}
