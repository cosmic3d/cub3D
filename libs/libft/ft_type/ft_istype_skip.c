/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istype_skip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:24:54 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/23 19:45:18 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_istype_skip_p(char **line, int (*f)(int))
{
	if (!line || !*line)
		return (1);
	while (**line && f(**line))
		(*line)++;
	return (0);
}

int	ft_istype_skip(char *line, int (*f)(int))
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i] && f(line[i]))
		i++;
	return (i);
}
