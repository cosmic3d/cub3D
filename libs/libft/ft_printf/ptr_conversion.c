/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:38:51 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/25 15:29:43 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_conversion(uintptr_t ptr, int fd)
{
	int	len;

	len = 2;
	write(fd, "0x", 2);
	if (!ptr)
		return (len += write(fd, "0", 1));
	len += hexlen(ptr);
	ft_puthex_case_fd(ptr, 'a', fd);
	return (len);
}
