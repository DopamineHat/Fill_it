NAME = fillit
INCLUDES = -I ./includes

SRC_ALGO =		ft_split_short.c	\
				resolve.c			\
				ft_count_bits.c		\
				place_one.c

SRC_PARSING =	ft_open_and_stock.c		\
				ft_check_tetri.c		\
				ft_init.c

SRC_DISPLAY =	ft_final_display.c

SRC_ALGO_PATH = $(addprefix algo/,$(SRC_ALGO))

SRC_PARSING_PATH = $(addprefix parsing/,$(SRC_PARSING))

SRC_DISPLAY_PATH = $(addprefix display/,$(SRC_DISPLAY))

SRC = main.c $(SRC_ALGO_PATH) $(SRC_PARSING_PATH) $(SRC_DISPLAY_PATH)

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

$(NAME): obj $(OBJ)
	make -C ./Libft
	$(CC) $(CFLAGS) $(LIBLINK) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJDIR)
	make -C Libft/ clean

fclean: clean
	rm -f $(NAME)
	rm -f ./Libft/libft.a

re: fclean all


.PHONY: clean all re fclean
