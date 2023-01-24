/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:26:02 by makbas            #+#    #+#             */
/*   Updated: 2022/12/27 17:37:15 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	P, C, E sayısını haritayı dönerek
	eğer gelen karakter aynıysa ilgili değişkeni 
	arttırıyoruz
*/
void	char_control(t_map *map, int x, int y)
{
	map->p_count = 0;	// player sayısı
	map->e_count = 0;	// exit sayısı
	map->c_count = 0;	// clolectible sayısı
	y = 0;	// satır indeksi
	while (map->map_line[y])
	{
		x = 0;	//satır elemanının indeksi
		while (map->map_line[y][x])	//satırda null değerine gelene kadar
		{
			if (map->map_line[y][x] == 'E') // E ye eşitse exit'ı arttır
			{
				map->e_x_loc = x;		// ileride işimize yarayacak 
				map->e_y_loc = y;		//tekrar iç içe döngü kullanmamak için
				map->e_count++;			// değişkenlere atadık
			}
			if (map->map_line[y][x] == 'C') // C ye eşitse collectible arttır
				map->c_count++;
			if (map->map_line[y][x] == 'P') // P ye eşitse player ı arttır
			{
				map->p_y_loc = y;	// oyuncunun x ve y konumlarını da 
				map->p_x_loc = x;	// bir değişkende tutacağız. ileride lazım olacak
				map->p_count++;
			}
			x++;
		}
		y++;
	}
}

/*
	haritadaki P, C, E sayısını kontrol edeceğiz.
	diğer fonksiyona gidip karakterlerin sayısını alacak
	ve bu fonksiyonda sayıları kontrol edip hata mesajlarını 
	gönderip hata döndüreceğiz
*/
int	char_c(t_map *map)
{
	char_control(map, 0, 0);	//kontrol edeceğimiz asıl fonksiyona gönderiyoruz.
	if (map->e_count != 1)	// eğer çıkış sayısı 1'e eşit değilse hata 
	{
		ft_printf("HATA : ÇIKIŞ sayısı 1 değil!");
		return (1);
	}
	if (map->p_count != 1) // oyuncu sayısı 1'e eşit değilse hata
	{
		ft_printf("HATA : OYUNCU sayısı 1 değil!");
		return (1);
	}
	if (map->c_count == 0)	//collectible sayısı en az 1 tane olması lazım. değilse hata
	{
		ft_printf("HATA : TOPLANABİLİR sayısı 0!");
		return (1);
	}
	return (0);
}

/*
	haritada "01CEP" karakterlerinden başka geçersiz karakter olup
	olmadığını kontrol edeceğiz. strchr fonksiyonu ile bunu yaptım
*/
int	element_c(t_map *map)
{
	int	y;
	int	x;

	y = 0;	// satır indeksi
	while (map->map_line[y])
	{
		x = 0; // satırın eleman indeksi
		while (map->map_line[y][x] != '\n' && map->map_line[y][x] != '\0')	// karakter '\0' ya da '\n' değilse döngüye girecek
		{
			if (ft_strchr(MAP_CHAR, map->map_line[y][x])) // kütüphanede MAP_CHAR define ettim "01CEP", karakter bu karakterlerden 
				x++;									  // birine eşitse (yani 0'dan farklı değer) x sayısnı arttıracak
			else	// hata varsa if'e girmeyecek ve else'den hata mesajını yazdıracak
			{
				ft_printf("HATA : %d. satırda '%c' harfi var!", \
					y, map->map_line[y][x]);
				return (1);
			}
		}
		y++;	// \n ya da \0 gelince satır sayısı artacak diğer satırı kontrol edecek
	}
	return (0);
}
