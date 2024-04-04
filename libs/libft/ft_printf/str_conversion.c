/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:01:25 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/25 15:29:47 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_conversion(char *str, int fd)
{
	if (!str)
		return (write(fd, "(null)", 6));
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
