/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:43:23 by jenavarr          #+#    #+#             */
/*   Updated: 2024/03/29 14:53:41 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_data *data)
{
	set_floor_ceiling(data);
	/* SE REALIZAN LOS CÁLCULOS PARA DIBUJAR EN LA */
	/* int		x;

	x = 0;
	while (x < WINX)
	{
		cast_ray(data, x);
		x++;
	} */
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, data->mlx.win_img->img, 0, 0);
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
