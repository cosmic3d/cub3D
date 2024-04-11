/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:43:23 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/04 13:07:44 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_data *data)
{
	set_floor_ceiling(data);
	init_raycasting(data);
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
				put_pixel(data->mlx.win_img, i, j, CEILING);
			else
				put_pixel(data->mlx.win_img, i, j, FLOOR);
			j++;
		}
		i++;
	}
}

void	drawMinimap(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	drawRect(data, 0, 0, max(data->map.size[X], data->map.size[Y]) * TILE_SIZE, BLUE);
	while (i < data->map.size[X])
	{
		j = 0;
		while (j < data->map.size[Y])
		{
			if (data->map.grid[i][j] == '1')
				drawRect(data, j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, YELLOW);
			// else if (data->map.grid[i][j] == '0')
			// 	drawRect(data, j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, BLUE);
			j++;
		}
		i++;
	}
	x = data->player.pos[0] * TILE_SIZE;
	y = data->player.pos[1] * TILE_SIZE;
	drawRect(data, x, y, 5, 0x00FF00);
}
