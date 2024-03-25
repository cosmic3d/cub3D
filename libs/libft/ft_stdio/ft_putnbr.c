/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:19:24 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/21 17:15:50 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}
	nbr = 48 + (nbr % 10);
	write(1, &nbr, 1);
}

void	ft_putnbr_unsigned(unsigned int nbr)
{
	if (nbr > 9)
		ft_putnbr_unsigned(nbr / 10);
	nbr = 48 + (nbr % 10);
	write(1, &nbr, 1);
}
