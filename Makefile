NAME = cub3D

# OS
OS = $(shell uname -s)

### Files
# Source files
SRC_DIR = src/
SRC_FILES =	main.c \

# Format: subdir/file.c | For example: main.c map/init.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

#DEBUG
$(info >	Source files info:)
$(info Source directory: [ $(SRC_DIR) ])
$(info Source files: [ $(SRC_FILES) ])
$(info Source full: [ $(SRC) ])

# Object files
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR),$(SRC_FILES:%.c=%.o))

$(info >	Object files info:)
$(info Object directory: [ $(OBJ_DIR) ])
$(info Object full: [ $(OBJ) ])

# Dependency files
DEPS = $(addprefix $(OBJ_DIR),$(SRC_FILES:%.c=%.d))

$(info >	Dependencies info:)
$(info Dependency directory: [ $(DEPS_DIR) ])
$(info Dependency full: [ $(DEPS) ])
# $(info [  ])

# Libraries
LIBS_DIR = libs/

LIBFT_DIR = $(LIBS_DIR)libft/
LIBFT_LIB = libft.a
LIBFT = $(LIBFT_DIR)$(LIBFT_LIB)

ifeq ($(OS),Linux)
	MLX_DIR = $(LIBS_DIR)minilibx_linux/
else ifeq ($(OS),Darwin)
	MLX_DIR = $(LIBS_DIR)minilibx_macos/
endif
MLX_LIB = libmlx.a
MLX = $(MLX_DIR)/$(MLX_LIB)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -MD -MF
INCLUDE = -I include/ $(LIBFT_DIR) $(MLX_DIR)
X11_FLAGS = -lXext -lX11
FRAMEWORK_FLAGS = -framework OpenGL -framework Appkit
MATH_FLAGS = -lm
LINUX_FLAGS = $(INCLUDE) $(MATH_FLAGS) $(X11_FLAGS)
MACOS_FLAGS = $(INCLUDE) $(MATH_FLAGS) $(FRAMEWORK_FLAGS)
FLAGS =

ifeq ($(OS),Linux)
	FLAGS = $(LINUX_FLAGS)
else ifeq ($(OS),Darwin)
	FLAGS = $(MACOS_FLAGS)
endif

$(info OS = $(OS))
$(info Flags = $(FLAGS))
# Commands and utils
RM = rm -rf
MKDIR = mkdir -p
MUTE = &> /dev/null
MK = Makefile

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(MK)
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJ_DIR)/$*.d -c $< -o $@



clean:
	@$(RM) $(OBJ)
	@$(RM) $(DEPS)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
-include $(DEPS)
