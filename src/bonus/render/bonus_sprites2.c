/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_sprites2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:54:14 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/23 18:29:18 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* static int	get_sprite_img(char *path, t_data *data, int i)
{
	data->sprite[i].img = mlx_xpm_file_to_image(data->mlx.mlx, path, \
		&data->sprite[i].size[X], &data->sprite[i].size[Y]);
	if (!data->sprite[i].img)
		return (c3d_error(ERR_XPM_TO_IMG));
	data->sprite[i].addr = mlx_get_data_addr(data->sprite[i].img, \
		&data->sprite[i].bpp, &data->sprite[i].line, &data->sprite[i].endian);
	if (!data->sprite[i].addr)
	{
		mlx_destroy_image(data->mlx.mlx, data->sprite[i].img);
		return (c3d_error(ERR_IMG_GET_ADDR));
	}
	data->sprite[i].line >>= 2;
	return (0);
} */

/*
int	get_sprite(int i, t_data *data)
{
	char	*path;
	char	*path_aux;

	if (i > 99)
		return (c3d_exit("You are crazy", data));
	if (i <= 9)
		path_aux = ft_strjoin("textures/sprite/sprite_0", ft_itoa(i));
	else
		path_aux = ft_strjoin("textures/sprite/sprite_", ft_itoa(i));
	if (!path_aux)
		c3d_exit(ERR_MALLOC, data);
	path = ft_strjoin(path_aux, ".xpm");
	if (!path)
	{
		free(path_aux);
		c3d_exit(ERR_MALLOC, data);
	}
	data->sprite[i].img = mlx_xpm_file_to_image(data->mlx.mlx, path, \
		&data->sprite[i].size[X], &data->sprite[i].size[Y]);
	if (!data->sprite[i].img)
	{
		free(path);
		free(path_aux);
		printf("i = %d\n", i);
		return (c3d_exit(ERR_XPM_TO_IMG, data));
	}
	data->sprite[i].addr = (int *)mlx_get_data_addr(data->sprite[i].img, \
		&data->sprite[i].bpp, &data->sprite[i].line, &data->sprite[i].endian);
	if (!data->sprite[i].addr)
	{
		mlx_destroy_image(data->mlx.mlx, data->sprite[i].img);
		free(path);
		free(path_aux);
		return (c3d_exit(ERR_IMG_GET_ADDR, data));
	}
	data->sprite[i].line >>= 2;
	free(path);
	free(path_aux);
	return (0);
}

void	init_sprite_images(t_data *data)
{
	int	i;

	data->sprite = malloc(sizeof(t_img) * 12);
	if (!data->sprite)
		c3d_exit(ERR_MALLOC, data);
	i = 0;
	while (i < 12)
	{
		if (get_sprite(i++, data))
			c3d_exit(ERR_XPM_TO_IMG, data);
	}
	return ;
}
*/