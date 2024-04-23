/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:11:37 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/23 19:10:31 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx(t_data *data);
static void	init_map_variables(t_map *map);
static void	init_texture(t_img *texture);
static void	init_player_variables(t_player *player);

/* Initialises all variables in the data struct and its children */
void	init_data(t_data *data)
{
	int	i;

	data->file = NULL;
	data->objects = NULL;
	init_mlx(data);
	init_map_variables(&data->map);
	init_player_variables(&data->player);
	init_ray_variables(&data->ray);
	init_mouse_variables(&data->mouse);
	data->sprite.i = 0;
	data->sprite.transparency_color = 0;
	data->sprite.frames = 0;
	data->bonus = 0;
	data->frame = 0;
	i = 0;
	while (i < WINX)
		data->zbuffer[i++] = 0.0;
	return ;
}

/* Initialises the mlx variables */
static void	init_mlx(t_data *data)
{
	data->mlx.window = NULL;
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		c3d_exit(ERR_MLX_INIT, data);
	data->mlx.window = mlx_new_window(data->mlx.mlx, WINX, WINY, "QUAKE 3D");
	if (!data->mlx.window)
		c3d_exit(ERR_MLX_WINDOW, data);
	data->mlx.win_img = get_img(data, WINX, WINY);
	data->mlx.win_img->size[X] = WINX;
	data->mlx.win_img->size[Y] = WINY;
	hook(data);
}

/* Initialises the map variables */
static void	init_map_variables(t_map *map)
{
	map->grid = NULL;
	init_texture(&map->elements.north);
	init_texture(&map->elements.south);
	init_texture(&map->elements.west);
	init_texture(&map->elements.east);
	init_texture(&map->elements.sprite);
	init_texture(&map->elements.door);
	map->elements.ceiling = -1;
	map->elements.floor = -1;
	map->size[X] = -1;
	map->size[Y] = -1;
	map->spawn[X] = -1;
	map->spawn[Y] = -1;
	map->player_dir[X] = -2;
	map->player_dir[Y] = -2;
	map->offset_y = 0.0;
	map->objects = 0;
}

/* Initialises the texture variables */
static void	init_texture(t_img *texture)
{
	texture->img = NULL;
	texture->addr = NULL;
	texture->bpp = 0;
	texture->line = 0;
	texture->endian = 0;
	texture->size[X] = 0;
	texture->size[Y] = 0;
}

/* Initialises the player variables */
static void	init_player_variables(t_player *player)
{
	player->pos[X] = 0.0;
	player->pos[Y] = 0.0;
	player->dir[X] = 0.0;
	player->dir[Y] = 0.0;
	player->plane[X] = 0.0;
	player->plane[Y] = 0.0;
	player->move_speed = MOVE_SPEED;
	player->rot_speed = ROTATE_SPEED;
}
