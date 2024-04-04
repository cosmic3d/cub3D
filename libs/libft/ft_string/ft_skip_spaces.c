/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:39:56 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/03 14:05:00 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// WIP

// Skips any space character, which includes ' ', '\t', '\n', '\v' and '\r'
// WIP
void	ft_skip_spaces(char *str, int *i)
{
	while (ft_isspace(str[*i]))
		*i++;
}

// Skips the spaces in a string str[*i], modifying the value of *i
// As of now, "spaces" literally means the space character, no tabs, newlines,
// etc.
// WIP
char	*ft_skip_spaces_ptr(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

// Skips any consecutive newlines
// WIP
void	ft_skip_newlines(char *str, int *i)
{
	while (str[*i] == '\n')
		*i++;
}
