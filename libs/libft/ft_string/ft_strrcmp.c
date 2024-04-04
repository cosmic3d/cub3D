/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:25:27 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/26 14:33:48 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Reverse strcmp, compares both strings from its end backwards
int	ft_strrcmp(const char *s1, const char *s2)
{
	size_t			i;
	size_t			j;
	unsigned char	*a1;
	unsigned char	*a2;

	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while (i > 0 && j > 0)
	{
		if (a1[i] > a2[j] || a1[i] < a2[j])
			return (a1[i] - a2[j]);
		else if (a1[i] == a2[j])
		{
			i--;
			j--;
		}
	}
	if (a1[i] > a2[j] || a1[i] < a2[j])
		return (a1[i] - a2[i]);
	else
		return (0);
}
