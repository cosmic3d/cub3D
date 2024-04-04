/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:07:58 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/03 18:39:30 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_texture_element(char *line, t_data *data, char **path);
static void	get_color_element(char *line, t_data *data, int *color);
static int	rgb_token_check(char *channel);
static int	rgb_to_int(int red, int green, int blue);

/* Stores in the appropriate pointers the values of all the elements that
a valid file.cub must have. */
int	get_file_elements(t_data *data)
{
	int		i;

	i = -1;
	while (data->file[++i] && data->textures.stored_values < 6)
	{
		if (data->file[i][0] == '\0')
			continue ;
		else if (ft_strncmp(data->file[i], "NO", 2) == 0)
			get_texture_element(data->file[i], data, &data->textures.north);
		else if (ft_strncmp(data->file[i], "SO", 2) == 0)
			get_texture_element(data->file[i], data, &data->textures.south);
		else if (ft_strncmp(data->file[i], "WE", 2) == 0)
			get_texture_element(data->file[i], data, &data->textures.west);
		else if (ft_strncmp(data->file[i], "EA", 2) == 0)
			get_texture_element(data->file[i], data, &data->textures.east);
		else if (ft_strncmp(data->file[i], "F", 1) == 0)
			get_color_element(data->file[i], data, &data->textures.floor);
		else if (ft_strncmp(data->file[i], "C", 1) == 0)
			get_color_element(data->file[i], data, &data->textures.ceiling);
		else
			c3d_exit(ERR_INVALID_FILE_FORMAT);
	}
	data->map.file_i = i;
	return (SUCCESS);
}

/* Obtains the texture path from the given line and stores it in **path */
static void	get_texture_element(char *line, t_data *data, char **path)
{
	if (*path)
		c3d_exit(ERR_FILE_REPEATED_ELEMENT);
	line = ft_strnchr(line + 2, ' ');
	if (ft_strrcmp(line, ".xpm") != 0)
		c3d_exit(ERR_FILE_FORMAT_ELEMENT);
	*path = ft_strdup(line);
	if (!*path)
		c3d_exit(ERR_MALLOC);
	data->textures.stored_values++;
	return ;
}

/* Stores the color rgb values from the given line and stores them in *color */
static void	get_color_element(char *line, t_data *data, int *color)
{
	int		line_end;
	char	*red;
	char	*green;
	char	*blue;

	if (*color >= 0)
		c3d_exit(ERR_FILE_REPEATED_ELEMENT);
	line_end = ft_strlen(line);
	line = ft_strnchr(line + 1, ' ');
	if ((int)ft_strlen(line) == line_end)
		c3d_exit(ERR_FILE_FORMAT_ELEMENT);
	line_end = ft_strlen(line);
	red = ft_strtok(line, ",");
	green = ft_strtok(NULL, ",");
	blue = ft_strtok(NULL, ",");
	if (rgb_token_check(red) || rgb_token_check(green) || rgb_token_check(blue))
		c3d_exit(ERR_FILE_FORMAT_ELEMENT);
	if ((int)(blue - line + ft_strlen(blue)) != line_end)
		c3d_exit(ERR_FILE_FORMAT_ELEMENT);
	*color = rgb_to_int(ft_atoi(red), ft_atoi(green), ft_atoi(blue));
	data->textures.stored_values++;
}

/* Checks that the given rgb channel token is formatted correctly. */
static int	rgb_token_check(char *channel)
{
	if (!channel)
		return (FAILURE);
	if (!ft_istype_iter(channel, ft_isdigit))
		return (FAILURE);
	if (!ft_isint(channel))
		return (FAILURE);
	return (SUCCESS);
}

/* Converts the given red, green and blue values into a single integer value */
static int	rgb_to_int(int red, int green, int blue)
{
	int	value;

	if ((red > 255 || red < 0) \
	|| (green > 255 || green < 0) \
	|| (blue > 255 || blue < 0))
		c3d_exit(ERR_FILE_FORMAT_ELEMENT);
	value = (red << 16) | (green << 8) | blue;
	return (value);
}
