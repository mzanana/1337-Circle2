SRCS = ft_hexal.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_unsigned.c ft_voidhex.c 
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

%o: %c
	$(CC) $(CFLAGS) $(SRCS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re