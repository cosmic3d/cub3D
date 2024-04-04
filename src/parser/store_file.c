/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:04:38 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/03 17:18:57 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_newlines(char **file);

/* Returns a char** with the contents of the file indicated by filepath and
removes the final newlines from it */
char	**store_file(char *filepath)
{
	char	**file;
	int		fd;
	int		file_lines;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		c3d_exit(ERR_CANNOT_OPEN_FILE);
	file_lines = ft_file_lines(fd);
	if (close(fd) == -1)
		c3d_exit(ERR_CANNOT_CLOSE_FILE);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		c3d_exit(ERR_CANNOT_OPEN_FILE);
	file = ft_store_file(fd, file_lines);
	if (close(fd) == -1)
		c3d_exit(ERR_CANNOT_CLOSE_FILE);
	clear_newlines(file);
	return (file);
}

/* Removes all the newlines at the end of each line of char **file */
static void	clear_newlines(char **file)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		j = ft_strlen(file[i]);
		if (file[i][j - 1] == '\n')
			file[i][j - 1] = '\0';
		i++;
	}
	return ;
}
