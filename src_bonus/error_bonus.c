/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:33:53 by apresas-          #+#    #+#             */
/*   Updated: 2024/05/01 17:49:36 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

static void	free_grid(char **grid, int size[2]);
static void	destroy_images(t_data *data);

/* Prints the received error message to STDOUT following a certain format */
int	c3d_error(const char *error)
{
	ft_printf_fd(2, "%sError\n%s%s\n", F_RED, RESET, error);
	return (FAILURE);
}

/* If an error is provided, c3d_error() will display it. Then, exit(1) is called
If ERR_GENERIC is provided, no error is displayed, then exit(1) is called
If no error is provided, no error is displayed, then exit(0) is called */
int	c3d_exit(const char *error, t_data *data)
{
	int	exit_status;

	exit_status = EXIT_FAILURE;
	if (!error)
		exit_status = EXIT_SUCCESS;
	else if (*error)
		c3d_error(error);
	if (data->file)
		ft_free_array((void **)data->file);
	if (data->map.grid)
		free_grid(data->map.grid, data->map.size);
	if (data->objects)
		free(data->objects);
	destroy_images(data);
	if (data->mlx.window)
		mlx_destroy_window(data->mlx.mlx, data->mlx.window);
	if (data->mlx.win_img)
		free(data->mlx.win_img);
	if (data->mlx.mlx)
		free(data->mlx.mlx);
	exit(exit_status);
	return (FAILURE);
}

int	c3d_close_window_exit(t_data *data)
{
	if (data->file)
		ft_free_array((void **)data->file);
	if (data->map.grid)
		free_grid(data->map.grid, data->map.size);
	if (data->objects)
		free(data->objects);
	destroy_images(data);
	if (data->mlx.window)
		mlx_destroy_window(data->mlx.mlx, data->mlx.window);
	if (data->mlx.win_img)
		free(data->mlx.win_img);
	if (data->mlx.mlx)
		free(data->mlx.mlx);
	exit(EXIT_SUCCESS);
	return (SUCCESS);
}

static void	destroy_images(t_data *data)
{
	int	i;

	if (data->map.elements.north.img)
		mlx_destroy_image(data->mlx.mlx, data->map.elements.north.img);
	if (data->map.elements.south.img)
		mlx_destroy_image(data->mlx.mlx, data->map.elements.south.img);
	if (data->map.elements.west.img)
		mlx_destroy_image(data->mlx.mlx, data->map.elements.west.img);
	if (data->map.elements.east.img)
		mlx_destroy_image(data->mlx.mlx, data->map.elements.east.img);
	if (data->map.elements.door.img)
		mlx_destroy_image(data->mlx.mlx, data->map.elements.door.img);
	if (data->map.elements.sprite.img)
		mlx_destroy_image(data->mlx.mlx, data->map.elements.sprite.img);
	if (data->mlx.win_img->img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.win_img->img);
	if (!data->sprite.img)
		return ;
	i = -1;
	while (++i < data->sprite.frames)
	{
		if (data->sprite.img[i].img)
			mlx_destroy_image(data->mlx.mlx, data->sprite.img[i].img);
	}
	free(data->sprite.img);
}

static void	free_grid(char **grid, int size[2])
{
	int	i;

	i = 0;
	while (i < size[Y])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
