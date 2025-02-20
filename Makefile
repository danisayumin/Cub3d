NAME	=	cub3d


CC		=	cc
CFLAGS	=	
#-Wall -Wextra -Werror -g3
DEBUG	=	-g3 -fsanitize=address -DDEBUG_FLAG=1 #-fsanitize=address
RM		=	rm -f

SRC		=	cub3d.c check.c init.c load.c map.c read.c utils.c utils2.c \

COLOR_INFO = \033[1;36m
COLOR_SUCCESS = \033[1;32m
COLOR_RESET = \033[0m

EMOJI_INFO = 🌈
EMOJI_SUCCESS = 🎉
EMOJI_CLEAN = 🧹
EMOJI_RUN = 🚀

SRC		:=	$(SRC:%=src/%)
OBJ		=	$(SRC:%.c=%.o)

INC_DIR	=	-Isrc


LIBFLAGS	+= -lmlx42 -L./src
MLX42		=	libmlx42.a
MLX42_DIR	=	MLX42
LIBRARYS	+=	MLX42.lib
INC_DIR		+=	-I$(MLX42_DIR)/include/MLX42
ifeq ($(shell uname), Darwin)
LIBFLAGS	+= -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
else
LIBFLAGS	+= -ldl -lglfw -pthread -lm
endif

all: $(NAME)
bonus: all

$(NAME): $(OBJ)
	cd $(MLX42_DIR) && cmake -B build -DDEBUG=1
	cd $(MLX42_DIR) && cmake --build build -j4
	cp $(MLX42_DIR)/build/libmlx42.a ./src
	@printf "$(COLOR_INFO)$(EMOJI_INFO)  Compiling $(NAME)...$(COLOR_RESET)\t"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFLAGS) $(INC_DIR) -o $@
	@sleep 0.25
	@printf "✅\n"

$(MLX42_DIR):
	@printf "$(COLOR_INFO)$(EMOJI_INFO)  Initializing submodules...$(COLOR_RESET)\t"
	@git submodule update --init --recursive
	@sleep 0.25
	@printf "✅\n"
	@printf "$(COLOR_INFO)$(EMOJI_INFO)  Building MLX42...$(COLOR_RESET)\t\t"
	@sleep 0.25
	@printf "✅\n"

norm:
	@norminette $(SRCS) incl/fractol.h libft

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $< $(INC_DIR)

clean:
	@$(RM) $(OBJ)
	@$(RM) ./src/libmlx42.a
fclean: clean
	@$(RM) $($(LIBRARYS:%.lib=%))
	@$(RM) $(NAME)

$(LIBRARYS:%=%.clean): %.lib.clean:
	@$(RM) $($*)
	@$(MAKE) -C $($*_DIR) fclean
	@$(RM) $*.lib

re: fclean all

.PHONY: bonus norm all clean fclean re
