NAME = cub3D

# OS
OS = $(shell uname -s)
# $(info $(OS))

### Files
# Source files
SRC_DIR = src/
SRC_FILES =	main.c error.c parser.c verify_arguments.c \

# Format: subdir/file.c | For example: main.c map/init.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

#DEBUG
# $(info >	Source files info:)
# $(info Source directory: [ $(SRC_DIR) ])
# $(info Source files: [ $(SRC_FILES) ])
# $(info Source full: [ $(SRC) ])

# Object files
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR),$(SRC_FILES:%.c=%.o))

# $(info >	Object files info:)
# $(info Object directory: [ $(OBJ_DIR) ])
# $(info Object full: [ $(OBJ) ])

# Dependency files
DEPS = $(addprefix $(OBJ_DIR),$(SRC_FILES:%.c=%.d))

# $(info >	Dependencies info:)
# $(info Dependency directory: [ $(OBJ_DIR) ])
# $(info Dependency full: [ $(DEPS) ])
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
CFLAGS = -Wall -Wextra -Werror -O3 #Puede que el 02 sea mejor
DFLAGS = -MD -MF
INCLUDE = -I include/ -I $(LIBFT_DIR) -I $(MLX_DIR)
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

# Commands and utils
RM = rm -rf
MKDIR = mkdir -p
MUTE = &> /dev/null
MK = Makefile

# ANSI escape codes
ESC = \033[
BOLD = $(ESC)1m
RED = $(ESC)91m
GREEN = $(ESC)92m
YELLOW = $(ESC)93m
BLUE = $(ESC)94m
MAGENTA = $(ESC)95m
CYAN = $(ESC)96m
RESET = $(ESC)0m
ITALIC = $(ESC)3m
UNDERLINE = $(ESC)4m
DIM = $(ESC)2m
HIGHLIGHT = $(BOLD)$(ITALIC)$(UNDERLINE)

BRED = $(BOLD)$(RED)
BGREEN = $(BOLD)$(GREEN)
BYELLOW = $(BOLD)$(YELLOW)
BBLUE = $(BOLD)$(BLUE)
BMAGENTA = $(BOLD)$(MAGENTA)
BCYAN = $(BOLD)$(CYAN)

all: title libft minilibx
	@$(MAKE) --no-print-directory $(NAME) > .tmp_cub3d
	@echo "make[1]: 'cub3D' is up to date." > .tmp_expected_cub3d
	@if diff -q .tmp_cub3d .tmp_expected_cub3d > /dev/null; then \
		echo "$(YELLOW)'cub3D' is up to date.$(RESET)"; \
	else \
		echo "$(GREEN)'cub3D' was compiled succesfully.$(RESET)                                    "; \
	fi
	@$(RM) .tmp_cub3d .tmp_expected_cub3d

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(MK)
#	@if [ ! -d $(@D) ]; then \
		echo "$(MAGENTA)mkdir $(@D)$(RESET)"; \
		$(MKDIR) $(@D); \
	fi
	$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) $(DFLAGS) $(OBJ_DIR)$*.d -c $< -o $@
#	@printf "$(YELLOW)Compiling $(UNDERLINE)$@$(RESET)$(YELLOW)...$(RESET)\r"

$(OBJ_DIR):
#	@if [ ! -d $(OBJ_DIR) ]; then \
		echo "$(MAGENTA)mkdir $(OBJ_DIR)"; \
		$(MKDIR) $(OBJ_DIR); \
	fi

libft:
	@echo "$(BLUE)Make $(HIGHLIGHT)Libft$(RESET)$(BLUE):$(RESET)"
	@echo "make[1]: Nothing to be done for 'all'." > .tmp_expected_libft
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) > .tmp_libft
	@if diff -q .tmp_libft .tmp_expected_libft > /dev/null; then \
		echo "$(GREEN)Libft is up to date"; \
	else \
		echo "$(GREEN)Libft compiled succesfully"; \
	fi
	@$(RM) .tmp_expected_libft .tmp_libft

minilibx:
	@echo "$(BLUE)Make $(HIGHLIGHT)MiniLibX$(RESET)$(BLUE):$(RESET)"
	@$(MAKE) --no-print-directory -sC $(MLX_DIR) > /dev/null

clean:
	@echo "$(BOLD)clean :$(RESET)"
	@$(RM) $(OBJ)
	@echo "$(RED)Object files removed$(RESET)"
	@$(RM) $(DEPS)
	@echo "$(RED)Dependency files removed$(RESET)"
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)'$(OBJ_DIR)' directory removed$(RESET)"
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@echo "$(RED)'libft' library cleaned$(RESET)"
	@$(MAKE) clean -sC $(MLX_DIR) > /dev/null
	@echo "$(RED)'MiniLibX' library cleaned$(RESET)"

fclean: clean
	@echo "$(BOLD)fclean :$(RESET)"
	@$(RM) $(NAME)
	@echo "$(RED)'$(NAME)' executable removed$(RESET)"
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@echo "$(RED)'libft' library fcleaned$(RESET)"

re: fclean all

title:
	@echo "$(BCYAN)> Compiling $(BOLD)$(UNDERLINE)cub3D$(RESET)$(BCYAN) <$(RESET)"

run: all
	./$(NAME)

.PHONY: all libft minilibx clean fclean re title run
-include $(DEPS)
