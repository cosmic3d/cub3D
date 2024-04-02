/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:05:07 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/02 12:59:00 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// All of these functions are a WIP and I still haven't figured out exactly
// which versions I want

/* Receives a pointer to a char in a string, keeps track of the character at
that point in the string, then travels the string until that character is
found again. Returns the pointer to that string.
If the character is not found again, returns a NULL pointer. */
// WIP
// Older version
// char	*ft_skip_chr_ptr(char *str)
// {
// 	char	ch;

// 	ch = *str;
// 	str++;
// 	while (*str)
// 	{
// 		if (*str == ch)
// 			return (str);
// 		str++;
// 	}
// 	return (NULL);
// }

// DO NOT USE WITHOUT VERIFYING THAT THE FUNCTION WORKS
// THIS IS A WIP
char	*ft_skip_char_ptr(char **str, int ch)
{
	while (**str)
	{
		if (**str == ch)
			return (*str);
		*str += 1;
	}
	return (*str); // ?
}

/* Receives a string and an index, keeps track of the character at str[i]
then travels the string until that character is found again. Returns the 
new value of the index that was used to travel the string.
If the character is not found again, returns the index at which the
string ends. */
// WIP
int	ft_skip_chr_i(char *str, int i)
{
	char	ch;

	ch = str[i];
	i++;
	while (str[i])
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	return (i);
}

/* Skips as many consecutive repetitions of the char c in the string str
starting at str[*i], returns the amount of characters that were skipped */
// WIP
int	ft_skip_char(char *str, int *i, char c)
{
	int	j = 0;

	while (str[*i + j] == c)
		j++;
	*i += j;
	return (j);
}

// Skips the spaces in a string str[*i], modifying the value of *i
// As of now, "spaces" literally means the space character, no tabs, newlines,
// etc.
void	ft_skip_spaces(char *str, int *i)
{
	int	j = *i;

	while (str[j] == ' ')
		j++;
	*i = j;
}
