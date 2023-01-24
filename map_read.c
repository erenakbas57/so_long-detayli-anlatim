/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:59:32 by makbas            #+#    #+#             */
/*   Updated: 2022/12/27 18:00:51 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	ilk önce map_read fonksiyonuna gönderiyoruz.
	malloc ile yer açtığımız dizideki elemanlara
	get_next_line ile satırları içine yazacağız
*/
int	map_read_c(t_map *map, char *f_name)
{
	int	fd;
	int	i;

	map_read(map, f_name);	// haritamızın malloc ile satır sayısı kadar yer açtık
	if (!(map->map_line) || map->map_y_line <= 0)	// tekrar kontrol yapıyoruz
	{
		map->map_line = NULL;
		return (1);
	}
	fd = open(f_name, O_RDONLY); // dosyayı tekrardan açtık
	if (fd == -1)	//dosya açılmazsa leak olmaması için free'liyoruz
	{
		free(map->map_line);
		return (1);
	}
	i = 0;
	map->map_line[i] = get_next_line(fd); 
	while (map->map_line[i])
	{
		i++;
		map->map_line[i] = get_next_line(fd);	// yazma işlemini gerçekleştiriyoruz
	}
	close(fd);	// dosyayı kapatıyoruz
	return (0);
}

/*
	buradaki yaptığımız işlem; harita dosyamızı açıyoruz ve
	sayma işlemi yapıyoruz.
	haritamızı diziye (char ** yapısı) aktaracağımız için
	haritanın satır sayısını alacağız ve malloc ile yer açıp
	kontrolleri sağlayacağız 
*/
void	map_read(t_map *map, char *f_name)
{
	int		len;
	int		fd;
	char	c;

	fd = open(f_name, O_RDONLY); // dosyayı açtık
	if (fd < 0)	// hata durum kontrolü
		return ;
	len = 0;	// satır sayısı
	while (read(fd, &c, 1)) // tek tek karakter okuması yapıyoruz
	{
		if (c == '\n') // eğer '\n' a gelirse satır sayısını 1 arttıracak
			len++;
	}
	len++;	// son satırda '\0' ile bittiği için döngü dışında 1 defa daha arttırıyoruz
	close(fd);	// dosya kapama
	map->map_line = malloc(sizeof(char *) * len + 1);	// her satırda string değer olacağı için (char *)
	if (!map->map_line)	// malloc kontrolü
		return ;
	map->map_line[len + 1] = NULL;	//son satıra NULL atıyoruz
	map->map_y_line = len;	// haritanın uzunluğunu değişkende tutuyoruz.
}

/*
	haritanın satırlarını tutan dizi elemanlarını
	free'ledikten sonra diziyi de free'liyoruz
*/
void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_y_line)
	{
		free(map->map_line[i]);
		i++;
	}
	free(map->map_line);
}

/*
	çıkış yaptığımızda mlx kütüphanesinin bize verdiği
	fonksiyon ile resimleri temizliyoruz.
	yine mlx kütüphane fonksiyonu ile ekranı temizliyoruz.
	ve map struct'ını tamamen free'liyoruz.
*/
int	ft_exit(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img_b);
	mlx_destroy_image(map->mlx, map->img_w);
	mlx_destroy_image(map->mlx, map->img_e);
	mlx_destroy_image(map->mlx, map->img_p);
	mlx_destroy_image(map->mlx, map->img_c);
	mlx_clear_window(map->mlx, map->mlx_win);
	free_map(map);
	exit(0);
	return (0);
}
