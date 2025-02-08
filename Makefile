NAME := cub3D
CFLAGS := #-Wextra -Wall -Werror
CFLAGS += -g3

CC := cc
RM := rm -rf

LIBTF_DIR := ./lib/libft
LIBMLX := ./lib/MLX42
LIBS := -L$(LIBTF_DIR) -lft 
#$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

OBJ_DIR := build
INCLUDE_DIR := include
INCLUDES := -I$(INCLUDE_DIR) -I$(LIBTF_DIR) 
#-I$(LIBMLX)/include

SRCS := cub3d.c 
#map.c init.c draw.c utils.c finish.c validation.c read_param.c
#player.c load_params.c math_utils.c rays.c walls.c
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))



PATH_MLX = ./lib/MLX42/
MLX = $(addprefix ${PATH_MLX}, libmlx_Linux.a)
MLX_A = -L${PATH_MLX} -lmlx_Linux -I${PATH_MLX} -lXrender -lXext -lX11 -lm -lz




all: libft $ $(NAME)

libft:
	@$(MAKE) -C $(LIBTF_DIR)

$(MLX):
	@make --quiet -C $(PATH_MLX)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(MLX_A) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS) $(MLX)
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) $(CFLAGS) $(MLX_A) -o $(NAME)

clean: 
	@$(MAKE) -C $(LIBTF_DIR) clean
	make clean -C $(LIBMLX)
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
	./$(NAME) maps/map.cub
