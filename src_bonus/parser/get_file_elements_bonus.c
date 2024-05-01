/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_elements_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:07:58 by apresas-          #+#    #+#             */
/*   Updated: 2024/05/01 17:51:15 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

static int	get_texture_element(char *line, t_data *data, t_img *texture);
static int	get_color_element(char *line, t_data *data, int *color);
static int	rgb_token_check(char *channel);

/* Stores in the appropriate pointers the values of all the elements that
a valid file.cub must have. */
int	get_file_elements(t_data *data, t_elements *elements, char **file)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (file[i] && count < 6)
	{
		if (ft_strncmp(file[i], "NO", 2) == 0)
			count += get_texture_element(file[i], data, &elements->north);
		else if (ft_strncmp(file[i], "SO", 2) == 0)
			count += get_texture_element(file[i], data, &elements->south);
		else if (ft_strncmp(file[i], "WE", 2) == 0)
			count += get_texture_element(file[i], data, &elements->west);
		else if (ft_strncmp(file[i], "EA", 2) == 0)
			count += get_texture_element(file[i], data, &elements->east);
		else if (ft_strncmp(file[i], "F", 1) == 0)
			count += get_color_element(file[i], data, &elements->floor);
		else if (ft_strncmp(file[i], "C", 1) == 0)
			count += get_color_element(file[i], data, &elements->ceiling);
		else if (file[i][0] != '\0' && count < 6)
			c3d_exit(ERR_INVALID_FILE_FORMAT, data);
		i++;
	}
	return (i);
}

/* Obtains the texture path from the given line and stores it in **path */
static int	get_texture_element(char *line, t_data *data, t_img *texture)
{
	if (texture->img)
		c3d_exit(ERR_FILE_REPEATED_ELEMENT, data);
	line = ft_strnchr(line + 2, ' ');
	if (line[0] == '\t')
		c3d_exit(ERR_FILE_FORMAT_ELEMENT, data);
	if (ft_strrcmp(line, ".xpm") != 0)
		c3d_exit(ERR_FILE_FORMAT_ELEMENT, data);
	texture->img = mlx_xpm_file_to_image(data->mlx.mlx, line, \
			&texture->size[X], &texture->size[Y]);
	if (!texture->img)
		c3d_exit(ERR_XPM_TO_IMG, data);
	texture->addr = (int *)mlx_get_data_addr(texture->img, &texture->bpp, \
			&texture->line, &texture->endian);
	texture->line >>= 2;
	if (!texture->addr)
		c3d_exit(ERR_IMG_GET_ADDR, data);
	return (1);
}

/* Stores the color rgb values from the given line and stores them in *color */
static int	get_color_element(char *line, t_data *data, int *color)
{
	int		line_end;
	char	*red;
	char	*green;
	char	*blue;

	if (*color >= 0)
		c3d_exit(ERR_FILE_REPEATED_ELEMENT, data);
	line_end = ft_strlen(line);
	line = ft_strnchr(line + 1, ' ');
	if ((int)ft_strlen(line) == line_end)
		c3d_exit(ERR_FILE_FORMAT_ELEMENT, data);
	line_end = ft_strlen(line);
	red = ft_strtok(line, ",");
	green = ft_strtok(NULL, ",");
	blue = ft_strtok(NULL, ",");
	if (rgb_token_check(red) || rgb_token_check(green) || rgb_token_check(blue))
		c3d_exit(ERR_FILE_FORMAT_ELEMENT, data);
	if ((int)(blue - line + ft_strlen(blue)) != line_end)
		c3d_exit(ERR_FILE_FORMAT_ELEMENT, data);
	*color = rgb_to_int(ft_atoi(red), ft_atoi(green), ft_atoi(blue));
	if (*color == -1)
		c3d_exit(ERR_FILE_FORMAT_ELEMENT, data);
	return (1);
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
int	rgb_to_int(int red, int green, int blue)
{
	int	value;

	if ((red > 255 || red < 0) \
	|| (green > 255 || green < 0) \
	|| (blue > 255 || blue < 0))
	{
		return (-1);
	}
	value = (red << 16) | (green << 8) | blue;
	return (value);
}
