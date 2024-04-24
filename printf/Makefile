NAME	= libftprintf.a
SRCS=    ft_printf.c ft_printadrs.c ft_putchar.c ft_putnbr.c \
            ft_putnbr_base.c ft_putstr.c ft_putnbr_unsigned.c

OBJS	= ${SRCS:%.c=%.o}

CFLAGS	= -Wall -Wextra -Werror

$(NAME):
	cc $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all