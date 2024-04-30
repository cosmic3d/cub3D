/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:25:33 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/23 14:08:31 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

#define WALL_COLOR 0xFFFF00
#define CLOSED_DOOR_COLOR 0xBBBB22
#define OPEN_DOOR_COLOR 0x5555FF
#define BG_COLOR 0x0000FF
#define PLAYER_COLOR 0x00FF00
#define SPRITE_COLOR 0xFF5555

static void	draw_tile(int *window, char id, int pos[2], int size);

void	draw_minimap(t_data *data, int *window)
{
	int	pos[2];
	int	i;
	int	j;
	int	tile_size;

	tile_size = fmax(WINX, WINY) / \
		fmax(data->map.size[X], data->map.size[Y]) / 4;
	if (tile_size < 1)
		return ;
	i = 0;
	while (i < data->map.size[Y])
	{
		j = 0;
		while (j < data->map.size[X])
		{
			pos[X] = j * tile_size;
			pos[Y] = i * tile_size;
			draw_tile(window, data->map.grid[i][j], pos, tile_size);
			j++;
		}
		i++;
	}
	pos[X] = data->player.pos[X] * tile_size - (tile_size / 2);
	pos[Y] = data->player.pos[Y] * tile_size - (tile_size / 2);
	draw_tile(window, 'P', pos, tile_size);
}

static void	draw_tile(int *window, char id, int pos[2], int size)
{
	int	color;
	int	i;
	int	j;

	color = BG_COLOR;
	if (id == '1')
		color = WALL_COLOR;
	else if (id == 'D')
		color = CLOSED_DOOR_COLOR;
	else if (id == 'd')
		color = OPEN_DOOR_COLOR;
	else if (id == 'P')
		color = PLAYER_COLOR;
	else if (id == 'O')
		color = SPRITE_COLOR;
	else if (id == SPACE)
		return ;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			window[(pos[Y] + j) * WINX + pos[X] + i] = color;
	}
}
