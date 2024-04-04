/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:56:32 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/03 14:09:25 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns a pointer to the first ocurrence of the a character that is NOT
chr in string str. */
char	*ft_strnchr(char *str, int chr)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("Error\nThis should be a SEGMENTATION FAULT\n", 2);
		ft_putstr_fd("A NULL pointer has been sent to ft_strchr\n", 2);
		return (NULL);
	}
	while (chr > 127)
		chr -= 128;
	if (chr == '\0')
		return (str);
	while (str[i] == (char)chr)
		i++;
	return (str + i);
}
