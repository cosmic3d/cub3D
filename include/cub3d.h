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
#elif defined __APPLE__
	#include "../libs/minilibx_macos/mlx.h"
#endif

// Textures
#define NO "../textures/north.png"
#define SO "../textures/south.png"
#define WE "../textures/west.png"
#define EA "../textures/east.png"
#define FLOOR 7368816
#define CEILING 7368816
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
#define ERR_INVALID_FILE_EXTENSION "The file provided is not a .cub file"
#define ERR_CANNOT_OPEN_FILE "Failure to open the file provided"
#define ERR_CANNOT_CLOSE_FILE "Failure to close the file provided"
#define ERR_INVALID_FILE_FORMAT "The file provided doesn't follow the guidelines"
// Fatal errors
#define ERR_MALLOC "Memory allocation failed"


typedef struct s_player
{
	double	x;
	double	y;
}				t_player;

typedef struct s_map
{
	int**	grid;
	int		width;
	int		height;
	int		spawn_x; // ?
	int		spawn_y; // ?
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
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor;
	int		ceiling;
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

#endif // CUB3D_H
