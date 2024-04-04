/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:23:59 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/21 18:18:30 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_puthex_fd(size_t hex, int fd)
{
	if (hex > 15)
	{
		ft_puthex_fd(hex / 16, fd);
	}
	if (hex % 16 > 9)
	{
		hex = hex % 16 + 'a' - 10;
	}
	else
	{
		hex = hex % 16 + '0';
	}
	write (fd, &hex, 1);
}

// Letter_case can be either 'A' for uppercase or 'a' for lowercase, be careful
void	ft_puthex_case_fd(size_t hex, int letter_case, int fd)
{
	if (hex > 15)
	{
		ft_puthex_case_fd(hex / 16, letter_case, fd);
	}
	if (hex % 16 > 9)
	{
		hex = hex % 16 + letter_case - 10;
	}
	else
	{
		hex = hex % 16 + '0';
	}
	write (fd, &hex, 1);
}
