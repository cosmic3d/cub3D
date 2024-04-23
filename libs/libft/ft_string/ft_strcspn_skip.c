/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn_skip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:34:53 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/23 19:56:37 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn_skip(char **s, const char *reject)
{
	size_t	i;

	i = 0;
	if (!s || !*s)
		return (i);
	if (!reject)
	{
		i = ft_strlen(*s);
		*s += i;
		return (i);
	}
	while ((*s)[i] && !ft_strchr((char *)reject, (*s)[i]))
		i++;
	*s += i;
	return (i);
}
