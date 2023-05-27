/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:22:51 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/05/16 11:32:13 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 700

# define WALL_PATH "incs/wall_texture.xpm"
# define BACKGROUND_PATH "incs/grass.xpm"
# define PLAYER_PATH_UP "incs/player_up.xpm"
# define PLAYER_PATH_DOWN "incs/player_down.xpm"
# define PLAYER_PATH_LEFT "incs/player_left.xpm"
# define PLAYER_PATH_RIGHT "incs/player_right.xpm"

# define DESTROY_NOTIFY 17

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../gnl/incs/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <X11/keysym.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int     width;
}			t_data;

typedef struct s_blocks
{
	void	*background;
	void	*player;
	void	*wall;
}			t_blocks;

typedef struct s_address
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img[256];
	
}			t_address;

int				esc(int keycode, t_address *mlx);
int				end(t_address *mlx);
int				destroy(t_address *mlx);
int				paint_background(t_data *img, t_address *mlx);
int				paint_walls(t_data *img, t_address *mlx);
int				paint_walls_2(t_data *img, t_address *mlx);
t_data 			load_img(t_address *mlx, char *path);
unsigned int    get_pixel_img(t_data *img, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			paint_image(t_address *mlx, t_data *img, int x, int y);

#endif