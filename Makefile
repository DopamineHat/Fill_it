NAME = fillit
INCLUDES = -I ./includes
SRC = main.c parsing/ft_open_and_stock.c parsing/ft_mask.c \
algo/resolve.c algo/ft_split_short.c display/ft_display.c \
display/ft_final_display.c parsing/ft_init_stuff.c \
algo/ft_count_bits.c algo/backtracking.c algo/place_one.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address

LIBFT	= ./Libft/libft.a
LIBINC	= -I./Libft
LIBLINK	= -L./Libft -lft

SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj libft $(NAME)

obj:
	mkdir -p ./obj/ ./obj/algo/ ./obj/parsing/ ./obj/display/

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./Libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBLINK) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)
	rm Libft/*.o Libft/*.a

re: fclean all
