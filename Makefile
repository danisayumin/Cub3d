NAME := cub3D
CFLAGS := -Wextra -Wall -Werror
CFLAGS += -g3

CC := cc
RM := rm -rf

LIBTF_DIR := ./lib/libft
LIBMLX := ./lib/MLX42
LIBS := -L$(LIBTF_DIR) -lft $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

OBJ_DIR := build
INCLUDE_DIR := include
INCLUDES := -I$(INCLUDE_DIR) -I$(LIBTF_DIR) -I$(LIBMLX)/include

SRCS := cub3d.c 
#map.c init.c draw.c utils.c finish.c validation.c read_param.c
#player.c load_params.c math_utils.c rays.c walls.c
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: libft mlx $(NAME)

libft:
	@$(MAKE) -C $(LIBTF_DIR)

mlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) $(CFLAGS) -o $(NAME)

clean: 
	@$(MAKE) -C $(LIBTF_DIR) clean
	@$(RM) -rf $(LIBMLX)/build
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(MAKE) -C $(LIBTF_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME) maps/map.cub

check: all
	valgrind -q --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions=suppress.sup ./$(NAME) maps/map.cub

.PHONY: all clean fclean re libft update_modules init_modules