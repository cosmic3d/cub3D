/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:01:28 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/04 12:50:27 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_grid(t_data *data)
{
	ft_printf("----------------------------\n");
	ft_printf("DEBUG: Map grid:\n");
	ft_printf("----------------------------\n");
	for (int x = 0; x < data->map.size[Y]; x++)
	{
		for (int y = 0; y < data->map.size[X]; y++)
			printf("%c", data->map.grid[x][y]);
		printf("|\n");
	}
	ft_printf("----------------------------\n");
	ft_printf("Height: %d\nWidth: %d\n", data->map.size[Y], data->map.size[X]);
	ft_printf("----------------------------\n");
}

void	print_map_elements(t_data *data)
{
	ft_printf("----------------------------\n");
	ft_printf("DEBUG: Map elements:\n");
	ft_printf("----------------------------\n");
	ft_printf("Textures:\n");
	ft_printf(" North = \"%s\"\n", data->textures.north);
	ft_printf(" South = \"%s\"\n", data->textures.south);
	ft_printf(" West = \"%s\"\n", data->textures.west);
	ft_printf(" East = \"%s\"\n", data->textures.east);
	ft_printf("Colors:\n");
	ft_printf(" Floor = %d\n", data->textures.floor);
	ft_printf(" Ceiling = %d\n", data->textures.ceiling);
	ft_printf("----------------------------\n");
}

void	debug_check(void)
{
	static int	n;

	n++;
	ft_printf("Check %d\n", n);
}
