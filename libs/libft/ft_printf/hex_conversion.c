/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:17:33 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/25 15:29:35 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_conversion(size_t hex, int fd, char letter_case)
{
	if (!hex)
		return (write(fd, "0", 1));
	ft_puthex_case_fd(hex, letter_case - 23, fd);
	return (hexlen(hex));
}

int	hexlen(size_t hex)
{
	int	len;

	len = 0;
	while (hex / 16 != 0)
	{
		hex /= 16;
		len++;
	}
	if (hex > 0)
		len++;
	return (len);
}
