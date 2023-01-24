/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:07:19 by makbas            #+#    #+#             */
/*   Updated: 2022/12/27 18:07:29 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	struct yapısında tuttuğumuz değişkenlere
	mlx kütüphanesindeki xpm_file_to_image fonksiyonu ile
	resimin konumunu ve x, y değerleri yolladık.
	x ve y değerlerinin adresini yolladık çünkü diğer fonksşyonda
	resimleri gerekli yerlere işlerken 0'dan başlamasını sağlattık
	ve fonksiyon bu değeri kabul ediyor
*/
int	create_xpm(t_map *map)
{
	int	x;
	int	y;

	map->img_e = mlx_xpm_file_to_image(map->mlx, "./img/exit.xpm", &x, &y);
	map->img_c = mlx_xpm_file_to_image(map->mlx, "./img/coin.xpm", &x, &y);
	map->img_w = mlx_xpm_file_to_image(map->mlx, "./img/wall.xpm", &x, &y);
	map->img_p = mlx_xpm_file_to_image(map->mlx, "./img/player.xpm", &x, &y);
	map->img_b = mlx_xpm_file_to_image(map->mlx, "./img/back.xpm", &x, &y);
	if (!map->img_b || !map->img_c || !map->img_e || !map->img_p || !map->img_w)
		return (1);
	return (0);
}

/*
	gerekli karakterler eşleşince ilgili resmio pencere
	yerine işleyecek ve penceremizi oluşturacak
*/
int	win_put_img(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map_line[y][x])
	{
		if (map->map_line[y] && map->map_line[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		if (map->map_line[y][x] == 'E')	
			ft_put(map, map->img_e, x, y);
		if (map->map_line[y][x] == 'C')
			ft_put(map, map->img_c, x, y);
		if (map->map_line[y][x] == 'P')
			ft_put(map, map->img_p, map->p_x_loc, map->p_y_loc);
		if (map->map_line[y][x] == '0')
			ft_put(map, map->img_b, x, y);
		if (map->map_line[y][x] == '1')
			ft_put(map, map->img_w, x, y);
		x++;
	}
	return (0);
}

/*
	mlx kütüphanesindeki fonksiyon ile ekrana resimleri işleme
	fonksyiuonunu yazdık. diğer fonksiyon uzun olduğu için tekrar
	fonksiyon yazmam gerekti
*/
void	ft_put(t_map *map, void *img, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, 64 * x, 64 * y);
}

/*
	tuşlardan biirne dokunulduğunda pencereyi clear ediyoruz
	map_move fonksyonuna gidiyor orada işlemler yaplınıca 
	ekran tekrar yeni değerler yahut aynı değerler ile işleniyor
	hareket sayısı ekrana işleniyor
*/
int	ft_move(int key, t_map *map)
{
	int		x;
	int		y;
	char	*move;

	x = map->p_x_loc;
	y = map->p_y_loc;
	if (key == 13)	// s tuşu
		y--;
	else if (key == 1)	// w tuşu
		y++;
	else if (key == 2)	// d tuşu
		x++;
	else if (key == 0)	// a tuşu
		x--;
	else if (key == 53)	// esc tuşu
		ft_exit(map);	// uygulama kapanacağı için free'leme işlemlerini yapıyor
	else
		return (0);
	mlx_clear_window(map->mlx, map->mlx_win);	// ekran temizleniyor
	map_move(map, x, y);	// yeni map oluşturmak için fonksiyona gidiyor.
	win_put_img(map);	// harita değişse de değişmese de tekrardan oluşturulacak
	move = ft_itoa(map->p_move_c);	// hareket sayısı tür dönüşümü yapılacak
	mlx_string_put(map->mlx, map->mlx_win, 15, 15, 16777215, move);	// ekranın aynı kısmına değer gönderilecek
	free(move);	// free'leme yapmazsak leaks olur
	return (0);
}

/*
	! eğer tuşa basılıp oyuncu hareket etmezse hareket sayısı değişmeyecek
*/
void	map_move(t_map *map, int x, int y)
{
	if (map->map_line[y][x] != '1' && map->map_line[y][x] != 'E') // yani hareket edebilirse
	{
		ft_printf("hareket sayısı : %d\n", ++map->p_move_c); // hareket sayısını arttırıp ekrana yazdı
		if (map->map_line[y][x] == 'C')	// eğer hareket ettiği yer C ise 
			map->c_count--;		// 'C'nin sayısını azalt
		map->map_line[map->p_y_loc][map->p_x_loc] = '0'; // oyuncunun önceki konumunu 0 yap
		map->map_line[y][x] = 'P';	// yeni konumunu P yap
		map->p_y_loc = y;	//yeni konumunun x ve y değerlerini değişkene eşitle
		map->p_x_loc = x;
	}
	else if (map->map_line[y][x] == 'E' && map->c_count == 0)	// eğer gittiği yer E'ye eşitse ve C sayısı 0 kaldıysa girecek
	{
		ft_printf("hareket sayısı : %d\n", ++map->p_move_c);	// hareket sayısını arttıracak
		ft_exit(map);	// haritayı free'leyecek
	}
}
