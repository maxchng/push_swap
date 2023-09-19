# Makefile for push_swap

# Program name
NAME = push_swap
BONUS_NAME = checker

# Source files
SRCS =	push_swap.c \
		utils.c \
		operations.c \
		operations_utils.c \
		instructions_1.c \
		instructions_2.c \
		instructions_3.c \
		ft_strtok.c \
		ps_atoi.c \
		parse_argv.c \
		err_handling.c \
		sort_small.c \
		sort_small_utils.c \
		sort_big.c \
		sort_big_utils_1.c \
		sort_big_utils_2.c \
		count_ascending.c \
		count_descending.c \
		count_utils_1.c \
		count_utils_2.c

BONUS_SRCS = checker.c

GNL_SRCS =	gnl/get_next_line.c \
			gnl/get_next_line_utils.c

# Object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)

# Path to libft library
LIBFT_PATH = ./libft
GNL_PATH = ./gnl

# Run make tool in libft
LIBFT_MAKE = $(MAKE) -C$(LIBFT_PATH)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Linker flags and libraries
LDFLAGS = -L$(LIBFT_PATH)
LDLIBS = -lft

# Include path for header files
LIBFT_INCLUDE = -I$(LIBFT_PATH)
GNL_INCLUDE = -I$(GNL_PATH)

# Remove command and flags
RM = rm
RMFLAGS = -rf

# Default target
all: $(NAME)

# Rule to build program
$(NAME): $(OBJS)
	@$(LIBFT_MAKE) re
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

bonus: $(filter-out push_swap.o, $(OBJS)) $(BONUS_OBJS) $(GNL_OBJS)
	@$(LIBFT_MAKE) re
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $(BONUS_NAME)

# Pattern rule to compile .c files into .o files
%.o: %.c
	@$(CC) $(LIBFT_INCLUDE) $(GNL_INCLUDE) -c $< -o $@

# Remove all object files
clean:
	@$(LIBFT_MAKE) clean
	@$(RM) $(RMFLAGS) $(OBJS) $(BONUS_OBJS) $(GNL_OBJS)

# Remove all generated files
fclean: clean
	@$(LIBFT_MAKE) fclean
	@$(RM) $(RMFLAGS) $(NAME) $(BONUS_NAME)

# Rebuild the program
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re