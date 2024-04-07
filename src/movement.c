/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:51:36 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/07 21:46:44 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_data *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir[X];
	data->player.dir[X] = data->player.dir[X] * cos(angle) - \
	data->player.dir[Y] * sin(angle);
	data->player.dir[Y] = old_dir_x * sin(angle) + \
	data->player.dir[Y] * cos(angle);
	old_plane_x = data->player.plane[X];
	data->player.plane[X] = data->player.plane[X] * cos(angle) - \
	data->player.plane[Y] * sin(angle);
	data->player.plane[Y] = old_plane_x * sin(angle) + \
	data->player.plane[Y] * cos(angle);
	/* printf("Player direction: [%f, %f]\n", data->player.dir[X], data->player.dir[Y]);
	printf("Player plane: [%f, %f]\n\n", data->player.plane[X], data->player.plane[Y]);
	printf("Player position: [%f, %f]\n", data->player.pos[X], data->player.pos[Y]); */
}

void move_forward(t_data *d)
{
	printf("Player direction: [%f, %f]\n", d->player.dir[X], d->player.dir[Y]);
	printf("Player position: [%f, %f]\n", d->player.pos[X], d->player.pos[Y]);
	if (d->map.grid[(int)(d->player.pos[Y] + d->player.dir[Y] * MOVE_SPEED)]\
	[(int)d->player.pos[X]] != '1')
	{
		d->player.pos[Y] += d->player.dir[Y] * MOVE_SPEED;
	}
	if (d->map.grid[(int)d->player.pos[Y]]\
	[(int)(d->player.pos[X] + d->player.dir[X] * MOVE_SPEED)] != '1')
	{
		d->player.pos[X] += d->player.dir[X] * MOVE_SPEED;
	}
}

void move_back(t_data *d)
{
	if (d->map.grid[(int)(d->player.pos[Y] - d->player.dir[Y] * MOVE_SPEED)]\
	[(int)d->player.pos[X]] != '1')
	{
		d->player.pos[Y] -= d->player.dir[Y] * MOVE_SPEED;
	}
	if (d->map.grid[(int)d->player.pos[Y]]\
	[(int)(d->player.pos[X] - d->player.dir[X] * MOVE_SPEED)] != '1')
	{
		d->player.pos[X] -= d->player.dir[X] * MOVE_SPEED;
	}
}

void move_left(t_data *d)
{
	if (d->map.grid[(int)(d->player.pos[Y] + d->player.dir[X] * MOVE_SPEED)]\
	[(int)d->player.pos[X]] != '1')
	{
		d->player.pos[Y] += d->player.dir[X] * MOVE_SPEED;
	}
	if (d->map.grid[(int)d->player.pos[Y]]\
	[(int)(d->player.pos[X] - d->player.dir[Y] * MOVE_SPEED)] != '1')
	{
		d->player.pos[X] -= d->player.dir[Y] * MOVE_SPEED;
	}
}

void move_right(t_data *d)
{
	if (d->map.grid[(int)(d->player.pos[Y] - d->player.dir[X] * MOVE_SPEED)]\
	[(int)d->player.pos[X]] != '1')
	{
		d->player.pos[Y] -= d->player.dir[X] * MOVE_SPEED;
	}
	if (d->map.grid[(int)d->player.pos[Y]]\
	[(int)(d->player.pos[X] + d->player.dir[Y] * MOVE_SPEED)] != '1')
	{
		d->player.pos[X] += d->player.dir[Y] * MOVE_SPEED;
	}
}
