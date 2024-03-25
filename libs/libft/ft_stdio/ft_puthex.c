/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:58:13 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/21 18:18:25 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_puthex(size_t hex)
{
	if (hex > 15)
	{
		ft_puthex(hex / 16);
	}
	if (hex % 16 > 9)
	{
		hex = hex % 16 + 'a' - 10;
	}
	else
	{
		hex = hex % 16 + '0';
	}
	write (1, &hex, 1);
}

// Letter_case can be either 'A' for uppercase or 'a' for lowercase, be careful
void	ft_puthex_case(size_t hex, int letter_case)
{
	if (hex > 15)
	{
		ft_puthex_case(hex / 16, letter_case);
	}
	if (hex % 16 > 9)
	{
		hex = hex % 16 + letter_case - 10;
	}
	else
	{
		hex = hex % 16 + '0';
	}
	write (1, &hex, 1);
}
