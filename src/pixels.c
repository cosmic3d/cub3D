/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:08:28 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/11 13:11:41 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*get_img(t_data *data, int width, int height)
{
	t_img	*img_p;

	img_p = (t_img *)malloc(sizeof(t_img));
	img_p->img = mlx_new_image(data->mlx.mlx, width, height);
	img_p->addr = (int *)mlx_get_data_addr(img_p->img, \
	&img_p->bpp, &img_p->line, &img_p->endian);
	if (!img_p->addr)
		c3d_exit("Failed to get image address");
	return (img_p);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	int pixel;

	if (x >= WINX || y >= WINY || x < 0 || y < 0)
		return ;
	pixel = y * (img->line / 4) + x;
	img->addr[pixel] = color;
}

unsigned int get_pixel_color(t_img *image, int x, int y)
{
	// provisional for debugging
	if (x >= image->size[X] || y >= image->size[Y])
		c3d_exit("WARNING: get_pixel_color got out of bounds coordinatesA");
	if (x < 0 || y < 0)
		c3d_exit("WARNING: get_pixel_color got out of bounds coordinatesB");
	//
	return (*(image->addr + y * (image->line / 4) + x));
}
