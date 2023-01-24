/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:15:17 by makbas            #+#    #+#             */
/*   Updated: 2022/10/28 19:15:17 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!(str))
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*str)
	{
		write(1, str, 1);
		count++;
		str++;
	}
	return (count);
}

int	ft_putnbr(long double number, int base, int dec, char c)
{
	int		count;
	char	*lower;
	char	*upper;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	count = 1;
	if (number < 0)
	{
		count++;
		number = -number;
		if (c != 'u')
			write(1, "-", 1);
	}
	if (number >= base)
		count += ft_putnbr(number / base, base, dec, c);
	if (dec == 1)
		write(1, &upper[(unsigned long)number % base], 1);
	else if (dec == 0)
		write(1, &lower[(unsigned long)number % base], 1);
	return (count);
}

int	ft_pointer(long double number, int base, int dec)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr(number, base, dec, 'p');
	return (count);
}
