/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:54:53 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/05 15:25:44 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* EN ESTE ARCHIVO SE REALIZARÁN ALGUNAS FUNCIONES QUE CREA UTILES PARA EL RAYCASTER,
INCLUSO EL PROPIO RAYCASTER */

//TESTING
/* const int mapa_test[5][5] = {
	{'1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1'}
}; */

#include "cub3d.h"

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
		calculate_step(data);
		check_hit(data);
		calculate_perp_dist(data);
		draw_vert_stripe(data, x);
	}
}

void	calculate_step(t_data *data)
{
	// Calculamos la primera distancia que recorre el rayo hasta la siguiente pared en ambas direcciones
	if (data->ray.ray_dir[X] < 0)
	{
		data->ray.step[X] = -1;
		data->ray.side_dist[X] = (data->player.pos[X] - data->ray.map[X]) * data->ray.delta_dist[X];
	}
	else
	{
		data->ray.step[X] = 1;
		data->ray.side_dist[X] = (data->ray.map[X] + 1.0 - data->player.pos[X]) * data->ray.delta_dist[X];
	}
	if (data->ray.ray_dir[Y] < 0)
	{
		data->ray.step[Y] = -1;
		data->ray.side_dist[Y] = (data->player.pos[Y] - data->ray.map[Y]) * data->ray.delta_dist[Y];
	}
	else
	{
		data->ray.step[Y] = 1;
		data->ray.side_dist[Y] = (data->ray.map[Y] + 1.0 - data->player.pos[Y]) * data->ray.delta_dist[Y];
	}
}

void check_hit(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist[X] < data->ray.side_dist[Y])
		{
			data->ray.side_dist[X] += data->ray.delta_dist[X];
			data->ray.map[X] += data->ray.step[X];
			data->ray.side[Y] = 0;
			data->ray.side[X] = 1;
			if (data->ray.step[X] < 0)
				data->ray.side[X] = -1;
		}
		else
		{
			data->ray.side_dist[Y] += data->ray.delta_dist[Y];
			data->ray.map[Y] += data->ray.step[Y];
			data->ray.side[X] = 0;
			data->ray.side[Y] = 1;
			if (data->ray.step[Y] < 0)
				data->ray.side[Y] = -1;
		}
		if (data->map.grid[data->ray.map[Y]][data->ray.map[X]] == WALL)
			data->ray.hit = 1;
	}
}

void calculate_perp_dist(t_data *data)
{
	if (data->ray.side[X] != 0)
		data->ray.perp_wall_dist = data->ray.side_dist[X] - data->ray.delta_dist[X];
	else
		data->ray.perp_wall_dist = data->ray.side_dist[Y] - data->ray.delta_dist[Y];
}

void draw_vert_stripe(t_data *data, int x)
{
	int	y;
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color; //Provisional para ver si se pinta bien la pared

	line_height = (int)(WINY / data->ray.perp_wall_dist);
	draw_start = WINY / 2 - line_height / 2 ;
	draw_end = line_height / 2 + WINY / 2;
	y = draw_start - 1;
	if (data->ray.side[X] == 1 && data->ray.side[Y] == 0)
		color = RED;
	else if (data->ray.side[X] == -1 && data->ray.side[Y] == 0)
		color = BLUE;
	else if (data->ray.side[Y] == 1 && data->ray.side[X] == 0)
		color = GREEN;
	else if (data->ray.side[Y] == -1 && data->ray.side[X] == 0)
		color = YELLOW;
	else // debug
	{
		ft_printf("draw_vert_stripe else\n");
		exit(1);
	}
	while (++y < draw_end)
		put_pixel(data->mlx.win_img, x, y, color);
}
