/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:33:53 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/26 18:10:59 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Prints the received error message to STDOUT following a certain format */
int	c3d_error(char *error)
{
	ft_printf_fd(2, "%sError\n%s%s\n", F_RED, RESET, error);
	return (FAILURE);
}

/* If an error is provided, c3d_error() will display it. Then, exit(1) is called
If no error is provided, then exit(0) is called */
void	c3d_exit(char *error)
{
	if (!error)
		exit(EXIT_SUCCESS);
	c3d_error(error);
	exit(EXIT_FAILURE);
}
