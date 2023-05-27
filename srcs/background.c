/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:21:55 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/05/13 13:02:41 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	paint_background(t_data *img, t_address *mlx)
{
	int	x;
	int	y;

	x = 100;
	y = 100;
	while (y < 501)
	{
		while (x < 1001)
		{
			paint_image(mlx, &mlx->img['0'], x, y);
			x += 100;
		}
		x = 100;
		y += 100;
	}
	return (0);
}
