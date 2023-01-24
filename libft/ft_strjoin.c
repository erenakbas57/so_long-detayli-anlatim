/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:10:20 by makbas            #+#    #+#             */
/*   Updated: 2022/10/11 16:10:21 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s;
	char	*join;

	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	s = 0;
	if (!join)
		return (0);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[s] != '\0')
	{
		join[i] = s2[s];
		s++;
		i++;
	}
	join[i] = '\0';
	return (join);
}
