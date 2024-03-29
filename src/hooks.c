/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:42:47 by jenavarr          #+#    #+#             */
/*   Updated: 2024/03/29 11:50:16 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hook(t_data *data)
{
	mlx_hook(data->mlx.window, DESTROY_NOTIFY, 0, c3d_exit, NULL);
	mlx_hook(data->mlx.window, KEY_PRESS, 0, keypressed, data);
	/* mlx_hook(sys->mlx_win, BUTTON_MOUSEDOWN, 0, mousedown, sys);
	mlx_hook(sys->mlx_win, BUTTON_MOUSEMOVE, 0, mousemove, sys);
	mlx_hook(sys->mlx_win, BUTTON_MOUSEUP, 0, mouseup, sys); */
}

int	keypressed(int keycode, t_data *data)
{
	if (keycode == KEY_A)
		rotate_player(data, -ROTATE_SPEED);
	if (keycode == KEY_D)
		rotate_player(data, ROTATE_SPEED);
	if (keycode == KEY_ESC)
		c3d_exit(NULL);
	return (0);
}
