/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:43:23 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/16 15:45:02 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/time.h>

static void	set_ceiling_and_floor(t_img *window, t_elements elements);

// Al menos para linux esto está guay
static time_t	get_time()
{
	static time_t	start_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (!start_time)
		start_time = time.tv_sec * 1000000 + time.tv_usec;
	return ((time.tv_sec * 1000000 + time.tv_usec) - start_time);
}

void	render(t_data *data)
{
	static time_t	last_render;
	time_t			elapsed_time;

	elapsed_time = get_time() - last_render;
	if (last_render && elapsed_time < 5000) //200 FPS
		return ;
	set_ceiling_and_floor(data->mlx.win_img, data->map.elements);
	init_raycasting(data);
	bonus_draw_sprites(data);
	if (data->bonus)
		drawMinimap(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, data->mlx.win_img->img, 0, 0);
	last_render = get_time();
}

static void	set_ceiling_and_floor(t_img *window, t_elements elements)
{
	int		i;
	int		j;

	i = 0;
	while (i < WINX)
	{
		j = 0;
		while (j < WINY >> 1)
			put_pixel(window, i, j++, elements.ceiling);
		while (j < WINY)
			put_pixel(window, i, j++, elements.floor);
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
