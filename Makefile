NAME = fillit
INCLUDES = -I ./includes
SRC = main.c parsing/ft_open_and_stock.c parsing/ft_check_tetri.c \
algo/resolve.c algo/ft_split_short.c \
display/ft_final_display.c parsing/ft_init.c \
algo/ft_count_bits.c algo/place_one.c


OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

LIBFT	= ./Libft/libft.a
LIBINC	= -I./Libft
LIBLINK	= -L./Libft -lft

SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: $(NAME)

obj:
	mkdir -p ./obj/ ./obj/algo/ ./obj/parsing/ ./obj/display/

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(NAME): obj $(OBJ)
	make -C ./Libft
	$(CC) $(CFLAGS) $(LIBLINK) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJDIR)
	make -C Libft/ clean

fclean: clean
	rm $(NAME)
	rm ./Libft/libft.a

re: fclean all


.PHONY: clean all re fclean
