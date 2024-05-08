/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:52:17 by apresas-          #+#    #+#             */
/*   Updated: 2024/05/08 12:49:41 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	update_variables(t_data *data)
{
	data->player.pos[X] = data->map.spawn[Y] + 0.5;
	data->player.pos[Y] = data->map.spawn[X] + 0.5;
	data->player.dir[X] = data->map.player_dir[X];
	data->player.dir[Y] = data->map.player_dir[Y];
	data->player.plane[X] = fabs(data->player.dir[Y]) * 0.66;
	data->player.plane[Y] = fabs(data->player.dir[X]) * 0.66;
	if (data->map.player_dir[X] == -1 || data->map.player_dir[Y] == 1)
	{
		data->player.plane[X] *= -1;
		data->player.plane[Y] *= -1;
	}
}

int	parser(t_data *data, char *filepath)
{
	int	file_line;

	data->file = store_file(filepath, data);
	file_line = get_file_elements(data, &data->map.elements, data->file);
	file_line += get_bonus_elements(data, data->file + file_line);
	bonus_parse_map(data, data->file + file_line);
	update_variables(data);
	return (0);
}
