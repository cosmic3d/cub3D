/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:41:21 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/25 15:29:31 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_conversion(int c, int fd)
{
	char	ch;

	ch = (char)c;
	write(fd, &ch, 1);
	return (1);
}
