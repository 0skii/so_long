/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:44:53 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/05/13 13:26:31 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	destroy(t_address *mlx)
{
	mlx_destroy_display(mlx->mlx_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->mlx_ptr);
	return (0);
}

int	end(t_address *mlx)
{
	destroy(mlx);
	printf("GG!\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	esc(int keycode, t_address *mlx)
{
	if (mlx && keycode == XK_Escape)
		end(mlx);
	return (0);
}
