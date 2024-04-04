/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:00:10 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/03 14:10:02 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns the index at which the first ocurrence of the a character that is NOT
chr in string str. */
int	ft_strnchr_i(char *str, int chr)
{
	int	i;

	i = 0;
	while (chr > 127)
		chr -= 128;
	while (str[i] && str[i] == (char)chr)
		i++;
	return (i);
}
