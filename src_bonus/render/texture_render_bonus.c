/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:24:38 by apresas-          #+#    #+#             */
/*   Updated: 2024/05/04 02:53:39 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

int	*get_texture_addr(t_data *data, t_img *texture)
{
	int		*texture_addr;
	double	wall_x;

	if (data->ray.side[X] == 0)
	{
		wall_x = data->player.pos[X] + data->ray.perp_wall_dist * \
				data->ray.ray_dir[X];
	}
	else
	{
		wall_x = data->player.pos[Y] + data->ray.perp_wall_dist * \
				data->ray.ray_dir[Y];
	}
	wall_x -= floor(wall_x);
	texture_addr = texture->addr + (int)(wall_x * texture->line);
	return (texture_addr);
}

t_img	*get_texture(t_data *data)
{
	if (data->map.grid[data->ray.map[Y]][data->ray.map[X]] == DOOR)
		return (&data->map.elements.door);
	if (data->ray.side[X] == 0)
	{
		if (data->ray.side[Y] == 1)
			return (&data->map.elements.south);
		else
			return (&data->map.elements.north);
	}
	if (data->ray.side[X] == 1)
		return (&data->map.elements.west);
	return (&data->map.elements.east);
}

void	draw_vert_stripe(int *texture, int *win, int tx_size[2], t_data *data)
{
	int		y;
	int		draw_end;
	double	step;
	double	texture_iter_d;
	int		line_h;

	line_h = (int)(WINY / data->ray.perp_wall_dist);
	y = ((WINY - line_h) >> 1) - data->map.offset_y;
	texture_iter_d = 0.0;
	step = (double)tx_size[Y] / (line_h + 1);
	if (y < 0)
	{
		texture_iter_d = step * -y;
		y = 0;
	}
	draw_end = y + line_h;
	if (draw_end >= WINY)
		draw_end = WINY - 1;
	while (y <= draw_end)
	{
		if (!inRange((int)texture_iter_d * tx_size[X], tx_size[X] * tx_size[Y]))
			break ;
		win[y++ * WINX] = texture[(int)texture_iter_d * tx_size[X]];
		texture_iter_d += step;
	}
}

int	inRange(int index, int texture_size)
{
	return (index >= 0 && index < texture_size);
}
