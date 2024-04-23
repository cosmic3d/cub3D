/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:33:40 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/23 17:42:11 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_3(const char *s1, const char *s2, const char *s3)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_s3;
	size_t	len;
	char	*str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_s3 = ft_strlen(s3);
	len = len_s1 + len_s2 + len_s3;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, len_s1 + len_s2 + 1);
	ft_strlcat(str, s3, len + 1);
	return (str);
}

char	*ft_strjoin_4(const char *s1, \
	const char *s2, \
	const char *s3, \
	const char *s4)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_s3;
	size_t	len_s4;
	char	*str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_s3 = ft_strlen(s3);
	len_s4 = ft_strlen(s4);
	str = ft_calloc(len_s1 + len_s2 + len_s3 + len_s4 + 1, sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, len_s1 + len_s2 + 1);
	ft_strlcat(str, s3, len_s1 + len_s2 + len_s3 + 1);
	ft_strlcat(str, s4, len_s1 + len_s2 + len_s3 + len_s4 + 1);
	return (str);
}
