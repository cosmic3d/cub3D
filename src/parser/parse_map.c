/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:27:03 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/05 16:59:06 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_valid_map_characters(t_map *map, char **file);
static void	get_player_spawn_and_dir(t_map *map, char player, int x, int y);
static void	check_map_is_surrounded(char **grid, int size[2]);
static int	tile_is_exterior(char **grid, int y, int x, int size[2]);

void	parse_map(t_data *data, char **file)
{
	while (*file && **file == '\0')
		++file;
	if (!file)
		c3d_exit("No map in file");
	check_valid_map_characters(&data->map, file);
	data->map.grid = create_map_from_file(file, data->map.size);
	print_data(data);
	check_map_is_surrounded(data->map.grid, data->map.size);
}

static void	check_valid_map_characters(t_map *map, char **file)
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
					c3d_exit("Multiple spawn points in map");
			}
			if (!ft_strchr("10NSWE ", file[i][j]))
				c3d_exit("Invalid characters found in map");
		}
		if (j == 0 || *ft_strnchr(file[i], ' ') == '\0')
			c3d_exit("Empty lines in map found");
	}
	if (map->spawn[X] == -1)
		c3d_exit("No spawn point in map");
}

static void	get_player_spawn_and_dir(t_map *map, char player, int x, int y)
{
	map->spawn[X] = x;
	map->spawn[Y] = y;
	if (player == 'N')
	{
		map->player_dir[X] = 0;
		map->player_dir[Y] = -1;
	}
	else if (player == 'S')
	{
		map->player_dir[X] = 0;
		map->player_dir[Y] = 1;
	}
	else if (player == 'W')
	{
		map->player_dir[X] = 1;
		map->player_dir[Y] = 0;
	}
	else if (player == 'E')
	{
		map->player_dir[X] = -1;
		map->player_dir[Y] = 0;
	}
}

static void	check_map_is_surrounded(char **grid, int size[2])
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
					c3d_exit("Map is not surounded");
				if (ft_strchr("NSWE", grid[i][j]))
					c3d_exit("Player is out of bounds");
			}
			j++;
		}
		i++;
	}
	return ;
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
