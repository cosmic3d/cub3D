/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:21:41 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/03 17:33:52 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Uses malloc and free to safely allocate a void **array of h*w dimensions */
void	*ft_alloc_array(size_t size, size_t h, size_t w)
{
	void	**array;
	size_t	i;

	array = malloc(sizeof(void *) * h);
	if (!array)
		return (NULL);
	i = 0;
	while (i < w)
	{
		array[i] = malloc(size * w);
		if (!array[i])
		{
			ft_free_array_r(array, i - 1);
			return (NULL);
		}
		i++;
	}
	return (array);
}
