# Makefile for push_swap

# Program name
NAME = push_swap

# Source files
SRCS =	push_swap.c \
		operations.c \
		operations_utils.c \
		instructions_1.c \
		instructions_2.c \
		instructions_3.c \
		ft_strtok.c \
		ps_atoi.c \
		parse_argv.c \
		err_handling.c \
		sort_big.c \
		sort_big_utils_1.c \
		sort_big_utils_2.c \
		count_steps.c \
		count_steps_utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Path to libft library
LIBFT_PATH = ./libft

# Run make tool in libft
LIBFT_MAKE = $(MAKE) -C$(LIBFT_PATH)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Linker flags and libraries
LDFLAGS = -L$(LIBFT_PATH)
LDLIBS = -lft

# Include path for header files
INCLUDES = -I$(LIBFT_PATH)

# Remove command and flags
RM = rm
RMFLAGS = -rf

# Default target
all: $(NAME)

# Rule to build program
$(NAME): $(OBJS)
	@$(LIBFT_MAKE) re
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

# Pattern rule to compile .c files into .o files
%.o: %.c
	@$(CC) $(INCLUDES) -c $< -o $@

# Remove all object files
clean:
	@$(LIBFT_MAKE) clean
	@$(RM) $(RMFLAGS) $(OBJS)

# Remove all generated files
fclean: clean
	@$(LIBFT_MAKE) fclean
	@$(RM) $(RMFLAGS) $(NAME)

# Rebuild the program
re: fclean all

# Phony targets
.PHONY: all clean fclean re