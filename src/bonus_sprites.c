/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:20:23 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/17 17:18:26 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*

Sprites will be stationary (OBVIOUSLY)

They will be indicated in the map with 'S'.

They will behave like a '0' tile, except there will be a sprite there.

Sprites will always have the same image, nothing special on the map.cub file.

They will always face the player.

They will be given a certain hardcoded height. Depending on the sprite.

*/

// static double *get_sprites_proximity(t_data *data, int count);
static t_sprite	*get_sprites_array(t_data *data, int count);
// static t_sprite	*get_sprites_in_proximity_order(t_data *data);
static int	get_furthest_sprite(t_sprite *sprites, int count);

static void	get_sprite_transform(t_sprite_data *d, t_player *p, t_sprite s)
{
	double	pos[2];
	double	invDet;//figure out better name

	pos[X] = s.pos[X] - p->pos[X];
	pos[Y] = s.pos[Y] - p->pos[Y];
	invDet = 1.0 / ((p->plane[X] * p->dir[Y]) - (p->dir[X] * p->plane[Y]));
	d->transform[X] = invDet * ((p->dir[Y] * pos[X]) - (p->dir[X] * pos[Y]));
	d->transform[Y] = invDet * ((-p->plane[Y] * pos[X]) + (p->plane[X] * pos[Y]));
	return ;
}

void	bonus_draw_sprites(t_data *data)
{
	t_sprite		*sprites;
	t_sprite_data	d;

	sprites = get_sprites_array(data, data->sprite_count);
	// double	pos[2];
	int		i;
	// double	invDet;
	// double	transform[2];
	int		sprite_px;
	int		drawStart[2];
	int		drawEnd[2];
	int		x;
	int		y;

	int tex[2];
	int	dx;
	int	color;

	int texWidth = data->map.elements.sprite.size[X];
	int texHeight = data->map.elements.sprite.size[Y];

	int loop_count = 0;

	while (loop_count < data->sprite_count) // some rule
	{
		debug_check();
		i = get_furthest_sprite(sprites, data->sprite_count);
		// ft_printf("furthest sprite = sprite[%d]\n", i);
		// pos[X] = sprites[i].pos[X] - data->player.pos[X];
		// pos[Y] = sprites[i].pos[Y] - data->player.pos[Y];
		// printf("sprite pos[X] = %f\n", sprites[i].pos[X]);
		// printf("sprite pos[Y] = %f\n", sprites[i].pos[Y]);
		// printf("corrected pos[X] = %f\n", sprites[i].pos[X]);
		// printf("corrected pos[Y] = %f\n", sprites[i].pos[Y]);

		// invDet = 1.0 / ((data->player.plane[X] * data->player.dir[Y]) - (data->player.dir[X] * data->player.plane[Y]));
		// printf("invDet = %f\n", invDet);

		// transform[X] = invDet * ((data->player.dir[Y] * pos[X]) - (data->player.dir[X] * pos[Y]));
		// transform[Y] = invDet * ((-data->player.plane[Y] * pos[X]) + (data->player.plane[X] * pos[Y]));
		// printf("transform[X] = %f\n", transform[X]);
		// printf("transform[Y] = %f\n", transform[Y]);

		get_sprite_transform(&d, &data->player, sprites[i]);
		printf("newtransform[X] = %f\n", d.transform[X]);
		printf("newtransform[Y] = %f\n", d.transform[Y]);
		sprite_px = (int)((WINX / 2) * (1 + d.transform[X] / d.transform[Y]));
		printf("sprite_px = %d\n", sprite_px);

		// get_sprite_transform(X, data->player, dat)
		d.size[Y] = abs((int)(WINY / d.transform[Y]));
		// printf("d.size[Y] = %d\n", d.size[Y]);
		d.size[X] = abs((int)(WINY / d.transform[Y]));
		// printf("d.size[X] = %d\n", d.size[X]);

		drawStart[Y] = ((WINY - d.size[Y]) >> 1) + data->map.offset_y;
		if (drawStart[Y] < 0)
			drawStart[Y] = 0;
		printf("offset = %f\n", data->map.offset_y);
		printf("drawStart[Y] = %d\n", drawStart[Y]);
		drawEnd[Y] = d.size[Y] / 2 + WINY / 2;
		if (drawEnd[Y] >= WINY)
			drawEnd[Y] = WINY - 1;
		printf("drawEnd[Y] = %d\n", drawEnd[Y]);


		drawStart[X] = -d.size[X] / 2 + sprite_px;
		if (drawStart[X] < 0)
			drawStart[X] = 0;
		printf("drawStart[X] = %d\n", drawStart[X]);
		drawEnd[X] = d.size[X] / 2 + sprite_px;
		if (drawEnd[X] >= WINX)
			drawEnd[X] = WINX - 1;
		printf("drawEnd[X] = %d\n", drawEnd[X]);
	
		x = drawStart[X];
		while (x < drawEnd[X])
		{
			// printf("x = %d\n", x);
			tex[X] = (256 * (x - ((-d.size[X] / 2) + sprite_px)) * texWidth / d.size[X]) / 256;
			// printf("tex[X] = %d\n", tex[X]);
			if (d.transform[Y] > 0 && x > 0 && x < WINX && d.transform[Y] < data->zbuffer[x])
			{
				y = drawStart[Y];
				while (y < drawEnd[Y])
				{
					// printf("y = %d\n", y);
					dx = y - (WINY / 2) + (d.size[Y] / 2);
					tex[Y] = ((dx * texHeight) / d.size[Y]);
					// ft_printf("tex[%d][%d]\n", tex[X], tex[Y]);
					color = *(data->map.elements.sprite.addr + (tex[Y] * texWidth) + tex[X]);
					if (color)
						put_pixel(data->mlx.win_img, x, y - data->map.offset_y, color);
					// data->mlx.win_img->addr[y * data->mlx.win_img->line/4 + x] = (t_uint)color;
					y++;
				}
			}
			x++;
		}
		loop_count++;
	}
}

