/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:40:32 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/19 17:20:26 by apresas-         ###   ########.fr       */
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

// For debugging
# include <time.h>
# define FPS_TEST_CYCLES 5000

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
found in the map"
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
#define TRUE 1
#define FALSE 0
#define X 0
#define Y 1
#define WALL '1'
#define EMPTY '0'
#define SPACE 32
#define DOOR 'D'
#define SPRITE 'O'

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
#define CEILING RED

//Macros for calculation values

#define WINX 1920 //640
#define WINY 1080 //360
#define ROTATE_SPEED 0.05
#define MOVE_SPEED 0.1
#define TILE_SIZE 2

typedef struct s_sprite
{
	double	pos[2];
	double	dist;
}				t_sprite;

typedef struct s_sprite_drawing_data
{
	double	transform[2];
	double	iter[2];
	double	step[2];
	double	iter_start_y;
	int		on_screen_size[2];
	int		size[2];
	int		draw_start[2];
	int		draw_end[2];
}				t_sprite_data;

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
}				t_door_data;

typedef struct s_player
{
	double pos[2]; //Puede que venga mejor float
	double dir[2];
	double plane[2];
	double move_speed;
	double rot_speed;
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

typedef struct	s_map
{
	char		**grid;
	t_elements	elements;
	int			size[2];
	int			spawn[2];
	int			player_dir[2]; // [0] = x, [1] = y
	double		offset_y;
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

typedef struct s_mouse
{
	int	prev_pos[2];
	int	pressed;
	double	max_rot;
}				t_mouse;

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
	t_sprite	*sprites;
	t_mlx		mlx;
	// t_elements	elements;
	t_texture	textures;
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_mouse		mouse;
	int			texture_size;//
	int			bonus;
	int			sprite_count;
	double		zbuffer[WINX];
	int			frame_done;
}				t_data;

// functions:

void	init_data_struct(t_data *data);
int		parser(t_data *data, char *filepath);
int		parse_argument(t_data *data, char *filepath);
void	parse_file(t_data *data);
// int		get_file_elements(t_data *data);
// int		get_file_elements(t_mlx *mlx, t_elements *elements, char **file);
int		get_file_elements(t_data *data, t_elements *elements, char **file);
char	**store_file(char *filepath, t_data *data);
int		verify_arguments(int argc, char **argv);
int		c3d_error(const char *error);
// int		c3d_exit(char *error);
int		c3d_exit(const char *error, t_data *data);

// memory.c


// parse_map.c
void	get_player_spawn_and_dir(t_map *map, char player, int x, int y);
int		tile_is_exterior(char **grid, int y, int x, int size[2]);

// bonus_get_file_elements.c
int		get_bonus_elements(t_data *data, char **file);

// bonus_door.c
void	open_door(t_data *data);

// main.c
void	initialize_variables(t_data *data);
void	init_mlx(t_data *data);

// raycaster.c
void	init_raycasting(t_data *data);
// void	calculate_step(t_data *data);
// void 	check_hit(t_data *data);
// void calculate_perp_dist(t_data *data, int x);
// void 	calculate_perp_dist(t_data *data);

// hooks.c
void	hook(t_data *data);
int		keypressed(int keycode, t_data *data);
int		mousemove(int x, int y, t_data *data);

// pixels.c
t_img	*get_img(t_data *data, int width, int height);
void	put_pixel(t_img *img, int x, int y, int color);
t_uint	get_pixel_color(t_img *image, int x, int y);

// render.c
void	render(t_data *data);
void	drawMinimap(t_data *data);

// parse_map.c
void	parse_map(t_data *data, char **file);

// bonus_parse_map.c
void	bonus_parse_map(t_data *data, char **file);

// file_to_grid.c
char	**create_map_from_file(t_map *map, char **file);

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

//utils.c
double	deg_to_rad(double deg);

//draw.c
void	drawRect(t_data *data, int x, int y, int size, int color);

// texture_render.c
int		*get_window(t_data *data, int x);
t_img	*get_texture(t_data *data);
int		*get_texture_addr(t_data *data, t_img *texture);
void	draw_vert_stripe(int *texture, int *win, int tx_size[2], t_data *data);

// bonus_sprites.c
void	bonus_draw_sprites(t_data *data, t_sprite *sprite);

#endif // CUB3D_H
