/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cub3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:40:32 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/30 18:51:45 by apresas-         ###   ########.fr       */
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
# define ERR_NO_MAP_IN_FILE "The file provided does not contain a map"

// MiniLibX errors
# define ERR_XPM_TO_IMG "MiniLibX failed to convert an xpm to image"
# define ERR_IMG_GET_ADDR "MiniLibX failed to get the addr for an image"
# define ERR_MLX_INIT "MiniLibX failed to initialize mlx"
# define ERR_MLX_WINDOW "MiniLibX failed to create a window"

// Map errors
# define ERR_MAP_NOT_ENCLOSED "Incorrect map format, the map provided is not \
completely surrounded by walls"
# define ERR_MAP_MULTIPLE_SPAWN "Incorrect map format, multiple spawn points \
were found in the map"
# define ERR_MAP_INVALID_CHAR "Incorrect map format, invalid characters were \
found in the map\n(Tabulations are also not allowed)"
# define ERR_MAP_EMPTY_LINE "Incorrect map format, empty lines were found in \
the map"
# define ERR_MAP_NO_SPAWN "Incorrect map format, no spawn point was found in \
the map"
# define ERR_MAP_SPAWN_INVALID "Incorrect map format, the player spawn is \
in an invalid tile"
# define ERR_MAP_SPRITE_INVALID "Incorrect map format, a sprite was found \
in an invalid tile"
# define ERR_MAP_DOOR_INVALID "Incorrect map format, a door was found in an \
invalid tile"

// Fatal errors
# define ERR_MALLOC "Memory allocation failed"

// Generic error for exit without printing an error message but EXIT_FAILURE
# define ERR_GENERIC ""

//Useful macros
# define TRUE 1
# define FALSE 0
# define X 0
# define Y 1
# define WALL '1'
# define EMPTY '0'
# define SPACE 32
# define DOOR 'D'
# define SPRITE 'O'

//COLORS IN INT
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define FLOOR WHITE
# define CEILING RED

//Macros for calculation values

# define WINX 640
# define WINY 360
# define ROTATE_SPEED 0.1
# define MOVE_SPEED 0.1
# define TILE_SIZE 2
# define FPS 60

typedef struct s_object
{
	double	pos[2];
	double	dist;
}				t_object;

// typedef struct s_sprite_drawing_data
// {
// 	double	transform[2];
// 	double	iter[2];
// 	double	step[2];
// 	double	iter_start_y;
// 	int		on_screen_size[2];
// 	int		size[2];
// 	int		draw_start[2];
// 	int		draw_end[2];
// }				t_sprite_data;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line;
	int		endian;
	int		size[2];
}					t_img;

typedef struct s_door_data
{
	double	step[2];
	double	side_dist[2];
	double	delta_dist[2];
	int		map[2];
	double	pos[2];
}				t_door_data;

typedef struct s_player
{
	double	pos[2];
	double	dir[2];
	double	plane[2];
	double	move_speed;
	double	rot_speed;
}				t_player;

typedef struct s_map_elements
{
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	t_img	sprite;
	t_img	door;
	int		floor;
	int		ceiling;
}				t_elements;

typedef struct s_map
{
	char		**grid;
	t_elements	elements;
	int			size[2];
	int			spawn[2];
	int			player_dir[2];
	double		offset_y;
	int			objects;
}				t_map;

typedef struct s_ray
{
	double	camera;
	double	ray_dir[2];
	int		map[2];
	double	side_dist[2];
	double	delta_dist[2];
	double	perp_wall_dist;
	int		step[2];
	int		side[2];
}				t_ray;

typedef struct s_mouse
{
	int		prev_pos[2];
	int		pressed;
}				t_mouse;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*window;
	t_img	*win_img;
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

//
typedef struct s_sprite
{
	t_img	*img;
	int		transparency_color;
	int		frames;
	int		i;
	int		framerate;
}				t_sprite;

typedef struct s_data
{
	char		**file;
	t_object	*objects;
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_mouse		mouse;
	t_sprite	sprite;
	int			bonus;
	double		zbuffer[WINX];
	int			frame;// unnecessary
}				t_data;

// functions:

// game_loop.c
int	game_loop(t_data *data);

// verify_arguments.c
int		verify_arguments(int argc, char **argv);

// init.c
void	init_data(t_data *data);

// bonus_sprites2.c
void	init_sprite_images(t_data *data);// recolocar

// init2.c
void	init_ray_variables(t_ray *ray);
void	init_mouse_variables(t_mouse *mouse);

// parser.c
int		parser(t_data *data, char *filepath);

// store_file.c
char	**store_file(char *filepath, t_data *data);

// get_file_elements.c
int		get_file_elements(t_data *data, t_elements *elements, char **file);
int		rgb_to_int(int red, int green, int blue);

// bonus_get_file_elements.c
int		get_bonus_elements(t_data *data, char **file);

// bonus_get_file_elements2.c
int		get_transparency_color(char **line, t_data *data);
int		get_sprite_texture_count(char **line, t_data *data);
char	*get_path_prefix(char *line, t_data *data);
char	*get_full_path(char *prefix, int i, t_data *data);

// parse_map.c
void	parse_map(t_data *data, char **file);
void	get_player_spawn_and_dir(t_map *map, char player, int x, int y);
int		tile_is_exterior(char **grid, int y, int x, int size[2]);

// file_to_grid.c
char	**create_map_from_file(t_map *map, char **file);

// bonus_parse_map.c
void	bonus_parse_map(t_data *data, char **file);

// render.c
void	render(t_data *data);

// raycaster.c
void	init_raycasting(t_data *data);

// texture_render.c
t_img	*get_texture(t_data *data);
int		*get_texture_addr(t_data *data, t_img *texture);
void	draw_vert_stripe(int *texture, int *win, int tx_size[2], t_data *data);

// bonus_sprites.c
void	bonus_draw_sprites(t_data *data, t_object *obj);

// bonus_minimap.c
void	draw_minimap(t_data *data, int *window);

// error.c
int		c3d_error(const char *error);
int		c3d_exit(const char *error, t_data *data);
int		c3d_close_window_exit(t_data *data);

// hooks.c
void	hook(t_data *data);
int		keypressed(int keycode, t_data *data);
int		mousemove(int x, int y, t_data *data);
int		mousepressed(int button, int x, int y, t_data *data);
int		mousereleased(int button, int x, int y, t_data *data);

// movement.c
void	rotate_player(t_data *data, double angle);
void	move_forward(t_data *d);
void	move_back(t_data *d);
void	move_left(t_data *d);
void	move_right(t_data *d);

// bonus_door.c
void	interact_door(t_data *data);

// pixels.c
t_img	*get_img(t_data *data, int width, int height);
void	put_pixel(t_img *img, int x, int y, int color);
t_uint	get_pixel_color(t_img *image, int x, int y);

// // debug.c
// void	print_map_grid(t_data *data);
// void	print_map_elements(t_data *data);
// void	debug_check(void);
// void	print_data(t_data *data);
// void	imprimirArray2D(t_data *data);

// //utils.c
// double	deg_to_rad(double deg);

#endif // CUB3D_H
