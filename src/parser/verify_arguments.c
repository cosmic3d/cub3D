/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:18:25 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/04 13:45:37 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Verifies that the arguments provided to cub3d are valid */
int	verify_arguments(int argc, char **argv)
{
	if (argc > 2)
		c3d_exit(ERR_TOO_MANY_ARGS);
	else if (argc < 2)
		c3d_exit(ERR_TOO_FEW_ARGS);
	if (ft_strlen(argv[1]) <= 4)
		c3d_exit(ERR_INVALID_FILEPATH);
	if (ft_strrcmp(argv[1], ".cub") != 0)
		c3d_exit(ERR_INVALID_FILE_EXTENSION);
	return (SUCCESS);
}
