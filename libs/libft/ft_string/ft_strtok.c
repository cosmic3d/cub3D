/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:20:45 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/28 16:21:46 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Divides str into tokens separated by characters in delim, attempts to be
similar to strtok */
char	*ft_strtok(char *str, const char *delim)
{
	static char	*saveptr;

	return (ft_strtok_r(str, delim, &saveptr));
}
