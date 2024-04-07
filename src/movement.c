/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:51:36 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/07 17:59:35 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	printf("Player direction: [%f, %f]\n", data->player.dir[X], data->player.dir[Y]);
	printf("Player plane: [%f, %f]\n\n", data->player.plane[X], data->player.plane[Y]);
	printf("Player position: [%f, %f]\n", data->player.pos[X], data->player.pos[Y]);
}
