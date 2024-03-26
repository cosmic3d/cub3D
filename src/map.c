/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:52:17 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/26 18:25:06 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_argument(t_data *data, char *filepath)
{
	data->fd = open(filepath, O_RDONLY);
	if (data->fd == -1)
		c3d_exit(ERR_CANNOT_OPEN_FILE);
	data->file = store_file(filepath);
	parse_file(data);
	data->map.height = measure_map_height(data)
}

void	parse_file(t_data *data)
{
	int	i = 0;

	// Skip empty lines
	while (data->file[i] && data->file[i][0] == '\n')
		i++;

	// Check texture rule
	if (data->file[i] && !ft_strcmp(data->file[i], "NO "))
	{
		data->textures.north = ft_strdup(data->file[i] + 3);
		if (!data->textures.north)
			c3d_exit(ERR_MALLOC);
	}
	else
		c3d_exit(ERR_INVALID_FILE_FORMAT);

	int	j;
	j = 2;
	if (data->file[i] && !ft_strcmp(data->file[i], "F "))
	{
		while (data->file[i][j])
		{
			
		}
		data->textures.floor = tal;
	}
}

char	**store_file(char *filepath)
{
	char	**file;
	int		fd;
	int		file_lines;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		c3d_exit(ERR_CANNOT_OPEN_FILE);
	file_lines = ft_file_lines(fd);
	if (close(fd) == -1)
		c3d_exit(ERR_CANNOT_CLOSE_FILE);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		c3d_exit(ERR_CANNOT_OPEN_FILE);
	file = ft_store_file(fd, file_lines);
	if (close(fd) == -1)
		c3d_exit(ERR_CANNOT_CLOSE_FILE);
	return (file);
}

int	measure_map_height(t_data *data)
{
	char	*auxline;
	int		height;

}