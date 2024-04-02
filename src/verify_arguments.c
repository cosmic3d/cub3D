/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:18:25 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/02 12:45:38 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
verify arguments:

- argc > 2
- argc < 2
- argv[1][0] == 0 //?
- argv[1] ! ".cub"
- argv[1] len <= 4
- argv[1] ! contains only valid characters for a file path //?
*/

/*
Checks that the amount of arguments is the appropriate one and also that the
argument that is provided ends in ".cub"
*/
int	verify_arguments(int argc, char **argv)
{
	//int	fd;

	if (argc > 2)
		return (c3d_error(ERR_TOO_MANY_ARGS));
	else if (argc < 2)
		return (c3d_error(ERR_TOO_FEW_ARGS));
	if (ft_strlen(argv[1]) <= 4)
		return (c3d_error(ERR_INVALID_FILEPATH));
	if (ft_strrcmp(argv[1], ".cub") != 0)
		return (c3d_error(ERR_INVALID_FILE_EXTENSION));
	return (SUCCESS);
}
