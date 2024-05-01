/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:42:47 by jenavarr          #+#    #+#             */
/*   Updated: 2024/05/01 17:49:32 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

void	hook(t_data *data)
{
	mlx_hook(data->mlx.window, DESTROY_NOTIFY, 0, c3d_close_window_exit, data);
	mlx_hook(data->mlx.window, KEY_PRESS, 1L << 0, keypressed, data);
	mlx_hook(data->mlx.window, BUTTON_MOUSEMOVE, 1L << 6, mousemove, data);
	mlx_hook(data->mlx.window, BUTTON_MOUSEDOWN, 1L << 2, mousepressed, data);
	mlx_hook(data->mlx.window, BUTTON_MOUSEUP, 1L << 3, mousereleased, data);
}

int	keypressed(int keycode, t_data *data)
{
	if (keycode == KEY_RIGHT)
		rotate_player(data, data->player.rot_speed);
	else if (keycode == KEY_LEFT)
		rotate_player(data, -data->player.rot_speed);
	else if (keycode == KEY_W)
		move_forward(data);
	else if (keycode == KEY_S)
		move_back(data);
	else if (keycode == KEY_A)
		move_left(data);
	else if (keycode == KEY_D)
		move_right(data);
	else if (keycode == KEY_E)
		interact_door(data);
	else if (keycode == KEY_ESC)
		c3d_exit(NULL, data);
	else
		return (0);
	return (0);
}

int	mousemove(int x, int y, t_data *data)
{
	int	difference;

	if (data->mouse.pressed == 0 || x < 0 || x >= WINX || y < 0 || y >= WINY)
		return (0);
	data->map.offset_y = (2 * y / (double)WINY - 1) * WINY;
	difference = x - data->mouse.prev_pos[X];
	if (difference == 0)
		return (0);
	rotate_player(data, (data->player.rot_speed / 4) * difference);
	data->mouse.prev_pos[X] = x;
	data->mouse.prev_pos[Y] = y;
	return (0);
}

int	mousepressed(int button, int x, int y, t_data *data)
{
	if (button == MOUSE_LEFTCLICK && x >= 0 && x < WINX && y >= 0 && y < WINY)
	{
		data->mouse.pressed = 1;
		data->mouse.prev_pos[X] = x;
		data->mouse.prev_pos[Y] = y;
	}
	return (0);
}

int mousereleased(int button, int x, int y, t_data *data)
{
	if (button == MOUSE_LEFTCLICK && x >= 0 && x < WINX && y >= 0 && y < WINY)
		data->mouse.pressed = 0;
	return (0);
}
