/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:49:51 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/27 14:53:39 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchr_i(const char *str, int chr)
{
	int	len;

	len = ft_strlen(str);
	if ((char)chr == 0)
		return (len);
	while (len >= 0)
	{
		if (str[len] == (char)chr)
			return (len);
		len--;
	}
	return (-1);
}
