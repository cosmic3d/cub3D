/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   albert_home_render.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:43:23 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/22 18:05:20 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/time.h>

static void	set_ceiling_and_floor(t_img *window, t_elements elements);

// Al menos para linux esto está guay
static time_t	get_time(void)
{
	static time_t	start_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (!start_time)
		start_time = time.tv_sec * 1000000 + time.tv_usec;
	return ((time.tv_sec * 1000000 + time.tv_usec) - start_time);
}

void	render(t_data *data)
{
	static time_t	last_render;
	time_t			elapsed_time;

	elapsed_time = get_time() - last_render;
	if (last_render && elapsed_time < 5000)
		return ;
	set_ceiling_and_floor(data->mlx.win_img, data->map.elements);
	init_raycasting(data);
	bonus_draw_sprites(data, data->sprites);
	if (data->bonus)
		draw_minimap(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, \
		data->mlx.win_img->img, 0, 0);
	last_render = get_time();
}

static void	set_ceiling_and_floor(t_img *window, t_elements elements)
{
	int		i;
	int		j;

	i = 0;
	while (i < WINX)
	{
		j = 0;
		while (j < WINY >> 1)
			put_pixel(window, i, j++, elements.ceiling);
		while (j < WINY)
			put_pixel(window, i, j++, elements.floor);
		i++;
	}
}
