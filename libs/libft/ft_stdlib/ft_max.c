/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:34:32 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/21 13:35:02 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

long	maxl(long a, long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t	max_size_t(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_uint	max_u(t_uint a, t_uint b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_ulong	max_ul(t_ulong a, t_ulong b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
