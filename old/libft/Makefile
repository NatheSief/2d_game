# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 20:58:55 by nsiefert          #+#    #+#              #
#    Updated: 2024/01/22 11:00:11 by nsiefert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	@cc
CFLAGS		=	-Wall -Wextra -Werror -g3

#Folders
INCLUDE		=	include/
LIBFT 		=	libft/
PRINTF 		=	printf/
GNL 		=	gnl/

OBJ_DIR		=	obj/

RM			=	@rm -f

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

LIBFTSRC = 	ft_atoi.c	 			\
			ft_bzero.c 				\
			ft_isalnum.c 			\
			ft_isalpha.c 			\
			ft_isascii.c 			\
			ft_isdigit.c 			\
			ft_isprint.c 			\
			ft_memchr.c 			\
			ft_memcmp.c 			\
			ft_memcpy.c 			\
			ft_memmove.c 			\
			ft_memset.c 			\
			ft_strchr.c 			\
			ft_strlcat.c 			\
			ft_strlcpy.c 			\
			ft_strlen.c 			\
			ft_strncmp.c 			\
			ft_strnstr.c 			\
			ft_strrchr.c 			\
			ft_tolower.c 			\
			ft_toupper.c 			\
			ft_calloc.c 			\
			ft_strdup.c 			\
			ft_substr.c 			\
			ft_strjoin.c 			\
			ft_strtrim.c 			\
			ft_split.c 				\
			ft_itoa.c 				\
			ft_strmapi.c 			\
			ft_striteri.c 			\
			ft_putchar_fd.c			\
			ft_putstr_fd.c 			\
			ft_putendl_fd.c 		\
			ft_putnbr_fd.c			\

LIBFTSRCB =	ft_lstnew.c 			\
			ft_lstadd_front.c 		\
			ft_lstsize.c 			\
			ft_lstlast.c 			\
			ft_lstadd_back.c 		\
			ft_lstdelone.c 			\
			ft_lstclear.c 			\
			ft_lstiter.c 			\
			ft_lstmap.c

PRINTFSRC = ft_print_hex.c			\
			ft_print_ptr.c			\
			ft_print_hex.c			\
			ft_printf_utils.c		\
			ft_print_unsigned.c	\
			ft_printf.c				\

GNLSRC	  = get_next_line.c			\
			get_next_line_utils.c	\

SRC_LIBFT	= 	$(addprefix $(LIBFT), $(LIBFTSRC))
OBJ_LIBFT	= 	$(addprefix $(OBJ_DIR), $(LIBFTSRC:.c=.o))
SRC_LIBFTB	= 	$(addprefix $(LIBFT), $(LIBFTSRCB))
OBJ_LIBFTB	= 	$(addprefix $(OBJ_DIR), $(LIBFTSRCB:.c=.o))

SRC_PRINTF	=	$(addprefix $(PRINTF), $(PRINTFSRC))
OBJ_PRINTF	= 	$(addprefix $(OBJ_DIR), $(PRINTFSRC:.c=.o))

SRC_GNL		=	$(addprefix $(GNL), $(GNLSRC))
OBJ_GNL		= 	$(addprefix $(OBJ_DIR), $(GNLSRC:.c=.o))

OBJF		=	.cache_exists

all: print_lib $(NAME)

print_lib :
	@echo "$(MAGENTA)     /\__\      ___        /\  \         /\  \         /\  \     	$(RED)A	$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(MAGENTA)    /:/  /     /\  \      /::\  \       /::\  \        \:\  \    	$(RED)M	$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(MAGENTA)   /:/  /      \:\  \    /:/\:\  \     /:/\:\  \        \:\  \   	$(RED)E	$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(MAGENTA)  /:/  /       /::\__\  /::\_\:\__\   /::\_\:\  \       /::\  \  	$(RED)L	$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(MAGENTA) /:/__/     __/:/\/__/ /:/\:\ \:|__| /:/\:\ \:\__\     /:/\:\__\ 	$(RED)I	$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(MAGENTA) \:\  \    /\/:/  /    \:\_\:\/:/  / \/__\:\ \/__/    /:/  \/__/ 	$(RED)O	$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(MAGENTA)  \:\  \   \::/__/      \:\ \::/  /       \:\__\     /:/  /      	$(RED)R	$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(MAGENTA)   \:\  \   \:\__\       \:\/:/  /         \/__/     \/__/       	$(RED)E	$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(MAGENTA)    \:\__\   \/__/        \::/__/                                	$(RED)E	$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(MAGENTA)     \/__/                 _                            		  		$(DEF_COLOR)"
	@sleep 0.1

$(NAME): $(OBJ_LIBFT) $(OBJ_LIBFTB) $(OBJ_PRINTF) $(OBJ_GNL)
	@ar rc $(NAME) $(OBJ_LIBFT) $(OBJ_LIBFTB) $(OBJ_PRINTF) $(OBJ_GNL)
	@ranlib $(NAME)
	
$(OBJ_DIR)%.o: $(LIBFT)%.c $(OBJF)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(PRINTF)%.c $(OBJF)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(GNL)%.c $(OBJF)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_LIBFT) $(OBJ_LIBFTB) $(OBJ_PRINTF) $(OBJ_GNL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re print_lib