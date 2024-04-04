NAME	=	libft.a

### FIX THIS:
# NO RECOMPILE WHEN TOUCH GET_NEXT_LINE.H or FT_PRINTF.H OR LIBFT.H

### Source files
# ft_printf files
FT_PRINTF_DIR = ft_printf/
FT_PRINTF_SRC = $(FT_PRINTF_DIR)ft_printf.c \
				$(FT_PRINTF_DIR)ft_printf_fd.c \
				$(FT_PRINTF_DIR)wrappers.c \
				$(FT_PRINTF_DIR)ptr_conversion.c \
				$(FT_PRINTF_DIR)char_conversion.c \
				$(FT_PRINTF_DIR)uint_conversion.c \
				$(FT_PRINTF_DIR)str_conversion.c \
				$(FT_PRINTF_DIR)call_conversion.c \
				$(FT_PRINTF_DIR)hex_conversion.c \
				$(FT_PRINTF_DIR)int_conversion.c

# get_next_line files
GNL_DIR = get_next_line/
GNL_SRC =	$(GNL_DIR)get_next_line.c \
			$(GNL_DIR)get_next_line_utils.c

FT_TYPE_DIR = ft_type/
FT_TYPE_SRC =	$(FT_TYPE_DIR)ft_isdigit.c \
				$(FT_TYPE_DIR)ft_toupper.c \
				$(FT_TYPE_DIR)ft_istype_iter.c \
				$(FT_TYPE_DIR)ft_isspace.c \
				$(FT_TYPE_DIR)ft_isalpha.c \
				$(FT_TYPE_DIR)ft_isprint.c \
				$(FT_TYPE_DIR)ft_isascii.c \
				$(FT_TYPE_DIR)ft_isalnum.c \
				$(FT_TYPE_DIR)ft_tolower.c

FT_OTHER_DIR = ft_other/
FT_OTHER_SRC =	$(FT_OTHER_DIR)ft_split.c \
				$(FT_OTHER_DIR)ft_store_file.c \
				$(FT_OTHER_DIR)ft_alloc_array.c

FT_STDLIB_DIR = ft_stdlib/
FT_STDLIB_SRC =	$(FT_STDLIB_DIR)ft_free_array.c \
				$(FT_STDLIB_DIR)ft_max.c \
				$(FT_STDLIB_DIR)ft_isint.c \
				$(FT_STDLIB_DIR)ft_min.c \
				$(FT_STDLIB_DIR)ft_strtol.c \
				$(FT_STDLIB_DIR)ft_atoi.c \
				$(FT_STDLIB_DIR)ft_itoa.c \
				$(FT_STDLIB_DIR)ft_intlen.c \
				$(FT_STDLIB_DIR)ft_calloc.c

FT_STDIO_DIR = ft_stdio/
FT_STDIO_SRC =	$(FT_STDIO_DIR)ft_puthex.c \
				$(FT_STDIO_DIR)ft_puthex_fd.c \
				$(FT_STDIO_DIR)ft_putnbr.c \
				$(FT_STDIO_DIR)ft_putnbr_fd.c \
				$(FT_STDIO_DIR)ft_putchar_fd.c \
				$(FT_STDIO_DIR)ft_putstr_fd.c \
				$(FT_STDIO_DIR)ft_putstr.c \
				$(FT_STDIO_DIR)ft_putaddress.c \
				$(FT_STDIO_DIR)ft_putendl_fd.c

FT_LIST_DIR = ft_list/
FT_LIST_SRC =	$(FT_LIST_DIR)ft_lstnew.c \
				$(FT_LIST_DIR)ft_lstiter.c \
				$(FT_LIST_DIR)ft_lstadd_back.c \
				$(FT_LIST_DIR)ft_lstlast.c \
				$(FT_LIST_DIR)ft_lstadd_front.c \
				$(FT_LIST_DIR)ft_lstclear.c \
				$(FT_LIST_DIR)ft_lstdelone.c \
				$(FT_LIST_DIR)ft_lstsize.c \
				$(FT_LIST_DIR)ft_lstmap.c

FT_STRING_DIR = ft_string/
FT_STRING_SRC =	$(FT_STRING_DIR)ft_strlcpy.c \
				$(FT_STRING_DIR)ft_strlen.c \
				$(FT_STRING_DIR)ft_memset.c \
				$(FT_STRING_DIR)ft_memchr.c \
				$(FT_STRING_DIR)ft_match_str.c \
				$(FT_STRING_DIR)ft_bzero.c \
				$(FT_STRING_DIR)ft_strmapi.c \
				$(FT_STRING_DIR)ft_strndup.c \
				$(FT_STRING_DIR)ft_memcpy.c \
				$(FT_STRING_DIR)ft_strdup.c \
				$(FT_STRING_DIR)ft_strjoin.c \
				$(FT_STRING_DIR)ft_strncmp.c \
				$(FT_STRING_DIR)ft_strchr.c \
				$(FT_STRING_DIR)ft_strlcat.c \
				$(FT_STRING_DIR)ft_substr.c \
				$(FT_STRING_DIR)ft_strchr_i.c \
				$(FT_STRING_DIR)ft_memmove.c \
				$(FT_STRING_DIR)ft_memcmp.c \
				$(FT_STRING_DIR)ft_chrcount.c \
				$(FT_STRING_DIR)ft_strrchr.c \
				$(FT_STRING_DIR)ft_striteri.c \
				$(FT_STRING_DIR)ft_skip_chr.c \
				$(FT_STRING_DIR)ft_strcmp.c \
				$(FT_STRING_DIR)ft_strtrim.c \
				$(FT_STRING_DIR)ft_low_strlen.c \
				$(FT_STRING_DIR)ft_strnstr.c \
				$(FT_STRING_DIR)ft_match_ch.c \
				$(FT_STRING_DIR)ft_strlcmp.c \
				$(FT_STRING_DIR)ft_strrcmp.c \
				$(FT_STRING_DIR)ft_strtok.c \
				$(FT_STRING_DIR)ft_strtok_r.c \
				$(FT_STRING_DIR)ft_strspn.c \
				$(FT_STRING_DIR)ft_strcspn.c \
				$(FT_STRING_DIR)ft_strpbrk.c \
				$(FT_STRING_DIR)ft_strnchr.c \
				$(FT_STRING_DIR)ft_strnchr_i.c

FT_MATH_DIR = ft_math/
FT_MATH_SRC =	$(FT_MATH_DIR)ft_abs.c \
				$(FT_MATH_DIR)ft_pow.c \
				$(FT_MATH_DIR)ft_sqrt.c

SRC =	$(FT_TYPE_SRC) \
		$(FT_STDLIB_SRC) \
		$(FT_OTHER_SRC) \
		$(FT_STDIO_SRC) \
		$(FT_LIST_SRC) \
		$(FT_MATH_SRC) \
		$(FT_STRING_SRC) \
		$(FT_PRINTF_SRC) \
		$(GNL_SRC)

LAST_SRC = $(lastword $(SRC))

# Object files
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))
# Dependency files
DEPS = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.d))

# Compiler + flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra
DFLAGS = -MD -MF
ARFLAGS = rcs
INCLUDE = -I .

# Other tools
RM = rm -rf
MKDIR = mkdir -p
MUTE = &> /dev/null
MK = Makefile

# ANSI codes
ESC = \033[
RESET = $(ESC)0m
ITALIC = $(ESC)3m
DIM = $(ESC)2m

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@ar $(ARFLAGS) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: ./%.c $(MK)
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) -I . $(DFLAGS) $(OBJ_DIR)$*.d -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(RM) $(DEPS)
	@$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
-include $(DEPS)
