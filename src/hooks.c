/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:42:47 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/11 11:29:46 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hook(t_data *data)
{
	mlx_hook(data->mlx.window, DESTROY_NOTIFY, 0, c3d_exit, NULL);
	mlx_hook(data->mlx.window, KEY_PRESS, 1L<<0, keypressed, data); //MÁSCARA NECESARIA, SINO NO FUNCIONA EN LINUX PERO EN MAC SÍ
	mlx_hook(data->mlx.window, BUTTON_MOUSEDOWN, 1L<<2, mousedown, data);
	// mlx_hook(data->mlx.window, BUTTON_MOUSEMOVE, 1L<<6, mousemove, data);
	/* mlx_hook(data->mlx.window, BUTTON_MOUSEDOWN, 0, keypressed, data);
	mlx_key_hook(data->mlx.window, keypressed, data); */
	/* mlx_hook(sys->mlx_win, BUTTON_MOUSEDOWN, 0, mousedown, sys);
	mlx_hook(sys->mlx_win, BUTTON_MOUSEMOVE, 0, mousemove, sys);
	mlx_hook(sys->mlx_win, BUTTON_MOUSEUP, 0, mouseup, sys); */
}

int	keypressed(int keycode, t_data *data)
{
	// int	move_dir[2];

	// printf("Keycode: %d\n", keycode);

	if (keycode == KEY_RIGHT)
		rotate_player(data, ROTATE_SPEED);
	else if (keycode == KEY_LEFT)
		rotate_player(data, -ROTATE_SPEED);
	else if (keycode == KEY_W)
		move_forward(data);
	else if (keycode == KEY_S)
		move_back(data);
	else if (keycode == KEY_A)
		move_left(data);
	else if (keycode == KEY_D)
		move_right(data);
	else if (keycode == KEY_ESC)
		c3d_exit(NULL);
	else
	if (keycode == KEY_ESC)
		c3d_exit(NULL);
	render(data);
	return (0);
}

int	mousedown(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)data;
	(void)keycode;
	//ft_printf("Mouse Keycode: %d\n Mouse [X, Y]: [%d,%d]\nData pointer: %p\n", keycode, x, y, data);
	return (0);
}
