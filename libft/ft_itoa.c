/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:17:07 by makbas            #+#    #+#             */
/*   Updated: 2022/10/19 18:01:38 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	get_len(int n)
{
	long	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	lenght;
	long	value;

	value = n;
	lenght = get_len(value);
	result = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!result)
		return (0);
	result[lenght] = '\0';
	lenght--;
	if (n < 0)
		value = -value;
	while (lenght >= 0)
	{
		result[lenght] = (value % 10) + '0';
		value /= 10;
		lenght--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
