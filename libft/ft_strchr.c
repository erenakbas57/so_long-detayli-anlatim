/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:10:12 by makbas            #+#    #+#             */
/*   Updated: 2022/12/27 17:33:13 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)	// karakter null değil ve "01CEP" ilk karakterine eşit değilse indeks arttıracak
		s++;	//diğerine bakmış olacak
	if (*s == (char)c)	// karakter "01CEP" birine eşitse while'a girmeyip bize karakterin ascii değerini yollayavcak
		return ((char *)s);	// ve if içine girmiş olacak
	return (0);	// eşit değilse if içine girmeyip x artmayacak ve else e girip hata verecek
}
