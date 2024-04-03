/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:42:47 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/02 12:43:29 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hook(t_data *data)
{
	mlx_hook(data->mlx.window, DESTROY_NOTIFY, 0, c3d_exit, NULL);
	mlx_hook(data->mlx.window, KEY_PRESS, 1L<<0, keypressed, data); //MÁSCARA NECESARIA, SINO NO FUNCIONA EN LINUX PERO EN MAC SÍ
	mlx_hook(data->mlx.window, BUTTON_MOUSEDOWN, 1L<<2, mousedown, data);
	/* mlx_hook(data->mlx.window, BUTTON_MOUSEDOWN, 0, keypressed, data);
	mlx_key_hook(data->mlx.window, keypressed, data); */
	/* mlx_hook(sys->mlx_win, BUTTON_MOUSEDOWN, 0, mousedown, sys);
	mlx_hook(sys->mlx_win, BUTTON_MOUSEMOVE, 0, mousemove, sys);
	mlx_hook(sys->mlx_win, BUTTON_MOUSEUP, 0, mouseup, sys); */
}

int	keypressed(int keycode, t_data *data)
{
	ft_printf("Keycode: %d\n", keycode);
	// c3d_exit(NULL);
	if (keycode == KEY_A)
		rotate_player(data, -ROTATE_SPEED);
	if (keycode == KEY_D)
		rotate_player(data, ROTATE_SPEED);
	if (keycode == KEY_ESC)
		c3d_exit(NULL);
	render(data);
	return (0);
}

int	mousedown(int keycode, int x, int y, t_data *data)
{
	ft_printf("Mouse Keycode: %d\n Mouse [X, Y]: [%d,%d]\nData pointer: %p\n", keycode, x, y, data);
	return (0);
}
