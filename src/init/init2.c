/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:53:41 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/30 18:21:46 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
