/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:11:09 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/26 17:26:45 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ORIGINAL GNL:

static char	*read_to_buffer(int fd, char *buffer);
static char	*buffer_to_string(char *buffer);
static char	*buffer_cleanup(char *old_buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*string;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = read_to_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	string = buffer_to_string(buffer);
	buffer = buffer_cleanup(buffer);
	return (string);
}

static char	*read_to_buffer(int fd, char *buffer)
{
	char	*auxiliar;
	int		aux_len;

	aux_len = 1;
	auxiliar = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!auxiliar)
		return (NULL);
	while (!gnl_strchr(buffer, '\n') && aux_len != 0)
	{
		aux_len = read(fd, auxiliar, BUFFER_SIZE);
		if (aux_len == -1)
		{
			free(auxiliar);
			return (NULL);
		}
		auxiliar[aux_len] = '\0';
		buffer = gnl_strjoin(buffer, auxiliar);
	}
	free(auxiliar);
	return (buffer);
}

static char	*buffer_to_string(char *buffer)
{
	int		i;
	char	*to_string;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	i++;
	to_string = malloc(sizeof(char) * (i + 1));
	if (!to_string)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		to_string[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		to_string[i++] = '\n';
	to_string[i] = '\0';
	return (to_string);
}

static char	*buffer_cleanup(char *old_buffer)
{
	int		i;
	int		j;
	int		buffer_len;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (old_buffer[i] != '\n' && old_buffer[i] != '\0')
		i++;
	if (old_buffer[i] == '\0')
	{
		free(old_buffer);
		return (NULL);
	}
	buffer_len = gnl_strlen(old_buffer) - i;
	new_buffer = malloc(sizeof(char) * (buffer_len + 1));
	if (!new_buffer)
		return (NULL);
	i++;
	while (old_buffer[i] != '\0')
		new_buffer[j++] = old_buffer[i++];
	new_buffer[j] = '\0';
	free(old_buffer);
	return (new_buffer);
}

/* NEWER VERSION THAT IS HALFWAY THROUGH:

static void	*gnl_error(char *err);
static char	*read_to_buffer(int fd, char *buffer);
static char	*buffer_to_string(char *buffer);
static char	*buffer_cleanup(char *old_buffer);

// This implementation is not super clean
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*string;

	if (BUFFER_SIZE <= 0)
		return (gnl_error(GNL_ERR_BUFFER_SIZE));
	if (fd < 0)
		return (gnl_error(GNL_ERR_FD));
	buffer = read_to_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	string = buffer_to_string(buffer);
	buffer = buffer_cleanup(buffer);
	return (string);
}

static char	*read_to_buffer(int fd, char *buffer)
{
	char	*auxiliar;
	int		aux_len;

	aux_len = 1;
	auxiliar = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!auxiliar)
		return (gnl_error(GNL_ERR_MALLOC));
	while (!gnl_strchr(buffer, '\n') && aux_len != 0)
	{
		aux_len = read(fd, auxiliar, BUFFER_SIZE);
		if (aux_len == -1)
		{
			free(auxiliar);
			return (gnl_error(GNL_ERR_READ));
		}
		auxiliar[aux_len] = '\0';
		buffer = ft_strjoin(buffer, auxiliar);
	}
	free(auxiliar);
	return (buffer);
}

static char	*buffer_to_string(char *buffer)
{
	int		i;
	char	*to_string;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	i++;
	to_string = malloc(sizeof(char) * (i + 1));
	if (!to_string)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		to_string[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		to_string[i++] = '\n';
	to_string[i] = '\0';
	return (to_string);
}

static char	*buffer_cleanup(char *old_buffer)
{
	int		i;
	int		j;
	int		buffer_len;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (old_buffer[i] != '\n' && old_buffer[i] != '\0')
		i++;
	if (old_buffer[i] == '\0')
	{
		free(old_buffer);
		return (NULL);
	}
	buffer_len = ft_strlen(old_buffer) - i;
	new_buffer = malloc(sizeof(char) * (buffer_len + 1));
	if (!new_buffer)
		return (gnl_error(GNL_ERR_MALLOC));
	i++;
	while (old_buffer[i] != '\0')
		new_buffer[j++] = old_buffer[i++];
	new_buffer[j] = '\0';
	free(old_buffer);
	return (new_buffer);
}

static void	*gnl_error(char *err)
{
	ft_printf_fd(2, GNL_ERR_PREFIX);
	ft_printf_fd(2, err);
	ft_printf_fd(2, "\n");
	return (NULL);
}

*/