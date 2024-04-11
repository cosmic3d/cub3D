/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:40:32 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/11 13:06:13 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "eventcodes.h"
# include "keycodes.h"

// Debugging libs
# include <time.h> //

# ifdef __linux__
#  include "../libs/minilibx_linux/mlx.h"
# endif
# ifdef __APPLE__
#  include "../libs/minilibx_macos/mlx.h"
# endif

// Textures
/*
int	rgb_floor(int range)
{
	return ((FLOOR >> range) & 0xFF);
}
// Where range is RED, GREEN or BLUE
*/

// Redefining macros that for some reason in my case are wanky
# ifdef __linux__
#  define O_RDONLY 00
# endif
/* Macros for errors */
// Argc errors
# define ERR_TOO_FEW_ARGS "Too few arguments, one argument is needed"
# define ERR_TOO_MANY_ARGS "Too many arguments, only one argument is needed"
// File errors
# define ERR_INVALID_FILEPATH "The argument provided has an invalid path"
# define ERR_INVALID_FILE_EXTENSION "The file provided is not a .cub file"
# define ERR_CANNOT_OPEN_FILE "Failure to open the file provided"
# define ERR_CANNOT_CLOSE_FILE "Failure to close the file provided"
# define ERR_INVALID_FILE_FORMAT "The file provided doesn't follow the \
guidelines"
# define ERR_FILE_REPEATED_ELEMENT "Incorrect file format, repeated element \
found"
# define ERR_FILE_FORMAT_ELEMENT "Incorrect file format, an element was \
incorrectly formatted"
# define ERR_NOT_ENOUGH_ELEMENTS "Incorrect file format, not enough elements \
were provided"

// Map errors
# define ERR_MAP_NOT_ENCLOSED "Incorrect map format, the map provided is not \
completely surrounded by walls"

// Fatal errors
# define ERR_MALLOC "Memory allocation failed"

//Useful macros
#define TRUE 1
#define FALSE 0
#define X 0
#define Y 1
#define WALL '1'
#define EMPTY '0'
#define SPACE 32

//COLORS IN INT
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define YELLOW 0xFFFF00
#define CYAN 0x00FFFF
#define MAGENTA 0xFF00FF
#define FLOOR WHITE
#define CEILING CYAN

//Macros for calculation values
#define WINX 1920
#define WINY 1080
#define ROTATE_SPEED 0.1
#define MOVE_SPEED 0.1

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line;
	int		endian;
	int		size[2];
}					t_img;

typedef struct s_player
{
	double pos[2]; //Puede que venga mejor float
	double dir[2];
	double plane[2];
}				t_player;

typedef struct s_map_elements
{
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	int		floor;
	int		ceiling;
}				t_elements;

typedef struct	s_map
{
	char		**grid;
	t_elements	elements;
	int			size[2];
	int			spawn[2];
	int			player_dir[2]; // [0] = x, [1] = y
}				t_map;

typedef struct s_ray
{
	double	camera[2];
	double	ray_dir[2];
	int		map[2];
	double	side_dist[2];
	double	delta_dist[2];
	double	perp_wall_dist;
	int		step[2];
	int		hit;
	int		side[2];
}				t_ray;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*window;
	t_img	*win_img;
	//t_img	*fc_img; //Floor and ceiling
	int		texture_size;
}				t_mlx;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
	int		size[2];
}				t_texture;

typedef struct s_data
{
	char		**file;
	int			fd;
	t_mlx		mlx;
	// t_elements	elements;
	t_texture	textures;
	t_map		map;
	t_player	player;
	t_ray		ray;
}				t_data;

// functions:

void	init_data_struct(t_data *data);
int		parser(t_data *data, char *filepath);
int		parse_argument(t_data *data, char *filepath);
void	parse_file(t_data *data);
// int		get_file_elements(t_data *data);
int		get_file_elements(t_mlx *mlx, t_elements *elements, char **file);
char	**store_file(char *filepath);
int		verify_arguments(int argc, char **argv);
int		c3d_error(char *error);
int		c3d_exit(char *error);

// main.c
void	initialize_variables(t_data *data);
void	init_mlx(t_data *data);

// raycaster.c
void	init_raycasting(t_data *data);
void	calculate_step(t_data *data);
void 	check_hit(t_data *data);
void 	calculate_perp_dist(t_data *data);
void 	draw_vert_stripe(t_data *data, int x);

// hooks.c
void	hook(t_data *data);
int		keypressed(int keycode, t_data *data);
int		mousedown(int keycode, int x, int y, t_data *data);

// pixels.c
t_img	*get_img(t_data *data, int width, int height);
void	put_pixel(t_img *img, int x, int y, int color);
// int		get_pixel_color(t_img *image, int x, int y);
unsigned int get_pixel_color(t_img *image, int x, int y);

// render.c
void	render(t_data *data);
void	set_floor_ceiling(t_data *data);
void	parse_map(t_data *data, char **file);
int		is_tile_external(char **file, int i, int j);
char	**create_map_from_file(char **file, int size[2]);

// debug.c
void	print_map_grid(t_data *data);
void	print_map_elements(t_data *data);
void	debug_check(void);
void	print_data(t_data *data);
void	imprimirArray2D(t_data *data);

// movement.c
void	rotate_player(t_data *data, double angle);
void	move_forward(t_data *d);
void	move_back(t_data *d);
void	move_left(t_data *d);
void	move_right(t_data *d);

// texture_render.c
void	draw_vert_stripe(t_data *data, int x);

#endif // CUB3D_H
