/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:20:23 by apresas-          #+#    #+#             */
/*   Updated: 2024/05/08 12:49:41 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	sort_objects_by_distance(t_object *sprites, t_player p, int count);
static void	get_sprite_transform(t_sprite_d *d, t_player *p, t_object s);
static void	get_draw_limits(int xy, t_sprite_d *sd, t_data *d, int offset);
static void	draw_sprite_column(t_sprite_d *sdata, t_data *data, int x);

void	bonus_draw_sprites(t_data *data, t_object *obj)
{
	t_sprite_d		sdata;
	int				i;
	int				x;

	sort_objects_by_distance(obj, data->player, data->map.objects);
	i = -1;
	while (++i < data->map.objects)
	{
		get_sprite_transform(&sdata, &data->player, obj[i]);
		if (sdata.transform[Y] <= 0)
			continue ;
		get_draw_limits(X, &sdata, data, data->map.offset_y);
		get_draw_limits(Y, &sdata, data, data->map.offset_y);
		x = sdata.draw_start[X];
		while (x <= sdata.draw_end[X] && sdata.iter[X] < sdata.size[X])
		{
			if (sdata.transform[Y] < data->zbuffer[x])
				draw_sprite_column(&sdata, data, x);
			sdata.iter[X] += sdata.step[X];
			x++;
		}
	}
}

static void	sort_objects_by_distance(t_object *obj, t_player p, int count)
{
	t_object	tmp;
	int			i;
	int			j;

	i = -1;
	while (++i < count)
	{
		obj[i].dist = fabs(pow(p.pos[X] - obj[i].pos[X], 2) + \
		pow(p.pos[Y] - obj[i].pos[Y], 2));
	}
	i = -1;
	while (++i < count - 1)
	{
		j = -1;
		while (++j < count - i - 1)
		{
			if (obj[j].dist < obj[j + 1].dist)
			{
				tmp = obj[j];
				obj[j] = obj[j + 1];
				obj[j + 1] = tmp;
			}
		}
	}
	return ;
}

static void	get_sprite_transform(t_sprite_d *d, t_player *p, t_object s)
{
	double	sprite_offset[2];
	double	inverse_determinant;

	inverse_determinant = 1.0 / \
		((p->plane[X] * p->dir[Y]) - (p->dir[X] * p->plane[Y]));
	sprite_offset[X] = s.pos[X] - p->pos[X];
	sprite_offset[Y] = s.pos[Y] - p->pos[Y];
	d->transform[X] = inverse_determinant * \
		((p->dir[Y] * sprite_offset[X]) - (p->dir[X] * sprite_offset[Y]));
	d->transform[Y] = inverse_determinant * \
		((-p->plane[Y] * sprite_offset[X]) + (p->plane[X] * sprite_offset[Y]));
	return ;
}

static void	get_draw_limits(int xy, t_sprite_d *sd, t_data *d, int offset)
{
	int	center_on_screen;

	if (xy == X)
		center_on_screen = (int)((WINX / 2) * \
		(1 + sd->transform[X] / sd->transform[Y]));
	sd->size[xy] = d->sprite.img[d->sprite.i].size[xy];
	sd->on_screen_size[xy] = abs((int)(WINY / sd->transform[Y]));
	sd->step[xy] = 1.0 * sd->size[xy] / sd->on_screen_size[xy];
	sd->iter[xy] = 0.0;
	if (xy == X)
		sd->draw_start[xy] = center_on_screen - (sd->on_screen_size[xy] >> 1);
	else if (xy == Y)
		sd->draw_start[xy] = ((WINY - sd->on_screen_size[xy]) >> 1) - offset;
	if (sd->draw_start[xy] < 0)
	{
		sd->iter[xy] = sd->step[xy] * -sd->draw_start[xy];
		sd->draw_start[xy] = 0;
	}
	if (xy == X)
		sd->draw_end[xy] = center_on_screen + (sd->on_screen_size[xy] >> 1);
	else if (xy == Y)
		sd->draw_end[xy] = ((WINY + sd->on_screen_size[xy]) >> 1) - offset;
	if (sd->draw_end[xy] >= d->mlx.win_img->size[xy])
		sd->draw_end[xy] = d->mlx.win_img->size[xy] - 1;
	sd->iter_start_y = sd->iter[Y];
}

static void	draw_sprite_column(t_sprite_d *sdata, t_data *data, int x)
{
	int	*window;
	int	*texture;
	int	y;
	int	color;

	window = data->mlx.win_img->addr + x;
	texture = data->sprite.img[data->sprite.i].addr + (int)sdata->iter[X];
	y = sdata->draw_start[Y];
	sdata->iter[Y] = sdata->iter_start_y;
	while (y <= sdata->draw_end[Y] && (int)sdata->iter[Y] < sdata->size[Y])
	{
		color = texture[(int)sdata->iter[Y] * sdata->size[X]];
		if (color != data->sprite.transparency_color)
			window[y * WINX] = color;
		sdata->iter[Y] += sdata->step[Y];
		y++;
	}
}
