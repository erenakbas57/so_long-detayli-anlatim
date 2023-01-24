/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:26:05 by makbas            #+#    #+#             */
/*   Updated: 2022/12/27 18:01:43 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAP_CHAR "01CEP"

typedef struct s_map
{
	void	*img_p;
	void	*img_w;
	void	*img_e;
	void	*img_b;
	void	*img_c;
	char	**map_line;
	int		p_x_loc;
	int		p_y_loc;
	int		e_x_loc;
	int		e_y_loc;
	int		e_count;
	int		p_count;
	int		c_count;
	int		p_move_c;
	int		map_y_line;
	char	*f_name;
	void	*mlx;
	void	*mlx_win;
}				t_map;

int		file_control(int argc, char *argv);
int		map_read_c(t_map *map, char *f_name);
int		map_read_control(t_map *map, char *f_name);
void	map_read(t_map *map, char *f_name);
int		map_control(t_map *map);
int		rectangle_c(t_map *map);
void	char_control(t_map *map, int x, int y);
int		char_c(t_map *map);
int		wall_c(t_map *map);
int		wall_f_e(t_map *map, int y);
int		wall_middle(t_map *map, int y);
int		element_c(t_map *map);
void	free_map(t_map *map);
void	recursive_p(t_map *map, int y, int x);
int		valid_c(t_map *map);
int		coin_c(t_map *map);
int		exit_c(t_map *map);
int		map_init(t_map *map, char	*argc);
int		create_xpm(t_map *map);
int		win_put_img(t_map *map);
void	ft_put(t_map *map, void *img, int x, int y);
int		ft_exit(t_map *map);
int		ft_move(int key, t_map *map);
void	map_move(t_map *map, int x, int y);

#endif
