# Define program name
NAME = push_swap

# Including libft & ensuring #include "libft.h" works in push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

# Define source files
SRCS = push_swap.c \
	   utlis1.c \
	   utlis2.c \

# Define object files
OBJS = $(SRCS:%.c=%.o)

# Define compiler
CC = cc

# Define flags for compilation
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to remove object files
clean:
		rm -f $(OBJS)
		@make -C $(LIBFT_DIR) clean

# Rule to remove object files and the program
fclean: clean
		rm -f $(NAME)
		@make -C $(LIBFT_DIR) fclean

# Rule to rebuild the program
re: clean fclean all re

.PHONY: clean fclean all re
