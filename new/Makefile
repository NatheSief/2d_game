NAME		=	so_long
CC			=	cc
FLAG		=	-Wall -Wextra -Werror
LIBFT_PATH	=	./libft/
LIBFT_FILE	=	libft.a
MLX_FILE	=	libmlx.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
MLX_FLAG	=	-lX11 -lXext
MLX_PATH	=	./minilibx-linux/
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		=	main.c					\
				core/errors_display.c	\
				core/garbage.c			\
				core/inits.c			\
				core/utils.c			\
				maps/generate_map.c		\
				parsing/parsing.c		\
				parsing/path.c			\
				render/evolve_display.c	\
				render/launch_game.c	\
				render/mouvements.c		\

SRC_DIR		=	./srcs/

INC_DIR		=	./includes/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

lib:
	make -C $(LIBFT_PATH)

mlx:
	make -sC $(MLX_PATH)

$(NAME): lib mlx $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)

clean:
	make clean -sC $(MLX_PATH)
	make clean -sC $(LIBFT_PATH)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re