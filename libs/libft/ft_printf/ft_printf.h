/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:55:43 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/25 13:55:44 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "../libft.h"

// utils utils, possibly replaced in the future for a libft alternative
int	hexlen(size_t hex);

int	call_conversion(const char *format, va_list ap, int fd, int i);
int	char_conversion(int c, int fd);
int	str_conversion(char *str, int fd);
int	ptr_conversion(uintptr_t ptr, int fd);
int	int_conversion(int num, int fd);
int	uint_conversion(unsigned int num, int fd);
int	hex_conversion(size_t hex, int fd, char letter_case);

#endif // FT_PRINTF_H
