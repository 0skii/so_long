/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:06:43 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/05/18 11:16:24 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	paint_walls(t_data *img, t_address *mlx)
{
	int	x;
	int	y;
	int	file;
	
	x = 0;
	y = 0;
	while (x < 1101)
	{
		paint_image(mlx, &mlx->img['1'], x, y);
		x += 100;
	}
	x = 0;
	while (y < 601)
	{
		paint_image(mlx, &mlx->img['1'], x, y);
		y += 100;
	}
	paint_walls_2(img, mlx);
	return (0);
}

int	paint_walls_2(t_data *img, t_address *mlx)
{
	int	x;
	int	y;

	x = 1100;
	y = 100;
	while (y < 601)
	{
		paint_image(mlx, &mlx->img['1'], x, y);
		y += 100;
	}
	x = 100;
	y = 600;
	while (x < 1101)
	{
		paint_image(mlx, &mlx->img['1'], x, y);
		x += 100;
	}
	return (0);
}
