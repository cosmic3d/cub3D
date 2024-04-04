/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:08:30 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/03 17:29:16 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// STILL IN TESTING
// Uses get_next_line to return a char **pointer that stores a complete
// copy of the opened file indicated by the given file descriptor
// You must also give it the amount of lines of the file
char	**ft_store_file(int fd, int lines)
{
	char	**file;
	int		i;

	file = malloc(sizeof(char *) * (lines + 1));
	if (!file)
		return (NULL);
	file[lines] = NULL;
	i = 0;
	file[i] = get_next_line(fd);
	if (!file[i++])
		return (free(file), NULL);
	while (i < lines)
	{
		file[i] = get_next_line(fd);
		if (!file[i])
		{
			ft_free_array_r((void *)file, i - 1);
			return (free(file), NULL);
		}
		i++;
	}
	get_next_line(fd);
	return (file);
}

// STILL IN TESTING
// Returns the amount of lines an opened file corresponding to the given
// file descriptor contains
int	ft_file_lines(int fd)
{
	int		lines;
	char	*buffer;

	lines = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		lines++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	return (lines);
}