static int	get_furthest_sprite(t_sprite *sprites, int count)
{
	int		i;
	int		furthest;
	double	dist;

	i = 0;
	furthest = 0;
	dist = 0.0;
	while (i < count)
	{
		if (sprites[i].dist > dist)
		{
			furthest = i;
			dist = sprites[i].dist;
		}
		i++;
	}
	printf("Sprite[%d].dist = %f\n", furthest, sprites[furthest].dist);
	sprites[furthest].dist = -1.0;
	return (furthest);
}

static t_sprite	*get_sprites_array(t_data *data, int count)
{
	t_sprite	*sprites;
	int			i;
	int			j;
	int			k;

	i = -1;
	sprites = malloc(sizeof(t_sprite) * (count));
	if (!sprites)
		c3d_exit(ERR_MALLOC);
	k = 0;
	i = -1;
	while (++i < data->map.size[Y])
	{
		j = -1;
		while (++j < data->map.size[X])
		{
			// ft_printf("checking on map[%d][%d]\n", i, j);
			if (data->map.grid[i][j] == 'O')
			{
				// ft_printf("found a sprite in grid[%d][%d]\n", i, j);
				sprites[k].pos[X] = 0.5 + i;
				sprites[k].pos[Y] = 0.5 + j;
				sprites[k].dist = ((data->player.pos[X] - sprites[k].pos[X]) * (data->player.pos[X] - sprites[k].pos[X]) + \
				(data->player.pos[Y] - sprites[k].pos[Y]) * (data->player.pos[Y] - sprites[k].pos[Y]));
				k++;
			}
		}
	}
	return (sprites);
}

// static double *get_sprites_proximity(t_data *data, int count)
// {
// 	double	player[2];

// 	player[X] = data->player.pos[X];
// 	player[Y] = data->player.pos[Y];
	
// }
