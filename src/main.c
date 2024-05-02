/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:23:55 by apresas-          #+#    #+#             */
/*   Updated: 2024/05/01 19:29:02 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (verify_arguments(argc, argv) == FAILURE)
		return (1);
	init_data(&data);
	parser(&data, argv[1]);
	mlx_loop_hook(data.mlx.mlx, game_loop, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
