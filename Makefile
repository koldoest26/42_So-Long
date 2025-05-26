NAME        = so_long

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC_DIR     = src

SRCS        = $(SRC_DIR)/checks.c \
              $(SRC_DIR)/checks_utils.c \
              $(SRC_DIR)/mlx_end.c \
              $(SRC_DIR)/mlx_moves.c \
              $(SRC_DIR)/mlx_start.c \
              $(SRC_DIR)/mlx_start_utils.c \
              $(SRC_DIR)/so_long.c \
              $(SRC_DIR)/valid_path.c \
              $(SRC_DIR)/valid_path_free.c

OBJS        = $(SRCS:.c=.o)

INCLUDES    = -I. -Ilibft -Iminilibx

LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

MLX_DIR     = minilibx
MLX_A       = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -lXext -lX11

all: $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(MLX_A):
	make -C $(MLX_DIR)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	$(CC)  $(OBJS) $(LIBFT_A) $(MLX_A) $(MLX_FLAGS) -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

