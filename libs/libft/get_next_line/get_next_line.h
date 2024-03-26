/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:57:40 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/26 17:48:01 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# define GNL_ERR_PREFIX "error: get_next_line: "
# define GNL_ERR_BUFFER_SIZE "BUFFER_SIZE must have a value > 0"
# define GNL_ERR_FD "The provided file descriptor must have a value >= 0"
# define GNL_ERR_MALLOC "Memory allocation failed"
# define GNL_ERR_READ "The read function failed unexpectedly"

char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *left_str, char *buff);
size_t	gnl_strlen(char *str);

#endif // GET_NEXT_LINE_H
