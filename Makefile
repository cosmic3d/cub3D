NAME = cub3D

# -=-=-=-=-	CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

RESET		:= \033[0;39m
BLACK		:= \033[0;30m
RED			:= \033[0;91m
GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
MAGENTA		:= \033[0;95m
CYAN		:= \033[0;96m
GRAY		:= \033[0;90m
WHITE		:= \033[0;97m

# OS
OS = $(shell uname -s)
$(info $(OS))

### Files
# Source files
SRC_DIR = src/
SRC_FILES =	main.c error.c parser.c verify_arguments.c pixels.c raycaster.c hooks.c render.c\

# Format: subdir/file.c | For example: main.c map/init.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

#DEBUG
$(info >	Source files info:)
$(info Source directory: [ $(SRC_DIR) ])
$(info Source files: [ $(SRC_FILES) ])
$(info Source full: [ $(SRC) ])

# Object files
OBJ_DIR = obj/
OBJ    = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))


$(info >	Object files info:)
$(info Object directory: [ $(OBJ_DIR) ])
$(info Object full: [ $(OBJ) ])

# Dependency files
DEPS = $(addprefix $(OBJ_DIR),$(SRC_FILES:%.c=%.d))

$(info >	Dependencies info:)
# $(info Dependency directory: [ $(DEPS_DIR) ])
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
MLX = $(MLX_DIR)$(MLX_LIB)
LIBS += $(LIBFT)
LIBS += $(MLX)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 #Puede que el 02 sea mejor
DFLAGS = -MD -MF
INCLUDE = -I include/ -I $(LIBFT_DIR) -I $(MLX_DIR)
X11_FLAGS = -lXext -lX11
FRAMEWORK_FLAGS = -framework OpenGL -framework Appkit
MATH_FLAGS = -lm
LINUX_FLAGS = $(INCLUDE) $(MATH_FLAGS) $(X11_FLAGS)
MACOS_FLAGS = $(INCLUDE) $(MATH_FLAGS) $(FRAMEWORK_FLAGS)
FLAGS =

$(info Libs = $(LIBS))

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

all: make_libs $(NAME)

make_libs:
	@$(MAKE) -sC $(LIBFT_DIR)
	@$(MAKE) -sC $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(MK)
	@$(MKDIR) $(dir $@)
##	$(CC) $(CFLAGS)  $(DFLAGS) $(OBJ_DIR)$*.d -c $< -o $@ 
	$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@
##La madre que te parió con los wildcards xd


clean:
	@$(RM) $(OBJ)
	@$(RM) $(DEPS)
	@$(RM) $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(MLX_DIR)
	@echo "$(CYAN)Dependencies and objects removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -sC $(LIBFT_DIR)
	@echo "$(RED)$(NAME) Removed$(RESET)"

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
-include $(DEPS)
