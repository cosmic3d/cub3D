/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:43:23 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/09 18:54:28 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// debug
#include <time.h>

void	render(t_data *data)
{
	set_floor_ceiling(data);
	init_raycasting(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, data->mlx.win_img->img, 0, 0);

	static clock_t start;
	static clock_t end;
	end = clock();
	printf("Time since last frame: %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	start = clock();

}

void	set_floor_ceiling(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINX)
	{
		j = 0;
		while (j < WINY)
		{
			if (j < WINY / 2)
				put_pixel(data->mlx.win_img, i, j, CEILING);
			else
				put_pixel(data->mlx.win_img, i, j, FLOOR);
			j++;
		}
		i++;
	}
}
