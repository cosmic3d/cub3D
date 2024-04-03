/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:51:36 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/04 00:14:39 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TESTING
const int mapa_test[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 'W', 0, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
};

void	rotate_player(t_data *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir[X];
	data->player.dir[X] = data->player.dir[X] * cos(angle) - \
	data->player.dir[Y] * sin(angle);
	data->player.dir[Y] = old_dir_x * sin(angle) + \
	data->player.dir[Y] * cos(angle);
	old_plane_x = data->player.plane[X];
	data->player.plane[X] = data->player.plane[X] * cos(angle) - \
	data->player.plane[Y] * sin(angle);
	data->player.plane[Y] = old_plane_x * sin(angle) + \
	data->player.plane[Y] * cos(angle);
}
