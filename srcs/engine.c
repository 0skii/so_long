/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:02:36 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/05/16 15:42:55 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

unsigned int    get_pixel_img(t_data *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (y * img->line_length) + \
	(x * img->bits_per_pixel / 8))));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (color != 0xFF000000)
	{	
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	paint_image(t_address *mlx, t_data *img, int x, int y)
{
	int sx;
	int sy;

	sy = -1;
	while (++sy < img->height)
	{
		sx = -1;
		while (++sx < img->width)
		{
			my_mlx_pixel_put(&mlx->img[0], sx + x, sy + y, get_pixel_img(img, sx, sy));
		}
	}
}

t_data load_img(t_address *mlx, char *path)
{
	t_data img;
	
	if (path)
	{
		img.img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, \
		&img.width, &img.height);
	}
	else
	{	
		img.img = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
		img.width = WINDOW_WIDTH;
		img.height = WINDOW_HEIGHT;
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	return (img);
}