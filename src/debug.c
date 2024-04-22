/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:01:28 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/22 20:25:50 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	print_map_grid(t_data *data)
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
	(void)data;
	// ft_printf("----------------------------\n");
	// ft_printf("DEBUG: Map elements:\n");
	// ft_printf("----------------------------\n");
	// ft_printf("Textures:\n");
	// ft_printf(" North = \"%s\"\n", data->textures.north);
	// ft_printf(" South = \"%s\"\n", data->textures.south);
	// ft_printf(" West = \"%s\"\n", data->textures.west);
	// ft_printf(" East = \"%s\"\n", data->textures.east);
	// ft_printf("Colors:\n");
	// ft_printf(" Floor = %d\n", data->textures.floor);
	// ft_printf(" Ceiling = %d\n", data->textures.ceiling);
	// ft_printf("----------------------------\n");
}

void	debug_check(void)
{
	static int	n;

	n++;
	ft_printf("Check %d\n", n);
}

void	print_data(t_data *data)
{
	ft_printf("----------------------------\n");
	ft_printf("DEBUG: Print data\n");
	print_map_elements(data);
	print_map_grid(data);
	ft_printf("Player Position = [%d][%d]\n", data->map.spawn[X], \
		data->map.spawn[Y]);
	ft_printf("Player direction = [%d][%d]\n", data->map.player_dir[X], \
		data->map.player_dir[Y]);
	ft_printf("----------------------------\n");
}

void imprimirArray2D(t_data *data) {
    for (int i = 0; i < data->map.size[Y]; i++) {
        for (int j = 0; j < data->map.size[X]; j++) {
            printf("%c ", data->map.grid[i][j]);
        }
        printf("\n");
    }
}
*/