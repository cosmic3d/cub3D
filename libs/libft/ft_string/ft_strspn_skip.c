/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn_skip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:30:56 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/23 19:52:43 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn_skip(char **s, const char *accept)
{
	size_t	i;

	i = 0;
	if (!s || !*s || !accept)
		return (i);
	while ((*s)[i] && ft_strchr((char *)accept, (*s)[i]))
		i++;
	*s += i;
	return (i);
}
