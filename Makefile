NAME = hstiv.filler

NAME1 = vizu

LFT = libft/libft.a

SRC = src/main.c src/reader.c src/utils.c src/algo.c src/heatmap.c $(LFT)

HEAD = includes/

WWW = -Wall -Wextra -Werror

$(NAME):
	echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec."
	@make -C libft/ re && gcc -o $@ $(WWW) $(SRC) -I $(HEAD)
	@echo "(•̀ᴗ•́)و $(NAME) generated!".

all: $(NAME)

clean:
	@rm -f *.o
	@make -C libft/ fclean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
