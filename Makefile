NAME = so_long
CC	= cc 
CFLAGS = -Wall -Wextra -Werror 
SOURCE = so_long.c ft_free.c ft_close.c load.c ft_move.c check.c game_check.c check_map.c src.c ./printf/ft_strchr.c ./printf/ft_printadrs.c ./printf/ft_printf.c ./printf/ft_putchar.c ./printf/ft_putnbr_base.c ./printf/ft_putnbr_unsigned.c ./printf/ft_putnbr.c ./printf/ft_putstr.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
SOURCEB =  ./bonus/so_long_bonus.c ./bonus/ft_free_bonus.c ./bonus/enemy_bonus.c ./bonus/print_mvmnt.c ./bonus/ft_close_bonus.c ./bonus/load_bonus.c ./bonus/ft_move_bonus.c ./bonus/check_bonus.c ./bonus/game_check_bonus.c ./bonus/check_map_bonus.c ./bonus/src_bonus.c ./printf/ft_strchr.c ./printf/ft_printadrs.c ./printf/ft_printf.c ./printf/ft_putchar.c ./printf/ft_putnbr_base.c ./printf/ft_putnbr_unsigned.c ./printf/ft_putnbr.c ./printf/ft_putstr.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJ	=	$(SOURCE:.c=.o)
BOBJ = $(SOURCEB:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

bonus: $(BOBJ)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(BOBJ) -o $(NAME)

clean: 
	rm -rf ${OBJ} ${BOBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all
