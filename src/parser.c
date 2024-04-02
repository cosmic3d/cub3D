/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:52:17 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/02 13:16:12 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	parse_argument(t_data *data, char *filepath)
{
	data->fd = open(filepath, O_RDONLY);
	if (data->fd == -1)
		c3d_exit(ERR_CANNOT_OPEN_FILE);
	data->file = store_file(filepath);
	clear_newlines(data->file);
	parse_file(data);
	// data->map.size[Y] = measure_map_height(data);
	return (1); // por ahora
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
		if (file[i][j - 1] == '\n')
			file[i][j - 1] = '\0';
		i++;
	}
	return ;
}

void	parse_file(t_data *data)
{
	get_file_elements(data);
}

// test this
void	get_texture_element(char *line, t_data *data, char **path)
{
	int	i;

	i = 0;
	if (*path)
		c3d_exit(ERR_FILE_REPEATED_ELEMENT);
	ft_skip_char(line, &i, ' ');
	if (ft_strrcmp(line, ".xpm") != 0)
		c3d_exit(ERR_FILE_FORMAT_ELEMENT);
	printf("line = %s\n", line);
	*path = ft_strdup(line + i);
	if (!*path)
		c3d_exit(ERR_MALLOC);
	data->textures.stored_values++;
	return ;
}

void	get_color_element(char *line, t_data *data, int *color)
{
	int		i;
	char	*red_s;
	char	*green_s;
	char	*blue_s;
	int		line_end;

	if (*color)
		c3d_exit("1");
	line_end = ft_strlen(line);
	i = 1;
	if (ft_skip_char(line, &i, ' ') == 0)
		c3d_exit("1.5");
	red_s = ft_strtok(line + i, ",");
	if (!red_s || !ft_istype_iter(red_s, ft_isdigit) || !ft_isint(red_s))
		c3d_exit("2");
	green_s = ft_strtok(NULL, ",");
	if (!green_s || !ft_istype_iter(green_s, ft_isdigit) || !ft_isint(green_s))
		c3d_exit("3");
	blue_s = ft_strtok(NULL, ",");
	if (!blue_s || !ft_istype_iter(blue_s, ft_isdigit) || !ft_isint(blue_s))
		c3d_exit("4");
	if ((int)(blue_s - line + ft_strlen(blue_s)) != line_end)
		c3d_exit("5");
	*color = rgb_to_int(ft_atoi(red_s), ft_atoi(green_s), ft_atoi(blue_s));
	data->textures.stored_values++;
}

int	rgb_to_int(int red, int green, int blue)
{
	int	value;

	printf("r %d\ng %d\nb %d\n", red, green, blue);

	if ((red > 255 || red < 0) \
	|| (green > 255 || green < 0) \
	|| (blue > 255 || blue < 0))
		c3d_exit("6");
	value = (red << 16) | (green << 8) | blue;
	return (value);
}

int	get_file_elements(t_data *data)
{
	char	**file;
	int		i;

	file = data->file;
	i = 0;
	while (file[i++] && data->textures.stored_values < 6)
	{
		printf("checking file line:\n");
		printf("\"%s\"\n", file[i]);
		if (file[i][0] == '\0')
			continue ;
		else if (ft_strncmp(file[i], "NO", 2) == 0)
			get_texture_element(file[i], data, &data->textures.north);
		else if (ft_strncmp(file[i], "SO", 2) == 0)
			get_texture_element(file[i], data, &data->textures.south);
		else if (ft_strncmp(file[i], "WE", 2) == 0)
			get_texture_element(file[i], data, &data->textures.west);
		else if (ft_strncmp(file[i], "EA", 2) == 0)
			get_texture_element(file[i], data, &data->textures.east);
		else if (ft_strncmp(file[i], "F", 1) == 0)
			get_color_element(file[i], data, &data->textures.floor);
		else if (ft_strncmp(file[i], "C", 1) == 0)
			get_color_element(file[i], data, &data->textures.ceiling);
		else
			c3d_exit(ERR_INVALID_FILE_FORMAT);
	}
	printf("out\n");
	if (data->textures.stored_values != 6)
		c3d_exit(ERR_NOT_ENOUGH_ELEMENTS);
	return (SUCCESS);
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
