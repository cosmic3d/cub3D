/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:43:23 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/17 15:17:22 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_ceiling_and_floor(t_data *data);

void	render(t_data *data)
{
	if (!data->frame_done) //NO SE SI AFECTA O NO A LA PERFORMANCE
		return ;
	data->frame_done = 0;
	set_ceiling_and_floor(data);
	init_raycasting(data);
	if (data->bonus)
	{
		bonus_draw_sprites(data);
		drawMinimap(data);
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, \
	data->mlx.win_img->img, 0, 0);
	data->frame_done = 1;
}

static void	set_ceiling_and_floor(t_data *data)
{
	int	i;
	int	j;
	int	limit;

	i = 0;
	limit = WINY / 2 - data->map.offset_y - 1;
	while (i < WINX)
	{
		j = 0;
		while (j < limit)
			put_pixel(data->mlx.win_img, i, j++, data->map.elements.ceiling);
		while (j < WINY)
			put_pixel(data->mlx.win_img, i, j++, data->map.elements.floor);
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
	drawRect(data, data->player.pos[X] * tile_size - (tile_size / 2), data->player.pos[Y] * tile_size - (tile_size / 2), tile_size, 0x00FF00);
}
