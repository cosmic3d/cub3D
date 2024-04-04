/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:22:53 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/28 17:18:16 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Calculates the lenght of the initial segment of str which consists 
entirely of chars not in reject
Can also be interpreted as, returns the index at which str contains the first
ocurrence of a character in reject */
size_t	ft_strcspn(const char *str, const char *reject)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	if (!reject)
		return (ft_strlen(str));
	while (str[i])
	{
		if (ft_strchr((char *)reject, str[i]))
			return (i);
		i++;
	}
	return (i);
}
