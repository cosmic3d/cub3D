/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:23:36 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/28 16:23:59 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Locates the first occurence in the string s of any of the bytes in the
string accept. Returns a pointer to the byte in s that matches one of the
bytes in accept, or NULL if no such byte is found.
Returns NULL if s and/or accept have a value of NULL. */
char	*ft_strpbrk(const char *s, const char *accept)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	if (!accept || !s)
		return (NULL);
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
			{
				result = (char *)(s + i);
				return (result);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
