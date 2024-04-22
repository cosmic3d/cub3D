/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:43:23 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/22 20:31:39 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_ceiling_and_floor(t_data *data);

void	render(t_data *data)
{
	set_ceiling_and_floor(data);
	init_raycasting(data);
	if (data->bonus)
	{
		if (data->sprite_count)
			bonus_draw_sprites(data, data->sprites);
		draw_minimap(data, data->mlx.win_img->addr);
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, \
	data->mlx.win_img->img, 0, 0);
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
