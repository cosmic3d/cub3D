/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_file_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:03:08 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/23 20:10:32 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_bonus_texture(t_data *data, char *line, t_img *texture);
static int	get_sprites(t_data *data, char *line);
static void	get_sprites_from_directory(t_data *data, t_sprite *s, char *pre);
static int	get_sprite_framerate(char **line, t_data *data);

int	get_bonus_elements(t_data *data, char **file)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (file[i] && count < 2)
	{
		if (ft_strncmp(file[i], "SP", 2) == 0)
			count += get_sprites(data, file[i] + 2);
		else if (ft_strncmp(file[i], "DR", 2) == 0)
			count += get_bonus_texture(data, file[i], \
			&data->map.elements.door);
		else if (file[i][0] != '\0' && count < 2)
			c3d_exit(ERR_INVALID_FILE_FORMAT, data);
		i++;
	}
	return (i);
}

static int	get_sprites(t_data *data, char *line)
{
	char	*prefix;
	int		i;

	data->sprite.i = 0;
	data->sprite.transparency_color = get_transparency_color(&line, data);
	data->sprite.frames = get_sprite_texture_count(&line, data);
	data->sprite.framerate = get_sprite_framerate(&line, data);
	prefix = get_path_prefix(line, data);
	data->sprite.img = malloc(sizeof(t_img) * data->sprite.frames);
	if (!data->sprite.img)
	{
		free(prefix);
		c3d_exit(ERR_MALLOC, data);
	}
	i = 0;
	while (i < data->sprite.frames)
	{
		data->sprite.img[i].img = NULL;
		data->sprite.img[i].addr = NULL;
		i++;
	}
	get_sprites_from_directory(data, &data->sprite, prefix);
	return (1);
}

static int	get_sprite_framerate(char **line, t_data *data)
{
	int	framerate;

	ft_strspn_skip(line, " \t");
	if (!ft_isdigit(**line))
		c3d_exit(ERR_FILE_FORMAT_ELEMENT, data);
	framerate = ft_atoi(*line);
	ft_istype_skip_p(line, ft_isdigit);
	ft_strspn_skip(line, " \t");
	return (framerate);
}

static void	get_sprites_from_directory(t_data *data, t_sprite *s, char *pre)
{
	char	*path;
	int		i;

	i = 0;
	while (i < s->frames)
	{
		path = get_full_path(pre, i, data);
		s->img[i].img = mlx_xpm_file_to_image(data->mlx.mlx, path, \
			&s->img[i].size[X], &s->img[i].size[Y]);
		free(path);
		if (!s->img[i].img)
			break ;
		s->img[i].addr = (int *)mlx_get_data_addr(s->img[i].img, \
			&s->img[i].bpp, &s->img[i].line, &s->img[i].endian);
		if (!s->img[i].addr)
			break ;
		s->img[i].line >>= 2;
		i++;
	}
	free(pre);
	if (i != s->frames)
		c3d_exit(ERR_XPM_TO_IMG, data);
}

static int	get_bonus_texture(t_data *data, char *line, t_img *texture)
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
