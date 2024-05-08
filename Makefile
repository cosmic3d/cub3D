NAME = cub3D
BONUS_NAME = cub3D_bonus

# OS
OS = $(shell uname -s)

### Files
# Source files
SRC_DIR = src/
SRC_FILES =	main.c \
			game_loop.c \
			error.c \
			hooks.c \
			movement.c \
			verify_arguments.c \
			init/init.c \
			init/init2.c \
			parser/parser.c \
			parser/store_file.c \
			parser/get_file_elements.c \
			parser/parse_map.c \
			parser/file_to_grid.c \
			render/pixels.c \
			render/raycaster.c \
			render/render.c \
			render/texture_render.c \

BONUS_SRC_DIR = src_bonus/
BONUS_SRC_FILES = \
    bonus/doors_bonus.c \
    bonus/parser/get_bonus_elements_bonus.c \
    bonus/parser/get_bonus_elements2_bonus.c \
    bonus/parser/parse_map_bonus.c \
    bonus/render/minimap_bonus.c \
    bonus/render/sprites2_bonus.c \
    bonus/render/sprites_bonus.c \
    error_bonus.c \
    game_loop_bonus.c \
    hooks_bonus.c \
    init/init2_bonus.c \
    init/init_bonus.c \
    main_bonus.c \
    movement_bonus.c \
    parser/file_to_grid_bonus.c \
    parser/get_file_elements_bonus.c \
    parser/parse_map_bonus.c \
    parser/parser_bonus.c \
    parser/store_file_bonus.c \
    render/pixels_bonus.c \
    render/raycaster_bonus.c \
    render/render_bonus.c \
    render/texture_render_bonus.c \
    verify_arguments_bonus.c

# Format: subdir/file.c | For example: main.c map/init.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
BONUS_SRC = $(addprefix $(BONUS_SRC_DIR), $(BONUS_SRC_FILES))

# Object files
OBJ_DIR = obj/
OBJ    = $(addprefix $(OBJ_DIR), $(SRC_FILES:%.c=%.o))
BONUS_OBJ_DIR = obj_bonus/
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_SRC_FILES:%.c=%.o))

# Dependency files
DEPS = $(addprefix $(OBJ_DIR),$(SRC_FILES:%.c=%.d))
BONUS_DEPS = $(addprefix $(BONUS_OBJ_DIR),$(BONUS_SRC_FILES:%.c=%.d))

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
CFLAGS = -Wall -Wextra -Werror -g -O2
DFLAGS = -MD -MF
INCLUDE = -I include/ -I $(LIBFT_DIR) -I $(MLX_DIR)
X11_FLAGS = -lXext -lX11
FRAMEWORK_FLAGS = -framework OpenGL -framework Appkit
MATH_FLAGS = -lm
LINUX_MLX_FLAGS = $(INCLUDE) $(MATH_FLAGS) $(X11_FLAGS)
MACOS_FLAGS = $(INCLUDE) $(MATH_FLAGS) $(FRAMEWORK_FLAGS)
MLX_FLAGS =

ifeq ($(OS),Linux)
	MLX_FLAGS = -L$(MLX_DIR) -lmlx $(X11_FLAGS)
else ifeq ($(OS),Darwin)
	MLX_FLAGS = -L$(MLX_DIR) -lmlx $(FRAMEWORK_FLAGS)
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
	@$(MAKE) --no-print-directory $(NAME) > .tmp_out
	@echo "make[1]: 'cub3D' is up to date." > .tmp_expected
	@if diff -q .tmp_out .tmp_expected > /dev/null; then \
		echo "$(YELLOW)'cub3D' is up to date.$(RESET)"; \
	else \
		echo "$(GREEN)'cub3D' was compiled succesfully.$(RESET)                                    "; \
	fi
	@$(RM) .tmp_out .tmp_expected

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(MATH_FLAGS) $(LIBS) -o $(NAME) -lm

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(MK)
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) $(DFLAGS) $(OBJ_DIR)$*.d -c $< -o $@

$(BONUS_NAME): $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX_FLAGS) $(MATH_FLAGS) $(LIBS) -o $(BONUS_NAME) -lm

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c $(MK)
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) $(DFLAGS) $(BONUS_OBJ_DIR)$*.d -c $< -o $@

bonus: title_bonus libft minilibx
	@$(MAKE) --no-print-directory $(BONUS_NAME) > .tmp_out
	@echo "make[1]: 'cub3D_bonus' is up to date." > .tmp_expected
	@if diff -q .tmp_out .tmp_expected > /dev/null; then \
		echo "$(YELLOW)'cub3D_bonus' is up to date.$(RESET)"; \
	else \
		echo "$(GREEN)'cub3D_bonus' was compiled succesfully.$(RESET)                                    "; \
	fi
	@$(RM) .tmp_out .tmp_expected

libft:
	@echo "$(BLUE)Make $(HIGHLIGHT)Libft$(RESET)$(BLUE):$(RESET)"
	@echo "make[1]: Nothing to be done for 'all'." > .tmp_expected
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) > .tmp_out
	@if diff -q .tmp_out .tmp_expected > /dev/null; then \
		echo "$(GREEN)Libft is up to date$(RESET)"; \
	else \
		echo "$(GREEN)Libft compiled succesfully$(RESET)"; \
	fi
	@$(RM) .tmp_expected .tmp_out

minilibx:
	@echo "$(BLUE)Make $(HIGHLIGHT)MiniLibX$(RESET)$(BLUE):$(RESET)"
	@$(MAKE) --no-print-directory -sC $(MLX_DIR) > /dev/null
	@echo "$(GREEN)MiniLibX compiled succesfully$(RESET)";

clean:
	@echo "$(BOLD)clean :$(RESET)"
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@echo "$(RED)Object files removed$(RESET)"
	@$(RM) $(DEPS) $(BONUS_DEPS)
	@echo "$(RED)Dependency files removed$(RESET)"
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@echo "$(RED)Object directories removed$(RESET)"
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@echo "$(RED)'libft' library cleaned$(RESET)"
	@$(MAKE) clean -sC $(MLX_DIR) > /dev/null
	@echo "$(RED)'MiniLibX' library cleaned$(RESET)"
	@$(RM) .tmp_out .tmp_expected

fclean: clean
	@echo "$(BOLD)fclean :$(RESET)"
	@$(RM) $(NAME)
	@echo "$(RED)'$(NAME)' executable removed$(RESET)"
	@$(RM) $(BONUS_NAME)
	@echo "$(RED)'$(BONUS_NAME)' executable removed$(RESET)"
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@echo "$(RED)'libft' library fcleaned$(RESET)"

re: fclean all

title:
	@echo "$(BCYAN)> Compiling $(BOLD)$(UNDERLINE)cub3D$(RESET)$(BCYAN) <$(RESET)"

title_bonus:
	@echo "$(BCYAN)> Compiling $(BOLD)$(UNDERLINE)cub3D$(RESET)$(BCYAN): $(BOLD)$(ITALIC)$(RED)B$(GREEN)O$(YELLOW)N$(CYAN)U$(BLUE)S $(BCYAN)<$(RESET)"

run: all
	./$(NAME) test.cub

bonus_run: bonus
	./$(BONUS_NAME) maps/bonus/map.cub

val: all
	valgrind ./$(NAME) test.cub

.PHONY: all libft minilibx clean fclean re title title_bonus run bonus_run val
-include $(DEPS)
-include $(BONUS_DEPS)
