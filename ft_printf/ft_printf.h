/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:42:29 by makbas            #+#    #+#             */
/*   Updated: 2022/10/31 13:42:29 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_control(char c, va_list list);

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long double number, int base, int dec, char c);
int	ft_pointer(long double number, int base, int dec);

#endif
