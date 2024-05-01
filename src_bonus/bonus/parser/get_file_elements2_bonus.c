/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_elements2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:59:23 by apresas-          #+#    #+#             */
/*   Updated: 2024/05/01 17:51:48 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

static int	get_color(char **line, t_data *data);

int	get_transparency_color(char **line, t_data *data)
{
	int	transparency_color;

	ft_strspn_skip(line, " \t");
	transparency_color = get_color(line, data);
	if (transparency_color == -1)
		c3d_exit(ERR_FILE_FORMAT_ELEMENT, data);
	return (transparency_color);
}

static int	get_color(char **line, t_data *data)
{
	int	rgb[3];
	int	i;

	i = 0;
	while (i < 3)
	{
		ft_strspn_skip(line, " \t");
		if (!ft_isdigit(**line))
			c3d_exit("1", data);
		rgb[i] = ft_atoi(*line);
		if (rgb[i] < 0 || rgb[i] > 255)
			c3d_exit("2", data);
		while (ft_isdigit(**line))
			*line += 1;
		if (i < 2 && **line != ',')
			c3d_exit("3", data);
		if (i == 2 && **line != ' ' && **line != '\t')
			c3d_exit("4", data);
		if (i < 2)
			*line += 1;
		i++;
	}
	return (rgb_to_int(rgb[0], rgb[1], rgb[2]));
}

int	get_sprite_texture_count(char **line, t_data *data)
{
	int	sprite_texture_count;

	ft_strspn_skip(line, " \t");
	if (!ft_isdigit(**line))
		c3d_exit(ERR_FILE_FORMAT_ELEMENT, data);
	sprite_texture_count = ft_atoi(*line);
	if (sprite_texture_count < 0 || sprite_texture_count > 99)
		c3d_exit(ERR_FILE_FORMAT_ELEMENT, data);
	ft_istype_skip_p(line, ft_isdigit);
	ft_strspn_skip(line, " \t");
	return (sprite_texture_count);
}

char	*get_full_path(char *prefix, int i, t_data *data)
{
	char	*path;
	char	*num;

	num = ft_itoa(i);
	if (!num)
	{
		free(prefix);
		c3d_exit(ERR_MALLOC, data);
	}
	if (i <= 9)
		path = ft_strjoin_4(prefix, "0", num, ".xpm");
	else
		path = ft_strjoin_3(prefix, num, ".xpm");
	if (!path)
	{
		free(prefix);
		free(num);
		c3d_exit(ERR_MALLOC, data);
	}
	free(num);
	return (path);
}

char	*get_path_prefix(char *line, t_data *data)
{
	char	*path_aux;
	char	*path_aux2;

	ft_strspn_skip(&line, " \t");
	path_aux = ft_strdup(line);
	if (!path_aux)
		c3d_exit(ERR_MALLOC, data);
	if (path_aux[ft_strlen(path_aux) - 1] != '/')
	{
		free(path_aux);
		c3d_exit("Sprite directory path must end with a '/'", data);
	}
	path_aux2 = ft_strjoin(path_aux, "sprite_");
	free(path_aux);
	if (!path_aux2)
		c3d_exit(ERR_MALLOC, data);
	return (path_aux2);
}
