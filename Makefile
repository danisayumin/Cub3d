vpath %.c src #remover quando usar as linhas comentadas

NAME := cub3D
CFLAGS := -Wextra -Wall -Werror -g3

CC := cc
RM := rm -rf

LIBTF_DIR := ./lib/libft
# GNL_DIR := ./lib/get_next_line
LIBMLX := ./lib/MLX42
LIBS := -L$(LIBTF_DIR) -lft $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# LIBS := -L$(LIBTF_DIR) -lft -L/usr/local/lib -lglfw

OBJ_DIR := build
# OBJ_DIR := src
INCLUDE_DIR := include
INCLUDES := -I$(INCLUDE_DIR) -I$(LIBTF_DIR) -I$(LIBMLX)/include
# INCLUDES := -I$(INCLUDE_DIR) -I$(LIBTF_DIR) -I$(GNL_DIR) -I$(LIBMLX)/include

SRCS := check.c cub3d.c draw.c finish.c ft_atoi.c init.c load.c map.c math_utils.c
SRCS += player.c rays.c read.c utils.c utils2.c
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# # Caminho para MLX42 no macOS
# PATH_MLX = ./lib/MLX42/
# MLX = $(addprefix ${PATH_MLX}, build/libmlx42.a)
# MLX_A = -L${PATH_MLX}/build -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw

all: libft mlx $(NAME)
# all: libft gnl mlx $(NAME)

libft:
	@$(MAKE) -C $(LIBTF_DIR)

# gnl:
# 	@$(MAKE) -C $(GNL_DIR)

mlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
# mlx:
# 	cd $(LIBMLX) && cmake -B build && make -C build

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) $(CFLAGS) -o $(NAME)
# $(NAME): $(OBJS) $(MLX)
# 	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) $(CFLAGS) $(MLX_A) -o $(NAME)

clean: 
	@$(MAKE) -C $(LIBTF_DIR) clean
# 	@$(MAKE) -C $(GNL_DIR) clean
	@$(RM) -rf $(LIBMLX)/build
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBTF_DIR) fclean
# 	@$(MAKE) -C $(GNL_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME) maps/map.cub

check: all
	valgrind -q --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions=suppress.sup ./$(NAME) maps/map.cub
# check: all
# 	valgrind -q --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes ./$(NAME) maps/map.cub

.PHONY: all clean fclean re libft
# .PHONY: all clean fclean re libft gnl mlx
