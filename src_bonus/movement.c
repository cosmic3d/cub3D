/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:51:36 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/22 20:23:58 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

void	rotate_player(t_data *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	old_dir_x = data->player.dir[X];
	data->player.dir[X] = data->player.dir[X] * cos_angle - \
	data->player.dir[Y] * sin_angle;
	data->player.dir[Y] = old_dir_x * sin_angle + \
	data->player.dir[Y] * cos_angle;
	old_plane_x = data->player.plane[X];
	data->player.plane[X] = data->player.plane[X] * cos_angle - \
	data->player.plane[Y] * sin_angle;
	data->player.plane[Y] = old_plane_x * sin_angle + \
	data->player.plane[Y] * cos_angle;
}

void	move_forward(t_data *d)
{
	int	x;
	int	y;

	y = (int)(d->player.pos[Y] + d->player.dir[Y] * fabs(d->player.move_speed));
	x = (int)d->player.pos[X];
	if (d->map.grid[y][x] != '1' && d->map.grid[y][x] != 'D')
	{
		d->player.pos[Y] += d->player.dir[Y] * fabs(d->player.move_speed);
	}
	y = (int)d->player.pos[Y];
	x = (int)(d->player.pos[X] + d->player.dir[X] * fabs(d->player.move_speed));
	if (d->map.grid[y][x] != '1' && d->map.grid[y][x] != 'D')
	{
		d->player.pos[X] += d->player.dir[X] * fabs(d->player.move_speed);
	}
}

void	move_back(t_data *d)
{
	int	x;
	int	y;

	y = (int)(d->player.pos[Y] - d->player.dir[Y] * fabs(d->player.move_speed));
	x = (int)d->player.pos[X];
	if (d->map.grid[y][x] != '1' && d->map.grid[y][x] != 'D')
	{
		d->player.pos[Y] -= d->player.dir[Y] * fabs(d->player.move_speed);
	}
	y = (int)d->player.pos[Y];
	x = (int)(d->player.pos[X] - d->player.dir[X] * fabs(d->player.move_speed));
	if (d->map.grid[y][x] != '1' && d->map.grid[y][x] != 'D')
	{
		d->player.pos[X] -= d->player.dir[X] * fabs(d->player.move_speed);
	}
}

void	move_left(t_data *d)
{
	int	x;
	int	y;

	y = (int)(d->player.pos[Y] - d->player.dir[X] * d->player.move_speed);
	x = (int)d->player.pos[X];
	if (d->map.grid[y][x] != '1' && d->map.grid[y][x] != 'D')
	{
		d->player.pos[Y] -= d->player.dir[X] * d->player.move_speed;
	}
	y = (int)d->player.pos[Y];
	x = (int)(d->player.pos[X] + d->player.dir[Y] * d->player.move_speed);
	if (d->map.grid[y][x] != '1' && d->map.grid[y][x] != 'D')
	{
		d->player.pos[X] += d->player.dir[Y] * d->player.move_speed;
	}
}

void	move_right(t_data *d)
{
	int	x;
	int	y;

	y = (int)(d->player.pos[Y] + d->player.dir[X] * d->player.move_speed);
	x = (int)d->player.pos[X];
	if (d->map.grid[y][x] != '1' && d->map.grid[y][x] != 'D')
	{
		d->player.pos[Y] += d->player.dir[X] * d->player.move_speed;
	}
	y = (int)d->player.pos[Y];
	x = (int)(d->player.pos[X] - d->player.dir[Y] * d->player.move_speed);
	if (d->map.grid[y][x] != '1' && d->map.grid[y][x] != 'D')
	{
		d->player.pos[X] -= d->player.dir[Y] * d->player.move_speed;
	}
}
