/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:32:00 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/03 18:33:16 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_height(char **file);
static int	get_map_width(char **file);
static void	copy_map(int **grid, char **file, int size[2]);

int	**create_map_from_file(char **file, int size[2])
{
	int	**grid;

	size[Y] = get_map_height(file);
	size[X] = get_map_width(file);
	grid = (int **)ft_alloc_array(sizeof(int), size[Y], size[X]);
	if (!grid)
		c3d_exit(ERR_MALLOC);
	copy_map(grid, file, size);
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

static void	copy_map(int **grid, char **file, int size[2])
{
	int	i;
	int	j;

	i = 0;
	while (i < size[Y])
	{
		j = 0;
		while (j < size[X])
		{
			if (file[i][j])
				grid[i][j] = file[i][j];
			else
				grid[i][j] = ' ';
			j++;
		}
		i++;
	}
}
