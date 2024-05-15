/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:53:41 by apresas-          #+#    #+#             */
/*   Updated: 2024/05/08 12:49:41 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_ray_variables(t_ray *ray)
{
	ray->camera = 0.0;
	ray->ray_dir[X] = 0.0;
	ray->ray_dir[Y] = 0.0;
	ray->map[X] = 0;
	ray->map[Y] = 0;
	ray->side_dist[X] = 0.0;
	ray->side_dist[Y] = 0.0;
	ray->delta_dist[X] = 0.0;
	ray->delta_dist[Y] = 0.0;
	ray->perp_wall_dist = 0.0;
	ray->step[X] = 0;
	ray->step[Y] = 0;
	ray->side[X] = 0;
	ray->side[Y] = 0;
	return ;
}

void	init_mouse_variables(t_mouse *mouse)
{
	mouse->prev_pos[X] = 0;
	mouse->prev_pos[Y] = 0;
	mouse->pressed = 0;
	return ;
}
