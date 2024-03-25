/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:30:39 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/21 13:38:13 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

long	minl(long a, long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t	min_size_t(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

t_uint	min_u(t_uint a, t_uint b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

t_ulong	min_ul(t_ulong a, t_ulong b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
