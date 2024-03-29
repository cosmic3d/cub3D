/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:54:53 by jenavarr          #+#    #+#             */
/*   Updated: 2024/03/29 11:39:28 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* EN ESTE ARCHIVO SE REALIZARÁN ALGUNAS FUNCIONES QUE CREA UTILES PARA EL RAYCASTER,
INCLUSO EL PROPIO RAYCASTER */

#include "cub3d.h"

void	initialize_variables(t_data *data)
{
	data->player.pos[X] = data->map.spawn[X] + 0.5;
	data->player.pos[Y] = data->map.spawn[Y] + 0.5;
	data->player.dir[X] = data->map.player_dir[X];
	data->player.dir[Y] = data->map.player_dir[Y];
	data->player.plane[X] = abs(data->player.dir[Y]) * 0.66;
	data->player.plane[Y] = abs(data->player.dir[X]) * 0.66;
}

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
