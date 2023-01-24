/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:18:00 by makbas            #+#    #+#             */
/*   Updated: 2022/12/27 17:25:03 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	duvar kontrolünde ilk ve son satır tamamen 1
	arada kalan tüm satırların 1. ve sonuncu indeksinin
	1 olması isteniyor.
*/
int	wall_c(t_map *map)
{
	int	y;
	int	value;
	int	value2;

	y = 0;	// 0. indeksten başlayacağız
	value = wall_f_e(map, y);	// ilk ve son satır aynı olduğu için beraber kontrol ediyoruz
	if (value != 0)	// hata varsa geriye 1 ya da son satırın sayısı dönecek (value değişkeni)
	{
		ft_printf("HATA : %d. satırda duvar hatası!", value); // value. satırda hata var diyecek
		return (1);
	}
	y = 1;	// ortahat 1. indeksten başladığı için 1 verdik
	value2 = wall_middle(map, y);	// orta satır kontrolüne yolladık int dönecek
	if (value2 != 0)	// hata varsa bize satır sayısını yolluyordu. hata varsa if'e girecek
	{
		ft_printf("HATA : %d. satırda duvar hatası!", value2);	// value2. satırda hata var mesajı yollayıp fonksiyondan çıkacak
		return (1);
	}
	return (0);
}

/*
	ilk ve son satırın kontrolünü aynı anda gerçekleştiriyoruz.
	iç içe while döngüsünde dönerken 1. ve sonuncu satır kontrolünü 
	aynı anda yapıp hata varsa geri hata yolluyoruz
*/
int	wall_f_e(t_map *map, int y)
{
	int	x;
	int	len;

	len = map->map_y_line - 1;	// satır sayısı - 1 bize son satırın indeksini verecek 
	if (y == 0 || y == (len))
	{
		x = 0;	// satırın 0. indeksinden kontrol başlıyor
		while (map->map_line[y][x] != '\n')	// \n olana kadar satırı dönecek
		{
			if (map->map_line[0][x] != '1') // 0. satırın x. indeksinde hata varsa
				return (1);	// geriye 1 dönecek ve mesajda 1. satırda hata var yazdıracağız
			if (map->map_line[len][x] != '1')	// sonuncu satırın x. indeksinde hata varsa
				return (len + 1);	// len + 1 yollayacağız. len+1. satırda hata var demek için
			x++;
		}
	}
	return (0);
}

/*
	orta satırların 1. ve sonuncu elemanı "1" olması gerekiyor
*/
int	wall_middle(t_map *map, int y)
{
	int	line_len;

	line_len = ft_strlen(map->map_line[0]) - 2;	// satırın son elemanını aldık
	while (map->map_line[y] != 0)	// son satırı da kontrol etmiş olacak ama fazladan değişken olmaması için böyle kullandım
	{
		if (map->map_line[y][0] != '1' || map->map_line[y][line_len] != '1') // eğer y. satırın 1. indeksi ya da y. satırın len. indeksi 1 değilse
			return (y + 1);	// geriye y+1 dönecek. satır numarası indeksten 1 fazla olduğu için. hata mesajına yollaycak
		y++;	//satırda hata yoksa satır sayısını arttıracak
	}
	return (0);
}
