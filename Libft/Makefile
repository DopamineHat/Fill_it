NAME = libft.a
FLAGS = -Wall -Werror -Wextra
INCDIR = -I ./includes
OBJDIR = ./obj/
SRCDIR = ./
OBJ = $(addprefix ./obj/, $(FILES:.c=.o))
SRC = $(addprefix ./srcs/, $(FILES))
FILES_OBJ= $(FILES:.c=.o)
FILES = ft_atoi.c \
ft_bzero.c \
ft_is_space.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_lstadd.c \
ft_lstdel.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstnew.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_pow.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_sqrt.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strsplit.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_swap_universal.c \
ft_swapvoidpt.c \
ft_tolower.c \
ft_toupper.c

all : $(NAME)

obj:
	mkdir -p ./obj/ ./obj/srcs/

./obj/%.o: ./srcs/%.c
	gcc $(FLAGS) $(INCDIR) -o $@ -c $<

$(NAME): obj $(addprefix ./obj/, $(FILES_OBJ))
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)



clean :
	rm -f $(OBJ)
	rm -rf $(OBJDIR)
fclean : clean
	rm -f $(NAME)

re : fclean all

norme :
	./norminette
	./norminette include

.PHONY: clean fclean re all
	rm -f $(OBJ)
