/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:08:17 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/25 15:29:50 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uint_conversion(unsigned int num, int fd)
{
	ft_putnbr_unsigned_fd(num, fd);
	return (ft_uintlen(num));
}
