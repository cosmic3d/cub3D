/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:32:37 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/18 12:47:24 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	bonus_check_valid_map_characters(t_map *map, char **file);
static int	bonus_check_map_is_surrounded(char **grid, int size[2]);
static int	tile_is_exterior(char **grid, int y, int x, int size[2]);
static int	count_sprites_in_map(int size[2], char **map);

void	bonus_parse_map(t_data *data, char **file)
{
	while (*file && **file == '\0')
		++file;
	if (!file)
		c3d_exit(ERR_NO_MAP_IN_FILE, data);
	if (bonus_check_valid_map_characters(&data->map, file) == 1)
		c3d_exit(NULL, data);
	data->map.grid = create_map_from_file(&data->map, file);
	if (!data->map.grid)
		c3d_exit(ERR_MALLOC, data);
	if (bonus_check_map_is_surrounded(data->map.grid, data->map.size) == 1)
		c3d_exit(NULL, data);
	data->sprite_count = count_sprites_in_map(data->map.size, data->map.grid);
}
static int	count_sprites_in_map(int size[2], char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < size[Y])
	{
		j = 0;
		while (j < size[X])
		{
			if (map[i][j] == 'O')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static int	bonus_check_valid_map_characters(t_map *map, char **file)
{
	int	i;
	int	j;

	i = -1;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (ft_strchr("NSWE", file[i][j]))
			{
				if (map->spawn[X] == -1)
					get_player_spawn_and_dir(map, file[i][j], i, j);
				else
					return (c3d_error(ERR_MAP_MULTIPLE_SPAWN));
			}
			if (!ft_strchr("10NSWEOD ", file[i][j]))
				return (c3d_error(ERR_MAP_INVALID_CHAR));
		}
		if (j == 0 || *ft_strnchr(file[i], ' ') == '\0')
			return (c3d_error(ERR_MAP_EMPTY_LINE));
	}
	if (map->spawn[X] == -1)
		return (c3d_error(ERR_MAP_NO_SPAWN));
	return (SUCCESS);
}

static int	bonus_check_map_is_surrounded(char **grid, int size[2])
{
	int	i;
	int	j;

	i = 0;
	while (i < size[Y])
	{
		j = 0;
		while (j < size[X])
		{
			if (tile_is_exterior(grid, i, j, size))
			{
				if (grid[i][j] == '0')
					return (c3d_error(ERR_MAP_NOT_ENCLOSED));
				if (ft_strchr("NSWE", grid[i][j]))
					return (c3d_error(ERR_MAP_SPAWN_INVALID));
				if (grid[i][j] == 'O')
					return (c3d_error(ERR_MAP_SPRITE_INVALID));
				if (grid[i][j] == 'D')
					return (c3d_error(ERR_MAP_DOOR_INVALID));
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	tile_is_exterior(char **grid, int y, int x, int size[2])
{
	int	i;
	int	j;

	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			if (y + i != 0 && x + j != 0)
			{
				if (y + i >= size[Y] || y + i < 0 || \
					x + j >= size[X] || x + j < 0 || \
					grid[y + i][x + j] == ' ')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
