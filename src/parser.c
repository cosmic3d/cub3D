/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:52:17 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/27 13:15:32 by jenavarr         ###   ########.fr       */
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
	data->map.size[Y] = measure_map_height(data);
}

void	parse_file(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6) //EST MAL XD
	{
		if (!get_file_elements(data))
			c3d_exit(ERR_INVALID_FILE_FORMAT);
		i++;
	}

	/* // Check texture rule
	if (data->file[i] && !ft_strcmp(data->file[i], "NO ")) //Está mal creo
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
	} */
}

int get_file_elements(t_data *data)
{
	int	i = 0;

	if (!data->file[i])
		return (FALSE);
	while (data->file[i][0] == '\n' || data->file[i][0] == SPACE)
		i++;
	if (!data->file[i])
		return (FALSE);
	
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

/* int	measure_map_height(t_data *data)
{
	char	*auxline;
	int		height;

} */