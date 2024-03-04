CFLAGS = -Wall -Wextra -Werror
HEAD = ./includes/
SRC = ft_strlen.c ft_itoa.c
		
OBJS = $(SRC:.c=.o)
NAME = libft.a

.c.o:
		cc $(CFLAGS) -c -I $(HEAD) $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re