/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:24:38 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/10 13:45:16 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// debug
#include <time.h>

static t_img	*get_wall_texture(t_elements *elements, int side[2])
{
	if (side[X] == 1 && side[Y] == 0)
		return (&elements->west);
	else if (side[X] == -1 && side[Y] == 0)
		return (&elements->east);
	else if (side[X] == 0 && side[Y] == 1)
		return (&elements->south);
	else if (side[X] == 0 && side[Y] == -1)
		return (&elements->north);
	c3d_exit("get_wall_texture unexpected behavior");//
	return (NULL);
}

void	draw_vert_stripe(t_data *data, int x)
{
	int		y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wallX;
	t_img	*texture;

	//get texture for hit wall
	texture = get_wall_texture(&data->map.elements, data->ray.side);

	line_height = (int)(WINY / data->ray.perp_wall_dist);
	draw_start = WINY / 2 - line_height / 2;
	draw_end = draw_start + line_height;

	if (data->ray.side[Y] == 0)
		wallX = data->player.pos[Y] + data->ray.perp_wall_dist * data->ray.ray_dir[Y];
	else
		wallX = data->player.pos[X] + data->ray.perp_wall_dist * data->ray.ray_dir[X];
	wallX -= floor(wallX);

	int	texX = (int)(wallX * (double)(data->mlx.texture_size)); // ? casting
	double	step = 1.0 * data->mlx.texture_size / line_height;

	unsigned int color;
	y = draw_start;
	double texPosD = 0.0;
	int	texPosI = 0;
	// exit(0);
	while (y < draw_end)
	{
		texPosI = (int)texPosD & (data->mlx.texture_size - 1);
		texPosD += step;
		color = get_pixel_color(texture, texX, texPosI);
		put_pixel(data->mlx.win_img, x, y, color);
		// printf("textPosI = %d\n", texPosI);
		y++;
	}


	// Things to do:
	// 1. Figure out, which texture goes into this wall
	// 2. Make able to access the texture (this should be done in the init)
	// 3. Figure out the ratio of the wall texture at the hit point
	// 4. In a loop:
	//		1. Traverse the wall texture vertically
	//		2. Check at the appropriate heights, the color of the pixels of the wall
	//		3. put_pixel with the color
	// Note:
	//	Floor and Ceiling pixels are already painted

}

/*Things I need:
	- Have the textures initialised [OK]
	- Figure out which type of wall is hit (size[X] side[Y])

*/
