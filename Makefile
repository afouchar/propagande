NAME = Crusher.app

SRC =	./mod_main.c\
	./mod_copy.c\
	./mod_error.c\
	./mod_glitch.c\

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

LIB = ./libft/*.c

all: $(NAME)
$(NAME):
	@make -C ./libft
	@gcc $(FLAG) $(LIB) -c $(SRC)
	@gcc $(LIB) $(OBJ) -o $(NAME)
clean:
	@rm -f $(OBJ)
fclean:	clean
	@rm -f $(NAME)

re: fclean all
	@rm *.o