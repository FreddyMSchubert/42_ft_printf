NAME		=	libftprintf.a

SRCS		=	ft_printf.c print_char.c print_hexa.c print_int.c print_u_int.c print_ptr.c print_str.c \

OBJS		=	$(SRCS:.c=.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re