/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:08:28 by jenavarr          #+#    #+#             */
/*   Updated: 2024/03/29 12:06:48 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*get_img(t_data *data, int width, int height)
{
	t_img	*img_p;

	img_p = (t_img *)malloc(sizeof(t_img));
	img_p->img = mlx_new_image(data->mlx.mlx, width, height);
	img_p->addr = mlx_get_data_addr(img_p->img, \
	&img_p->bpp, &img_p->line, &img_p->endian);
	if (!img_p->addr)
		c3d_exit("Failed to get image address");
	return (img_p);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= WINX || y >= WINY || x < 0 || y < 0)
		return ;
	pixel = img->addr + (y * img->line) + (x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}
