/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:43:23 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/12 02:48:45 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_data *data)
{
	set_floor_ceiling(data);
	init_raycasting(data);
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

void	drawMinimap(t_data *data)
{
	int	i;
	int	j;
	int	tile_size;

	tile_size = fmax(WINX, WINY) / fmax(data->map.size[X], data->map.size[Y]) / 4;
	i = 0;
	while (i < data->map.size[Y])
	{
		j = 0;
		while (j < data->map.size[X])
		{
			if (data->map.grid[i][j] == '1')
				drawRect(data, j * tile_size, i * tile_size, tile_size, YELLOW);
			else if (data->map.grid[i][j] != SPACE)
				drawRect(data, j * tile_size, i * tile_size, tile_size, BLUE);
			j++;
		}
		i++;
	}
	drawRect(data, data->player.pos[X] * tile_size, data->player.pos[Y] * tile_size, tile_size, 0x00FF00);
}
