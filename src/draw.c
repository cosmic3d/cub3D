/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:09:35 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/11 19:09:35 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawRect(t_data *data, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	if (size < 1)
		return ;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(data->mlx.win_img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
