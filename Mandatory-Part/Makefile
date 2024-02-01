NAME		=	so_long

CC		  	=	cc
FLAG		=	-Werror -Wall -Wextra -g3

LIBFT_PATH	=	./libft/
LIBFT_FILE	=	libft.a

MLX_PATH	=	./minilibx-linux/
MLX_FILE	=	libmlx.a
MLX_FLAG	=	-lX11 -lXext
MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

INC_DIR		=	includes/
SRC_DIR		=	srcs/
OBJ_DIR		=	obj/

# Colors
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

SRCS		=	main.c				 	\
				core/free_map.c			\
				core/free_mlx.c			\
				core/utils.c			\
				core/init_utils.c			\
				core/handling_errors.c	\
				core/map_alloc.c		\
				core/init_map.c			\
				core/init_mlx.c			\
				map/path.c				\
				map/map.c				\
				render/mouvements.c		\
				render/launch_game.c	\

SRC		 	=	$(addprefix $(SRC_DIR), $(SRCS))
OBJ		 	=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

lib:
	@make -sC $(LIBFT_PATH)

mlx:
	@make -sC $(MLX_PATH)

$(NAME): lib mlx $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) -I$(INC_DIR) -L$(LIBFT_PATH) -lft $(MLX_EX)

axel: $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) -I$(INC_DIR) -L$(LIBFT_PATH) -lft $(MLX_EX)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAG) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/core
	@mkdir -p $(OBJ_DIR)/map
	@mkdir -p $(OBJ_DIR)/render

clean:
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(MLX_PATH)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
