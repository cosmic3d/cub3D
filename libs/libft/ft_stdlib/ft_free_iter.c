/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:50:11 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/26 17:58:51 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Still testing this, I'm not including it on the libft.a yet
void	ft_free_iter(void **array, int start, int end)
{
	int	i;

	if (start < end)
		i = start;
	else
	{
		i = end;
		end = start;
	}
	while (i <= end)
		free(array[i++]);
	return ;
}
