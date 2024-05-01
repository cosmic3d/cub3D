/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_grid_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:32:00 by apresas-          #+#    #+#             */
/*   Updated: 2024/05/01 17:51:14 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

static int	get_map_height(char **file);
static int	get_map_width(char **file);
static void	copy_map(char **grid, char **file, int size[2]);

char	**create_map_from_file(t_map *map, char **file)
{
	char	**grid;

	map->size[Y] = get_map_height(file);
	map->size[X] = get_map_width(file);
	grid = (char **)ft_alloc_array(sizeof(char), map->size[Y], map->size[X]);
	if (!grid)
		return (NULL);
	copy_map(grid, file, map->size);
	return (grid);
}

static int	get_map_height(char **file)
{
	int	height;

	height = 0;
	while (*file)
	{
		height++;
		file++;
	}
	return (height);
}

static int	get_map_width(char **file)
{
	int	width;
	int	i;
	int	j;

	width = 0;
	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
			j++;
		if (j > width)
			width = j;
		i++;
	}
	return (width);
}

static void	copy_map(char **grid, char **file, int size[2])
{
	int	i;
	int	j;

	i = 0;
	while (i < size[Y])
	{
		j = 0;
		while (j < size[X])
		{
			grid[i][j] = ' ';
			j++;
		}
		j = -1;
		while (file[i][++j])
			grid[i][j] = file[i][j];
		i++;
	}
}
