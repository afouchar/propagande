NAME = PNGCrusher.app

SRC =	./main_png.c\
	./error_png.c\
	./args_png.c\
	./copy_png.c\
	./glitch_png.c\

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

LIB =	./libft/*.c\

all: $(NAME)
$(NAME):
	@make -C ./libft
	@gcc $(FLAG) $(LIB) -c $(SRC)
	@gcc $(LIB) -lpng $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)
fclean:	clean
	@rm -f $(NAME)

re: fclean all
	@rm *.o