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
#define O_RDONLY 00

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


typedef struct s_player
{
	double pos[2]; //Puede que venga mejor float
	double dir[2];
	double plane[2];
}				t_player;

typedef struct s_map
{
	int		**grid;
	int		size[2];
	int		spawn[2];
	
	// textures // ?
}				t_map;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*window;
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
void	c3d_exit(char *error);
char	*get_color_str(char *token);

#endif // CUB3D_H
