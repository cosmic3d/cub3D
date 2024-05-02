/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:23:55 by apresas-          #+#    #+#             */
/*   Updated: 2024/05/01 17:49:29 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

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
