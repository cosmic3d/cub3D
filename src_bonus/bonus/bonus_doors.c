/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:20:28 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/23 14:04:56 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

static void	calculate_door_step(t_data *data, t_door_data *door);
static int	player_is_looking_at(char **grid, t_door_data *door_data);

void	interact_door(t_data *data)
{
	t_door_data	door_data;
	double		distance;
	int			door;

	door_data.map[X] = (int)data->player.pos[X];
	door_data.map[Y] = (int)data->player.pos[Y];
	door_data.delta_dist[X] = fabs(1 / data->player.dir[X]);
	door_data.delta_dist[Y] = fabs(1 / data->player.dir[Y]);
	calculate_door_step(data, &door_data);
	door = player_is_looking_at(data->map.grid, &door_data);
	if (door != 'D' && door != 'd')
		return ;
	door_data.pos[X] = door_data.map[X] + 0.5;
	door_data.pos[Y] = door_data.map[Y] + 0.5;
	distance = sqrt(pow(data->player.pos[X] - (door_data.pos[X]), 2) + \
		pow(data->player.pos[Y] - (door_data.pos[Y]), 2));
	if (distance >= 1.55)
		return ;
	if (door == 'D')
		data->map.grid[door_data.map[Y]][door_data.map[X]] = 'd';
	else
		data->map.grid[door_data.map[Y]][door_data.map[X]] = 'D';
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

static int	player_is_looking_at(char **grid, t_door_data *door_data)
{
	while (1)
	{
		if (door_data->side_dist[X] < door_data->side_dist[Y])
		{
			door_data->side_dist[X] += door_data->delta_dist[X];
			door_data->map[X] += door_data->step[X];
		}
		else
		{
			door_data->side_dist[Y] += door_data->delta_dist[Y];
			door_data->map[Y] += door_data->step[Y];
		}
		if (grid[door_data->map[Y]][door_data->map[X]] == WALL)
			return (0);
		if (grid[door_data->map[Y]][door_data->map[X]] == 'D')
			return ('D');
		if (grid[door_data->map[Y]][door_data->map[X]] == 'd')
			return ('d');
	}
	return (0);
}
