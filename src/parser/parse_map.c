/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:27:03 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/04 13:17:31 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_valid_map_characters(char **file);
static void	check_map_is_surrounded(int **grid, int size[2]);
static int	tile_is_exterior(int **grid, int y, int x, int size[2]);

void	get_player_spawn(int **grid, int size[2], t_map *map);

void	parse_map(t_data *data, char **file)
{
	while (*file && **file == '\0')
		++file;
	if (!file)
		c3d_exit("No map in file");
	check_valid_map_characters(file);
	data->map.grid = create_map_from_file(file, data->map.size);
	check_map_is_surrounded(data->map.grid, data->map.size);
	get_player_spawn(data->map.grid, data->map.size, &data->map);
	print_map_grid(data);
}

void	get_player_spawn(int **grid, int size[2], t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < size[Y])
	{
		x = 0;
		while (x < size[X])
		{
			if (grid[x][y] == 'N')
			{
				map->player_dir[X] = 0;
				map->player_dir[Y] = -1;
			}
			if (grid[x][y] == 'S')
			{
				map->player_dir[X] = 0;
				map->player_dir[Y] = 1;
			}
			else if (grid[x][y] == 'W')
			{
				map->player_dir[X] = 1;
				map->player_dir[Y] = 0;
			}
			else if (grid[y][x] == 'E')
			{
				map->player_dir[X] = -1;
				map->player_dir[Y] = 1;
			}
		}
	}
}

static void	check_valid_map_characters(char **file)
{
	int	i;
	int	j;
	int	spawn;

	i = -1;
	spawn = 0;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (ft_strchr("NSWE", file[i][j]))
			{
				if (spawn == 1)
					c3d_exit("Multiple spawn points in map");
				spawn = 1;
			}
			if (!ft_strchr("10NSWE ", file[i][j]))
				c3d_exit("Invalid characters found in map");
		}
		if (j == 0)
			c3d_exit("Empty lines in map found");
	}
	if (spawn == 0)
		c3d_exit("No spawn point in map");
}

static void	check_map_is_surrounded(int **grid, int size[2])
{
	int	i;
	int	j;

	i = 0;
	while (i < size[Y])
	{
		j = 0;
		while (j < size[X])
		{
			printf("Check [%d][%d]\n", i, j);
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
}

static int	tile_is_exterior(int **grid, int y, int x, int size[2])
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
