/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:54:53 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/04 01:08:47 by jenavarr         ###   ########.fr       */
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
	data->player.plane[X] = fabs(data->player.dir[Y]) * 0.66;
	data->player.plane[Y] = fabs(data->player.dir[X]) * 0.66; //TENER CUIDADO LUEGO CUANDO SE UTILIZE EL PLANE PORQUE EL EJE VERTICAL VA AL REVES
	if (data->player.dir[Y] == -1)
		data->player.angle = 0;
	else if (data->player.dir[X] == 1)
		data->player.angle = 90;
	else if (data->player.dir[Y] == 1)
		data->player.angle = 180;
	else if (data->player.dir[X] == -1)
		data->player.angle = 270;
}

void	init_raycasting(t_data *data)
{
	int	x;

	x = -1;
	// Inializamos las variables de la estructura ray
	while (++x < WINX)
	{
		// Calculamos la dirección de la cámara
		data->ray.camera[X] = 2 * x / (double)WINX - 1;
		// Calculamos la dirección del rayo
		data->ray.ray_dir[X] = data->player.dir[X] + data->player.plane[X] * data->ray.camera[X];
		data->ray.ray_dir[Y] = data->player.dir[Y] + data->player.plane[Y] * data->ray.camera[X];
		// Calculamos la posición del jugador en el mapa (este valor es un entero porque luego así determinaremos si hay una pared o no)
		data->ray.map[X] = (int)data->player.pos[X];
		data->ray.map[Y] = (int)data->player.pos[Y];
		// Calculamos la distancia que recorre el rayo hasta la siguiente pared en ambas direcciones (es la inversa de la dirección del rayo)
		data->ray.delta_dist[X] = fabs(1 / data->ray.ray_dir[X]);
		data->ray.delta_dist[Y] = fabs(1 / data->ray.ray_dir[Y]);
		data->ray.hit = 0;
		// Calculamos la PRIMERA distancia que recorre el rayo hasta la siguiente pared en ambas direcciones
		if (data->ray.ray_dir[X] < 0 && --data->ray.step[X] != 42)
			data->ray.side_dist[X] = (data->player.pos[X] - data->ray.map[X]) * data->ray.delta_dist[X];
		else
			data->ray.side_dist[X] = (data->ray.map[X] + 1.0 - data->player.pos[X]) * data->ray.delta_dist[X];
		if (data->ray.ray_dir[Y] < 0 && --data->ray.step[Y] != 42)
			data->ray.side_dist[Y] = (data->player.pos[Y] - data->ray.map[Y]) * data->ray.delta_dist[Y];
		else
			data->ray.side_dist[Y] = (data->ray.map[Y] + 1.0 - data->player.pos[Y]) * data->ray.delta_dist[Y];
	}
}

