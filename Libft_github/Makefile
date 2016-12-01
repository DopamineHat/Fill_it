NAME = libft.a
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I ./includes
SRC = ./srcs/*.c

OBJ = *.o

$(NAME) :
	gcc $(FLAGS) -c $(SRC) $(INCLUDES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

norme :
	./norminette
	./norminette include

.PHONY: clean fclean re all
	rm -f $(OBJ)
