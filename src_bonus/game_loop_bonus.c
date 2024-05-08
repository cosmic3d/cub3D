/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:40:42 by apresas-          #+#    #+#             */
/*   Updated: 2024/05/08 12:49:41 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	game_loop(t_data *data)
{
	static int	frame;
	frame++;
	render(data);
	if (frame % data->sprite.framerate == 0)
	{
		data->sprite.i = (data->sprite.i + 1) % data->sprite.frames;
	}
	return (0);
}
