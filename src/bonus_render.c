/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:52:22 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/16 10:28:50 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bonus_render(t_data *data)
{
	set_floor_ceiling(data);
	// bonus_draw_sprites();
	bonus_init_raycasting(data);

	drawMinimap(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, data->mlx.win_img->img, 0, 0);
}

void	set_floor_ceiling(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINX)
	{
		j = 0;
		while (j < WINY)
		{
			if (j < WINY / 2)
				put_pixel(data->mlx.win_img, i, j, data->map.elements.ceiling);
			else
				put_pixel(data->mlx.win_img, i, j, data->map.elements.floor);
			j++;
		}
		i++;
	}
}

