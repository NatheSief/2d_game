# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 14:53:43 by nsiefert          #+#    #+#              #
#    Updated: 2024/01/19 14:55:14 by nsiefert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	mlx-graphics.a

CC				=	@cc
CC_FLAGS		=	-Wall -Werror -Wextra
MLX_FLAG		=	-lX11 -lXext

MLX_PATH		=	./minilibx-linux/
MLX_FILE		=	libmlx.a
MLX_LIB			=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX			=	$(MLX_LIB) $(MLX_FLAG)

SRCS			=

SRC				=	$(addprefix $(SRC_DIR),$(SRCS))
OBJ				=	$(SRC:.c=.o)

.c.o:
	$(CC) $(CC_FLAGS) -c $< -o $@

all : $(NAME)

mlx :
	make -sC $(MLX_PATH)

$(NAME) : mlx $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)

clean :
	make clean -sC $(MLX_PATH)
	make clean -sC $(LIBFT_PATH)
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re : fclean all

.PHONY : all clean fclean re