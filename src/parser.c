/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:52:17 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/27 15:18:41 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_argument(t_data *data, char *filepath)
{
	data->fd = open(filepath, O_RDONLY);
	if (data->fd == -1)
		c3d_exit(ERR_CANNOT_OPEN_FILE);
	data->file = store_file(filepath);
	clear_newlines(data->file);
	parse_file(data);
	data->map.size[Y] = measure_map_height(data);
}

// This removes all newlines at the end of each line of out char **file
void	clear_newlines(char **file)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		j = ft_strlen(file[i]);
		if (file[i][j] == '\n')
			file[i][j] = '\0';
		i++;
	}
	return ;
}

/* File guidelines:

> TEXTURES:
	-Any amount of one or more empty lines
	-Each element must come in any order
	-Each type of information in an element can be separated by spaces
	-


> MAP:
	- Must only contain 0, 1 and space for the structure
	- Must contain
	- Map must be surrounded by walls (1)
	-
*/

void	parse_file(t_data *data)
{
	int	element;
	int	i;

	i = 0;
	element = 0;
	while (element < 6) //EST MAL XD
	{
		if (!get_file_elements(data))
			c3d_exit(ERR_INVALID_FILE_FORMAT);
		i++;
	}

	if (!get_file_elements(data))

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

// test this
void	get_texture_path(char *line, char **path)
{
	int	i;

	i = 0;
	if (*path)
		c3d_exit(ERR_FILE_REPEATED_ELEMENT);
	ft_skip_char(line, ' ', &i);
	if (ft_strrcmp(line, ".xpm") != 0)
		c3d_exit(ERR_FILE_FORMAT_ELEMENT);
	*path = ft_strdup(line + i);
	if (*path)
		c3d_exit(ERR_MALLOC);
	return ;
}

int	get_file_elements(t_data *data)
{
	char	**file;
	int		i;

//
	int		element_data = 0;
	char	*tex;
//

	file = data->file;
	i = 0;
	while (file[i])
	{
		if (ft_strcmp(file[i], "NO") == 0)
			data->textures.north = get_texture_path(file[i]);
		else if (ft_strcmp(file[i], "SO") == 0)
			data->textures.south = get_texture_path(file[i]);
		else if (ft_strcmp(file[i], "WE") == 0)
			data->textures.west = get_texture_path(file[i]);
		else if (ft_strcmp(file[i], "EA") == 0)
			data->textures.east = get_texture_path(file[i]);
		else if (ft_strcmp(file[i], "F") == 0)
			data->textures.floor = get_color_element(file[i]);
		else if (ft_strcmp(file[i], "C") == 0)
			data->textures.ceiling = get_color_element(file[i]);

		/*
		TEXTURE 001
		N 001
		S 011
		E 101
		W 111
		COLOR 000
		F 000
		C 010
		*/
		identify_element(&element_data);
		if (element_data & 1 == TEXTURE)
			get_texture(element_data);
		else if (element_data & 1 == COLOR)
			get_color(element_data);
	}
	return (SUCCESS);
}

int get_file_elements(t_data *data)
{
	// 
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