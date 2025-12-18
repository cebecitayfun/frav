NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

# MiniLibX Paths (Linux)
# Assuming you will clone minilibx-linux into a folder named 'minilibx-linux'
MLX_PATH = minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a

# Linux Flags: -L<path> -lmlx -lXext -lX11 -lm
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

SRCS = main.c render.c math_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re