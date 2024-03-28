/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:21:53 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/28 16:22:15 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Divides str into tokens separated by characters in delim, attempts to be
similar to strtok_r */
char	*ft_strtok_r(char *str, const char *delim, char **saveptr)
{
	char	*token;
	int		tok_start;
	int		tok_end;
	int		next_tok;

	if (str)
		*saveptr = str;
	if (!*saveptr)
		return (NULL);
	tok_start = ft_strspn(*saveptr, delim);
	tok_end = ft_strcspn(*saveptr + tok_start, delim) + tok_start;
	next_tok = ft_strspn(*saveptr + tok_end, delim) + tok_end;
	token = *saveptr;
	token[tok_end] = '\0';
	token += tok_start;
	if ((*saveptr)[next_tok] == '\0')
		*saveptr = NULL;
	else
		*saveptr += next_tok;
	return (token);
}
