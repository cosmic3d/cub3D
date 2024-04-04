/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:21:46 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/21 17:10:39 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int number)
{
	int	len;

	len = 1;
	if (number < 0)
		len++;
	while (number / 10 != 0)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

int	ft_uintlen(unsigned int number)
{
	int	len;

	len = 1;
	while (number / 10 != 0)
	{
		number = number / 10;
		len++;
	}
	return (len);
}
