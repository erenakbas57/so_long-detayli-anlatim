/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:41:07 by makbas            #+#    #+#             */
/*   Updated: 2022/12/27 17:53:36 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	iç içe while döngüsü ile haritanın her karakterine gireceğiz
	uzunluk referansı ilk satırın uzunluğuna göre olacak.
	uzunluğun içinde '\n' karaktteri de olduğu için "len - 1"e eşitse
	satır sayısını arttırıp diğer satırı kontrol edecek.
	eğer diğer satırlardan biri ilk satırın uzunluğuna eşit değilse
	hata döndürecek
*/
int	rectangle_c(t_map *map)
{
	int	y;
	int	x;
	int	len;

	len = ft_strlen(map->map_line[0]);	// ilk satırın uzunluğunu aldık
	y = 0;	// satır indeksi
	while (y < map->map_y_line)
	{
		x = 0; //satırdaki elemanın indeksi
		while (map->map_line[y] && map->map_line[y][x] != '\n' && \
			x < (int)(ft_strlen(map->map_line[y])))	// x, len'den küçükse ve '\n'a eşit değilse 
			x++;	// x artacak
		if (x != len -1)	// hata durumu : eğer ilk satır uzunluğuna eşit değilse hata dönecek
		{
			ft_printf("HATA : %d. satırda dikdörtgen hatası!", y + 1); // y indeks olduğu için y+1. satır yazdık
			return (1);
		}
		y++;	// satırda hata yoksa y artacak ve diğer satır kontrol edilecek
	}
	return (0);
}

/*
	oyuncudan aldığımız x ve y konumlarını burada kulanacağız
	oyuncunun hareket edebildiği yerleri anlamak için recursive fonksiyon
	kullandım. 
	gidebildiği yerler P olacak ve çıkış ya da collectible'a ulaşamazsa hata verecek
*/
int	valid_c(t_map *map)
{
	recursive_p(map, map->p_y_loc, map->p_x_loc);	// haritayı , x ve y konumlarını yolladık
	if (coin_c(map) || exit_c(map)) // çıkışa ve toplanabilir eşyaya ulaşabiliyor mu kontrolü yapıyoruz.
		return (1);	// buradan önceki fonksiyona 1 yollayıp if'içine girip hata verecek
	return (0);
}

/*
	oyuncunun x+1, x-1, y+1 ve y-1 taraflarına gidebildiğini sırasıyla kontrol ediyoruz.
	eğer gidebiliyorsa (yani orası 0 ya da C ise) orayı P'ye eşitliyoruz.
	tekrar recursive fonksiyona  yeni konumunu yolluyoruz ve yeni tekrardan çalışıyor.
	------------------------
	oyuncunun gidebildiği (0 ve C) yerler P ile değişti.
*/
void	recursive_p(t_map *map, int y, int x)
{
	if (map->map_line[y][x + 1] == '0' || map->map_line[y][x + 1] == 'C')
	{
		map->map_line[y][x + 1] = 'P';	// eğer gidebiliyorsa orası P olacak
		recursive_p(map, y, x + 1);		// ve fonksiyonu gidebildiği yerden tekrar çalıştırak
	}
	if (map->map_line[y][x - 1] == '0' || map->map_line[y][x - 1] == 'C')
	{
		map->map_line[y][x - 1] = 'P';	// eğer gidebiliyorsa orası P olacak
		recursive_p(map, y, x - 1);		// ve fonksiyonu gidebildiği yerden tekrar çalıştırak
	}
	if (map->map_line[y + 1][x] == '0' || map->map_line[y + 1][x] == 'C')
	{
		map->map_line[y + 1][x] = 'P';	// eğer gidebiliyorsa orası P olacak
		recursive_p(map, y + 1, x);		// ve fonksiyonu gidebildiği yerden tekrar çalıştırak
	}
	if (map->map_line[y - 1][x] == '0' || map->map_line[y - 1][x] == 'C')
	{
		map->map_line[y - 1][x] = 'P';	// eğer gidebiliyorsa orası P olacak
		recursive_p(map, y - 1, x);		// ve fonksiyonu gidebildiği yerden tekrar çalıştırak
	}
}

/*
	haritada C varsa orayı da gidilebilecek yer yapıp P ile değştirmiştik
	haritayı iç içe while ile dönüp eğer C görürsek oraya duvarlardan dolayı
	gidemediği için coin hatası verecek
*/
int	coin_c(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x] != 0 && map->map_line[y][x] != '\n')
		{
			if (map->map_line[y][x] == 'C')	// C ye eşit yer görürse hata verecek
			{
				ft_printf("HATA : Oyuncu toplanabilir eşyaya ulaşamıyor!");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
	oyuncunun çıkışa ulaşabilmesi için tek yol var.
	oyuncunun gidebildiği her kare P olduğu için
	eğer E harfinin dört yanından birinde P harfi varsa
	oyuncu çıkışa ulaşabiliyor demektir.
*/
int	exit_c(t_map *map)
{
	int	y;
	int	x;

	y = map->e_y_loc;	// E'nin x+1, x-1
	x = map->e_x_loc;	// y+1, y-1 çevresini P'ye eşit mi diye kontrol ettik.
	if (map->map_line[y][x + 1] == 'P' || map->map_line[y][x - 1] == 'P' || \
			map->map_line[y + 1][x] == 'P' || map->map_line[y - 1][x] == 'P')
		return (0);	// eşitse 0 olup if'e girmeyecek
	ft_printf("HATA : Oyuncu çıkışa ulaşamıyor!");	// hata mesajı verecek
	return (1);	// if'e girecek
}
