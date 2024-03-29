/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:23:55 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/29 14:55:30 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	hook(&data);
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
