/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:15:48 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/25 15:29:27 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	call_conversion(const char *format, va_list ap, int fd, int i)
{
	int	len;

	len = 0;
	if (format[i] == 'c')
		len = char_conversion(va_arg(ap, int), fd);
	else if (format[i] == 's')
		len = str_conversion(va_arg(ap, char *), fd);
	else if (format[i] == 'p')
		len = ptr_conversion(va_arg(ap, uintptr_t), fd);
	else if (format[i] == 'd' || format[i] == 'i')
		len = int_conversion(va_arg(ap, int), fd);
	else if (format[i] == 'u')
		len = uint_conversion(va_arg(ap, uint32_t), fd);
	else if (format[i] == 'x' || format[i] == 'X')
		len = hex_conversion(va_arg(ap, size_t), fd, format[i]);
	else if (format[i] == '%')
		len = write(fd, "%", 1);
	return (len);
}
