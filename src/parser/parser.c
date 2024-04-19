/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:52:17 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/18 14:15:21 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_texture(t_img *texture)
{
	texture->img = NULL;
	texture->addr = NULL;
	texture->bpp = 0;
	texture->line = 0;
	texture->endian = 0;
	texture->size[X] = 0;
	texture->size[Y] = 0;
}

static void	init_map_variables(t_map *map)
{
	init_texture(&map->elements.north);
	init_texture(&map->elements.south);
	init_texture(&map->elements.west);
	init_texture(&map->elements.east);
	init_texture(&map->elements.sprite);
	init_texture(&map->elements.door);
	map->elements.ceiling = -1;
	map->elements.floor = -1;
	map->grid = NULL;
	map->spawn[X] = -1;
	map->spawn[Y] = -1;
	map->size[X] = -1;
	map->size[Y] = -1;
	map->player_dir[X] = -2;
	map->player_dir[Y] = -2;
}

int	parser(t_data *data, char *filepath)
{
	int	file_line;

	data->sprite_count = 0;
	data->sprites = NULL;
	data->bonus = 0;
	if (ft_strncmp(filepath, "bonus_", 6) == 0)
		data->bonus = 1;
	data->file = store_file(filepath, data);
	init_map_variables(&data->map);
	file_line = get_file_elements(data, &data->map.elements, data->file);
	if (data->bonus)
		file_line += get_bonus_elements(data, data->file + file_line);
	if (data->bonus)
		bonus_parse_map(data, data->file + file_line);
	else
		parse_map(data, data->file + file_line);
	return (0);
}
