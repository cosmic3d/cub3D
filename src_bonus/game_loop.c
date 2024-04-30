/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:40:42 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/30 15:44:22 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

int	game_loop(t_data *data)
{
	render(data);
	data->frame++;
	if (data->frame % data->sprite.framerate == 0)
	{
		data->sprite.i = (data->sprite.i + 1) % data->sprite.frames;
	}
	return (0);
}
