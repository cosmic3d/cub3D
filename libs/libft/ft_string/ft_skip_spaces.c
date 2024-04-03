/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:39:56 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/27 14:42:56 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// WIP

// Skips any space character, which includes ' ', '\t', '\n', '\v' and '\r'
void	ft_skip_spaces(char *str, int *i)
{
	while (ft_isspace(str[*i]))
		*i++;
}

// Skips any consecutive newlines
void	ft_skip_newlines(char *str, int *i)
{
	while (str[*i] == '\n')
		*i++;
}
