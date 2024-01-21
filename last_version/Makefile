# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 10:52:02 by nsiefert          #+#    #+#              #
#    Updated: 2024/01/19 14:54:50 by nsiefert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

CC				=	cc
CC_FLAGS		=	-Wall -Werror -Wextra	

SRCS_PATH		=	./srcs/
INCLUDE_PATH	=	./includes/

LIBFT_PATH		=	./libft/
LIBFT_FILE		=	libft.a
LIBFT_LIB		=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

GRAPHISM_PATH	=	./moteur_graphique/
GRAPHISM_FILE	=	mlx_graphics.a
GRAPHISM_LIB	=	$(addprefix $(GRAPHISM_PATH), $(GRAPHISM_FILE))

SRCS			=

SRC				=	$(addprefix $(SRC_DIR),$(SRCS))
OBJ				=	$(SRC:.c=.o)

.c.o:
	$(CC) $(CC_FLAGS) -c $< -o $@

all : $(NAME)

lib :
	make -C $(LIBFT_PATH)

mlx :
	make -sC $(MLX_PATH)

$(NAME) : lib mlx $(OBJ)
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