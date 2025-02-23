NAME := cub3D
CFLAGS := -g3

CC := cc
RM := rm -rf

LIBTF_DIR := ./lib/libft
LIBMLX := ./lib/MLX42
LIBS := -L$(LIBTF_DIR) -lft

OBJ_DIR := build
INCLUDE_DIR := include
INCLUDES := -I$(INCLUDE_DIR) -I$(LIBTF_DIR) -I$(LIBMLX)/include

SRCS := cub3d.c 
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Caminho para MLX42 no macOS
PATH_MLX = ./lib/MLX42/
MLX = $(addprefix ${PATH_MLX}, build/libmlx42.a)
MLX_A = -L${PATH_MLX}/build -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit

all: libft mlx $(NAME)

libft:
	@$(MAKE) -C $(LIBTF_DIR)

mlx:
	cd $(LIBMLX) && cmake -B build && make -C build


$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS) $(MLX)
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) $(CFLAGS) $(MLX_A) -o $(NAME)

clean:
	@$(MAKE) -C $(LIBTF_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBTF_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME) maps/map.cub

check: all
	valgrind -q --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes ./$(NAME) maps/map.cub

.PHONY: all clean fclean re libft mlx
