NAME		=	vizu

INC			=	includes/

SRC_NAME	=	main.c read_map.c draw_map.c definers.c

SRC_PATH	=	srcs/

OBJ_NAME	=	$(SRC_NAME:.c=.o)

OBJ_PATH	=	srcs/obj/

INC_NAME	=	vizu.h

INC_PATH	=	includes/

LIB_NAME	=	libft.a

LIB_PATH	=	../libft/

LIB_INC_PATH =	../includes/

LIB_INC_NAME=	libft.h


LIB				=	$(addprefix $(LIB_PATH), $(LIB_NAME))
LIB_INC			=	$(addprefix $(LIB_INC_PATH), $(LIB_INC_NAME))
OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC				=	$(addprefix $(INC_PATH), $(INC_NAME))

.PHONY:				all $(LIB_NAME) clean fclean re


all: 				$(NAME)


$(NAME):			$(OBJ)
						@gcc -Wall -Wextra -Werror -lpthread $(OBJ) \
						-lmlx -framework OpenGL -framework AppKit -lm \
						-L $(LIB_PATH) -lft -o $(NAME)
						@echo "(•̀ᴗ•́)و $(NAME) generated!"

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c $(INC) $(LIB_INC)
						@mkdir -p $(OBJ_PATH)
						@gcc -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<

clean:
						@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ $(NAME) is deleting... Wait a sec."
						@rm -f $(OBJ)
						@rm -rf $(OBJ_PATH)

fclean:				clean
						@rm -rf $(NAME)

re:					fclean all
