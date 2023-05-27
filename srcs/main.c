/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:17:36 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/05/16 15:37:34 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int render(t_address	*mlx)
{
	(void) mlx;
	paint_walls(mlx->img, mlx);
	paint_background(mlx->img, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img[0].img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data				img;
	t_blocks			obj;
	static t_address	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, \
	("Thx for all the fish :)"));
	mlx.img[0] = load_img(&mlx, NULL);
	mlx.img['0'] = load_img(&mlx, BACKGROUND_PATH);
	mlx.img['1'] = load_img(&mlx, WALL_PATH);
	mlx_loop_hook(mlx.mlx_ptr, render, &mlx);
	mlx_hook(mlx.win_ptr, DESTROY_NOTIFY, 0, end, &mlx);
	mlx_key_hook(mlx.win_ptr, esc, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
