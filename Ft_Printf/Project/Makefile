SRCS = ft_hexal.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_unsigned.c ft_voidhex.c 
OBJS = ft_hexal.o ft_printf.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_unsigned.o ft_voidhex.o 

SRCS_BONUS = ft_hexal_bonus.c ft_plus_bonus.c ft_printf_bonus.c ft_putchar_bonus.c ft_putnbr_bonus.c ft_putstr_bonus.c ft_unsigned_bonus.c ft_voidhex_bonus.c 
OBJS_BONUS = ft_hexal_bonus.o ft_plus_bonus.o ft_printf_bonus.o ft_putchar_bonus.o ft_putnbr_bonus.o ft_putstr_bonus.o ft_unsigned_bonus.o ft_voidhex_bonus.o

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re