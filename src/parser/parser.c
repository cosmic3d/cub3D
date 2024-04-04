/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:52:17 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/04 12:51:10 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TO DO!!
/*
	INIT DATA
		To check if colors were already stored, we have to init them to -1
		Because an RGB of 0,0,0 has a value of 0.
		So we can't do if (*color) to check if we had already created them
		- each of the texture path pointers should be init to NULL
		- textures.stored_values = 0
		Etc.
*/

/* File guidelines:

> TEXTURES:
	-Any amount of one or more empty lines
	-Each element can come in any order
	-Each type of information in an element can be separated by spaces
	-
> MAP:
	- Must only contain 0, 1 and space for the structure
	- Must contain
	- Map must be surrounded by walls (1)
	-
*/

int	parser(t_data *data, int argc, char **argv)
{
	verify_arguments(argc, argv);
	data->file = store_file(argv[1]);
	get_file_elements(data);
	parse_map(data, data->file + data->map.file_i);
	print_map_elements(data);
	print_map_grid(data);
	return (0);
}
