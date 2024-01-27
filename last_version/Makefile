NAME		=	so_long

CC		  	=	cc
FLAG		=	-Wall -Wextra -g3

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

so_long_print :
	@echo "$(GREEN) ------------------------------------------------------------------------$(DEF_COLOR)"
	@echo "$(GREEN)/                                                                        \ $(DEF_COLOR)"
	@echo "$(GREEN)|       ,gg,                                                              |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)|      i8''8i               ,dPYb,                                        |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)|      '8,,8'               IP''Yb                                        |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)|       '88'                I8  8I                                        |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)|       dP'8,               I8  8'                                        |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)|      dP' '8a    ,ggggg,   I8 dP    ,ggggg,    ,ggg,,ggg,     ,gggg,gg   |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)|     dP'   'Yb  dP'  'Y8gggI8dP    dP'  'Y8ggg,8' '8P' '8,   dP'  'Y8I   |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)| _ ,dP'     I8 i8'    ,8I  I8P    i8'    ,8I  I8   8I   8I  i8'    ,8I   |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)| '888,,____,dP,d8,   ,d8' ,d8b,_ ,d8,   ,d8' ,dP   8I   Yb,,d8,   ,d8I   |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)| a8P'Y88888P' P'Y8888P'   8P''Y88P'Y8888P'   8P'   8I   'Y8P'Y8888P'888  |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)|                                                                  ,d8I'  |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)|                                                                ,dP'8I   |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)|                                                               ,8'  8I   |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)|                                                               I8   8I   |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)|                                                               '8, ,8I   |$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN)\                                                                'Y8P'	 /	compilated $(DEF_COLOR)"
	@sleep 0.1
	@echo "$(GREEN) ------------------------------------------------------------------------$(DEF_COLOR)"
	@echo "$(GREEN)				 |	|							$(DEF_COLOR)"
	@echo "$(GREEN)				 |	|							$(DEF_COLOR)"
	@echo "$(GREEN)				 |	|							$(DEF_COLOR)"
	@echo "$(GREEN)				 |	|							$(DEF_COLOR)"
	@echo "$(GREEN)				 |	|							$(DEF_COLOR)"
	@echo "$(GREEN)			  	/	 \							$(DEF_COLOR)"
	@echo "$(GREEN)			       |----------|							$(DEF_COLOR)"

mlx_print:
	@echo "$(BLUE)                        $(RED)    $(GREEN)L.             $(DEF_COLOR)    $(CYAN)              $(YELLOW)     $(MAGENTA)           $(GRAY)	$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(BLUE)                        $(RED)t   $(GREEN)EW:        ,ft $(DEF_COLOR)t   $(CYAN)           i  $(YELLOW) t   $(MAGENTA).          $(GRAY)			S $(DEF_COLOR)"
	@sleep 0.1
	@echo "$(BLUE)             ..       : $(RED)Ej  $(GREEN)E##;       t#E $(DEF_COLOR)Ej  $(CYAN)          LE  $(YELLOW) Ej  $(MAGENTA)Ef.        $(GRAY)			A $(DEF_COLOR)"
	@sleep 0.1
	@echo "$(BLUE)            ,W,     .Et $(RED)E#, $(GREEN)E###t      t#E $(DEF_COLOR)E#, $(CYAN)         L#E  $(YELLOW) E#, $(MAGENTA)E# Wi       $(GRAY):KW,      L	L $(DEF_COLOR)"
	@sleep 0.1
	@echo "$(BLUE)           t##,    ,W#t $(RED)E#t $(GREEN)E#fE#f     t#E $(DEF_COLOR)E#t $(CYAN)        G#W.  $(YELLOW) E#t $(MAGENTA)E#|\#D:     $(GRAY) ,#W:   ,KG	O $(DEF_COLOR)"
	@sleep 0.1
	@echo "$(BLUE)          L###,   j###t $(RED)E#t $(GREEN)E#t D#G    t#E $(DEF_COLOR)E#t $(CYAN)       D#K.   $(YELLOW) E#t $(MAGENTA)E#| \#f.   $(GRAY)  ;#W. jWi		P $(DEF_COLOR)"
	@sleep 0.1
	@echo "$(BLUE)        .E#j##,  G#fE#t $(RED)E#t $(GREEN)E#t  f#E.  t#E $(DEF_COLOR)E#t $(CYAN)      E#K.    $(YELLOW) E#t $(MAGENTA)E#|  \Wt  $(GRAY)   i#KED.		E $(DEF_COLOR)"
	@sleep 0.1
	@echo "$(BLUE)       ;WW; ##,:K#i E#t $(RED)E#t $(GREEN)E#t   t#K: t#E $(DEF_COLOR)E#t $(CYAN)    .E#E.     $(YELLOW) E#t $(MAGENTA)E#|___\;. $(GRAY)    L#W.		$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(BLUE)      j#E.  ##f#W,  E#t $(RED)E#t $(GREEN)E#t    ;#W,t#E $(DEF_COLOR)E#t $(CYAN)   .K#E       $(YELLOW) E#t $(MAGENTA)E#|\Wt     $(GRAY)  .GKj#K.		👀 $(DEF_COLOR)"
	@sleep 0.1
	@echo "$(BLUE)    .D#L    ###K:   E#t $(RED)E#t $(GREEN)E#t     :K#D#E $(DEF_COLOR)E#t $(CYAN)  .K#D        $(YELLOW) E#t $(MAGENTA)E#| \#K;   $(GRAY) iWf  i#K		$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(BLUE)   :K#t     ##D.    E#t $(RED)E#t $(GREEN)E#t      .E##E $(DEF_COLOR)E#t $(CYAN) .W#G         $(YELLOW) E#t $(MAGENTA)E#|___\#E, $(GRAY)LK:    t#		$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(BLUE)   ...      #G      ..  $(RED)E#t $(GREEN)..         G#E $(DEF_COLOR)E#t $(CYAN):W##########Wt$(YELLOW) E#t $(MAGENTA)jLLLLLLLLL;$(GRAY)i       tDj	$(DEF_COLOR)"
	@sleep 0.1
	@echo "$(BLUE)            j           $(RED),;. $(GREEN)            fE $(DEF_COLOR),;. $(CYAN):,,,,,,,,,,,,,$(YELLOW).,;. $(MAGENTA)           $(GRAY)				$(DEF_COLOR)"
	@sleep 0.1
	@echo ""

.c.o:
	$(CC) $(FLAG) -c $< -o $@

lib:
	@make -sC $(LIBFT_PATH)

mlx: mlx_print
	@make -sC $(MLX_PATH)

$(NAME): lib mlx so_long_print $(OBJ_DIR) $(OBJ)
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

.PHONY: all clean fclean re so_long_print
