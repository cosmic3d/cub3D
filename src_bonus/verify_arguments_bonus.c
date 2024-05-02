/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_arguments_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:18:25 by apresas-          #+#    #+#             */
/*   Updated: 2024/05/01 17:49:25 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

/* Verifies that the arguments provided to cub3d are valid */
int	verify_arguments(int argc, char **argv)
{
	if (argc > 2)
		c3d_error(ERR_TOO_MANY_ARGS);
	else if (argc < 2)
		c3d_error(ERR_TOO_FEW_ARGS);
	if (ft_strlen(argv[1]) <= 4)
		c3d_error(ERR_INVALID_FILEPATH);
	if (ft_strrcmp(argv[1], ".cub") != 0)
		c3d_error(ERR_INVALID_FILE_EXTENSION);
	return (SUCCESS);
}