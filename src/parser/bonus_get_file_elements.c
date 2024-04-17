/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_file_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:03:08 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/17 13:12:39 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_bonus_texture(char *line, t_mlx *mlx, t_img *texture);

int	get_bonus_elements(t_data *data, char **file)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (file[i] && count < 2)
	{
		if (ft_strncmp(file[i], "SP", 2) == 0)
			count += get_bonus_texture(file[i], &data->mlx, \
			&data->map.elements.sprite);
		else if (ft_strncmp(file[i], "DR", 2) == 0)
			count += get_bonus_texture(file[i], &data->mlx, \
			&data->map.elements.door);
		else if (file[i][0] != '\0' && count < 2)
			c3d_exit(ERR_INVALID_FILE_FORMAT);
		i++;
	}
	return (i);
}

static int	get_bonus_texture(char *line, t_mlx *mlx, t_img *texture)
{
	if (texture->img)
		c3d_exit(ERR_FILE_REPEATED_ELEMENT);
	line = ft_strnchr(line + 2, ' ');
	if (ft_strrcmp(line, ".xpm") != 0)
		c3d_exit(ERR_FILE_FORMAT_ELEMENT);
	texture->img = mlx_xpm_file_to_image(mlx->mlx, line, \
			&texture->size[X], &texture->size[Y]);
	if (!texture->img)
		c3d_exit(ERR_XPM_TO_IMG);
	texture->addr = (int *)mlx_get_data_addr(texture->img, &texture->bpp, \
			&texture->line, &texture->endian);
	texture->line >>= 2;
	if (!texture->addr)
		c3d_exit(ERR_IMG_GET_ADDR);
	return (1);
}
