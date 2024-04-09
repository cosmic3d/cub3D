/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:07:58 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/09 17:11:44 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture_element(char *line, t_mlx *mlx, t_img *texture);
static int	get_color_element(char *line, int *color);
static int	rgb_token_check(char *channel);
static int	rgb_to_int(int red, int green, int blue);

/* Stores in the appropriate pointers the values of all the elements that
a valid file.cub must have. */
int	get_file_elements(t_mlx *mlx, t_elements *elements, char **file)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (file[i] && count < 6)
	{
		printf("Line:\n%s\n", file[i]);
		if (ft_strncmp(file[i], "NO", 2) == 0)
			count += get_texture_element(file[i], mlx, &elements->north);
		else if (ft_strncmp(file[i], "SO", 2) == 0)
			count += get_texture_element(file[i], mlx, &elements->south);
		else if (ft_strncmp(file[i], "WE", 2) == 0)
			count += get_texture_element(file[i], mlx, &elements->west);
		else if (ft_strncmp(file[i], "EA", 2) == 0)
			count += get_texture_element(file[i], mlx, &elements->east);
		else if (ft_strncmp(file[i], "F", 1) == 0)
			count += get_color_element(file[i], &elements->floor);
		else if (ft_strncmp(file[i], "C", 1) == 0)
			count += get_color_element(file[i], &elements->ceiling);
		else if (file[i][0] != '\0' && count < 6)
			c3d_exit("yea");
		i++;
	}
	return (i);
}

/* Obtains the texture path from the given line and stores it in **path */
static int	get_texture_element(char *line, t_mlx *mlx, t_img *texture)
{
	if (texture->img)
		c3d_exit(ERR_FILE_REPEATED_ELEMENT);
	line = ft_strnchr(line + 2, ' ');
	if (ft_strrcmp(line, ".xpm") != 0)
		c3d_exit(ERR_FILE_FORMAT_ELEMENT);
	texture->img = mlx_xpm_file_to_image(mlx->mlx, line, \
			&texture->size[X], &texture->size[Y]);
	if (!texture->img)
		c3d_exit("mlx error"); // for now
	ft_printf("check\n");
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, \
			&texture->line, &texture->endian);
	return (1);
}

/* Stores the color rgb values from the given line and stores them in *color */
static int	get_color_element(char *line, int *color)
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
