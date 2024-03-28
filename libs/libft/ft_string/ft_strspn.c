/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:22:28 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/28 17:17:48 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Calculates the lenght of the initial segment of str which consists 
entirely of chars in accept
Can also be interpreted as, returns the index at which str contains the first
ocurrence of a character not in accept */
size_t	ft_strspn(const char *str, const char *accept)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	if (!accept)
		return (i);
	while (str[i])
	{
		if (!ft_strchr((char *)accept, str[i]))
			return (i);
		i++;
	}
	return (i);
}
