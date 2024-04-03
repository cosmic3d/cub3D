#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include "../libs/libft/libft.h"
#include "eventcodes.h"
#include "keycodes.h"
#ifdef __linux__
	#include "../libs/minilibx_linux/mlx.h"
#elif defined __APPLE__ // Change this for norminette
	#include "../libs/minilibx_macos/mlx.h"
#endif

// Textures
/*
int	rgb_floor(int range)
{
	return ((FLOOR >> range) & 0xFF);
}
// Where range is RED, GREEN or BLUE
*/

// Redefining macros that for some reason in my case are wanky
/* #define O_RDONLY 00  CAUSES COMPILATION ERROR DUE TO MACRO REDEFINED*/

/* Macros for errors */
// Argc errors
#define ERR_TOO_FEW_ARGS "Too few arguments provided, one argument is needed"
#define ERR_TOO_MANY_ARGS "Too many arguments provided, only argument is needed"
// File errors
#define ERR_INVALID_FILEPATH "The argument provided has an invalid path"
#define ERR_INVALID_FILE_EXTENSION "The file provided is not a .cub file"
#define ERR_CANNOT_OPEN_FILE "Failure to open the file provided"
#define ERR_CANNOT_CLOSE_FILE "Failure to close the file provided"
#define ERR_INVALID_FILE_FORMAT "The file provided doesn't follow the \
guidelines"
#define ERR_FILE_REPEATED_ELEMENT "Incorrect file format, repeated element \
found"
#define ERR_FILE_FORMAT_ELEMENT "Incorrect file format, an element was \
incorrectly formatted"
#define ERR_NOT_ENOUGH_ELEMENTS "Incorrect file format, not enough elements \
were provided"
// Fatal errors
#define ERR_MALLOC "Memory allocation failed"

//Useful macros
#define TRUE 1
#define FALSE 0
#define X 0
#define Y 1
#define WALL 1
#define EMPTY 0
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
#define WINX 640
#define WINY 360
#define ROTATE_SPEED 0.1

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line;
	int				endian;
}					t_img;

typedef struct s_player
{
	double pos[2]; //Puede que venga mejor float
	double dir[2];
	double angle;
	double plane[2];
}				t_player;

typedef struct s_map
{
	int		**grid;
	int		size[2];
	int		spawn[2];
	int		player_dir[2]; // [0] = x, [1] = y

	// textures // ?
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
	int		side;
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
	char	*north; //Maybe change to void because of mlx return value when retrieving textures
	char	*south;
	char	*east;
	char	*west;
	int		floor;
	int		ceiling;
	int		stored_values;
}				t_texture;

typedef struct s_data
{
	char		**file;
	int			fd;
	t_mlx		mlx;
	t_texture	textures;
	t_map		map;
	t_player	player;
	t_ray		ray;
}				t_data;

// functions:

int	parse_argument(t_data *data, char *filepath);
void	clear_newlines(char **file);
void	parse_file(t_data *data);
void	get_texture_element(char *line, t_data *data, char **path);
void	get_color_element(char *line, t_data *data, int *color);
int	rgb_to_int(int red, int green, int blue);
int	get_file_elements(t_data *data);
char	**store_file(char *filepath);
int	verify_arguments(int argc, char **argv);
int	c3d_error(char *error);
int	c3d_exit(char *error);

// raycaster.c
void	initialize_variables(t_data *data);

// hooks.c
void	hook(t_data *data);
int		keypressed(int keycode, t_data *data);
int		mousedown(int keycode, int x, int y, t_data *data);

// pixels.c
t_img	*get_img(t_data *data, int width, int height);
void	put_pixel(t_img *img, int x, int y, int color);

// render.c
void	render(t_data *data);
void	set_floor_ceiling(t_data *data);

// movement.c
void	rotate_player(t_data *data, double angle);
#endif // CUB3D_H
