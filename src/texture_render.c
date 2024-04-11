/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:24:38 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/11 17:32:03 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// debug
#include <time.h>

static t_img	*get_texture(t_data *data)
{
	int side_x;
	int side_y;

	side_x = data->ray.side[X];
	side_y = data->ray.side[Y];
	// if (side_x == 0)
	// {
	// 	if (side_y == 1)
	// 		return (&data->map.elements.south);
	// 	return (&data->map.elements.north);
	// }
	// if (side_x == 1)
	// 	return (&data->map.elements.west);
	// return (&data->map.elements.east);
	if (side_x == 1 && side_y == 0)
		return (&data->map.elements.west);
	else if (side_x == -1 && side_y == 0)
		return (&data->map.elements.east);
	else if (side_x == 0 && side_y == 1)
		return (&data->map.elements.south);
	else if (side_x == 0 && side_y == -1)
		return (&data->map.elements.north);
	c3d_exit("get_wall_texture unexpected behavior");//
	return (NULL);
}

static int	get_y_value(int draw_start, double *texD, int *texI, int texSize, double step)
{
	if (draw_start < 0)
	{
		*texD = step * (0 - draw_start);
		*texI = (int)*texD & (texSize - 1);// this & (texSize - 1) only works for powers of two sizes like 32, 64 and 128. Gotta think about this in case the program is sent other sizes.
		return (0);
	}
	return (draw_start);
}

static int	get_texture_px_x(t_ray ray, t_player player, int texture_size)
{
	double wall_x;

	if (ray.side[Y] == 0)
		wall_x = player.pos[Y] + ray.perp_wall_dist * ray.ray_dir[Y];
	else
		wall_x = player.pos[X] + ray.perp_wall_dist * ray.ray_dir[X];
	wall_x -= floor(wall_x);
	return ((int)(wall_x * (double)(texture_size)));
}

static void	texture_pixel_to_window_image(t_img *t, int ti, t_img *w, int wi)
{
	w->addr[wi] = t->addr[ti];
}

void	draw_vert_stripe(t_data *data, int x, int texture_size)
{
	int		y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		texture_px_x;
	double	step;
	double	texture_iter_d;
	int		texture_iter_i;
	t_img	*texture;

	texture_iter_d = 0.0;
	texture_iter_i = 0;
	texture = get_texture(data);
	line_height = (int)(WINY / data->ray.perp_wall_dist);
	draw_start = WINY / 2 - line_height / 2;
	draw_end = draw_start + line_height;
	if (draw_end >= WINY)
		draw_end = WINY - 1;
	step = 1.0 * texture_size / line_height;
	y = get_y_value(draw_start, &texture_iter_d, &texture_iter_i, texture_size, step);
	texture_px_x = get_texture_px_x(data->ray, data->player, texture_size);
	while (y < draw_end)
	{
		texture_iter_i = (int)texture_iter_d & (texture_size - 1);
		texture_iter_d += step;
		texture_pixel_to_window_image(texture, \
				texture_iter_i * (texture->line / 4) + texture_px_x, \
				data->mlx.win_img, \
				y * (data->mlx.win_img->line / 4) + x);
		y++;
	}
}
