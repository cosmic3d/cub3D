/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:18:25 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/27 13:19:04 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Checks that the amount of arguments is the appropriate one and also that the
argument that is provided ends in ".cub"
*/
bool	verify_arguments(int argc, char **argv)
{
	int	fd;

	if (argc > 2)
		return (!c3d_error(ERR_TOO_MANY_ARGS));
	else if (argc < 2)
		return (!c3d_error(ERR_TOO_FEW_ARGS));
	if (ft_strrcmp(argv[1], ".cub") != 0)
		return (!c3d_error(ERR_INVALID_FILE_EXTENSION));
	if (ft_strlen(argv[1]) <= 4)
		return (!c3d_error(errorxd));
/* 	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		return (!c3d_error(ERR_CANNOT_OPEN_FILE));
	}
	close(fd); */
	return (true);
}
