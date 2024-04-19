/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:20:28 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/19 18:19:05 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_door_step(t_data *data, t_door_data *door);
static int	check_player_is_looking_at_door(t_data *data, t_door_data *door);

void	open_door(t_data *data)
{
	t_door_data	door_data;
	double		distance;

	door_data.map[X] = (int)data->player.pos[X];
	door_data.map[Y] = (int)data->player.pos[Y];
	door_data.delta_dist[X] = fabs(1 / data->player.dir[X]);
	door_data.delta_dist[Y] = fabs(1 / data->player.dir[Y]);
	calculate_door_step(data, &door_data);
	if (!check_player_is_looking_at_door(data, &door_data))
		return ;
	door_data.pos[X] = door_data.map[X] + 0.5;
	door_data.pos[Y] = door_data.map[Y] + 0.5;
	distance = sqrt(pow(data->player.pos[X] - (door_data.pos[X]), 2) + \
		pow(data->player.pos[Y] - (door_data.pos[Y]), 2));
	if (distance >= 1.55)
		return ;
	data->map.grid[door_data.map[Y]][door_data.map[X]] = '0';
	return ;
}

static void	calculate_door_step(t_data *data, t_door_data *door)
{
	if (data->player.dir[X] < 0)
	{
		door->step[X] = -1;
		door->side_dist[X] = (data->player.pos[X] - door->map[X]) * \
		door->delta_dist[X];
	}
	else
	{
		door->step[X] = 1;
		door->side_dist[X] = (door->map[X] + 1.0 - data->player.pos[X]) * \
		door->delta_dist[X];
	}
	if (data->player.dir[Y] < 0)
	{
		door->step[Y] = -1;
		door->side_dist[Y] = (data->player.pos[Y] - door->map[Y]) * \
		door->delta_dist[Y];
	}
	else
	{
		door->step[Y] = 1;
		door->side_dist[Y] = (door->map[Y] + 1.0 - data->player.pos[Y]) * \
		door->delta_dist[Y];
	}
}

static int	check_player_is_looking_at_door(t_data *data, t_door_data *door)
{
	while (1)
	{
		if (door->side_dist[X] < door->side_dist[Y])
		{
			door->side_dist[X] += door->delta_dist[X];
			door->map[X] += door->step[X];
		}
		else
		{
			door->side_dist[Y] += door->delta_dist[Y];
			door->map[Y] += door->step[Y];
		}
		if (data->map.grid[door->map[Y]][door->map[X]] == WALL)
			return (0);
		if (data->map.grid[door->map[Y]][door->map[X]] == DOOR)
			return (1);
	}
	return (0);
}
