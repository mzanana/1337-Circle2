SRCS = ft_hexal.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_unsigned.c ft_voidhex.c 
OBJS = ft_hexal.o ft_printf.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_unsigned.o ft_voidhex.o 

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
