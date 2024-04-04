/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:23:55 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/04 13:12:27 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		c3d_exit("Error\nFailed to initialize mlx\n");
	data->mlx.window = mlx_new_window(data->mlx.mlx, WINX, WINY, "QUAKE 3D");
	if (!data->mlx.window)
		c3d_exit("Error\nFailed to create window\n");
	data->mlx.texture_size = 64;
	data->mlx.win_img = get_img(data, WINX, WINY);
	hook(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (verify_arguments(argc, argv) == FAILURE)
		return (1);
	parse_argument(&data, argv[1]);
	init_mlx(&data);
	initialize_variables(&data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
