NAME	= push_swap

CC	= gcc

RM	= rm -f

SRCS	=	src/main.c			\
		src/algo.c			\
		src/gestion_of_chain_list.c	\
		src/stock_mouve.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -Wall -Wextra -O3 -g3

all: $(NAME)

$(NAME): $(OBJS)
	 cd lib/my/; make re
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -L./lib -lmy -g3

clean:
	$(RM) $(OBJS)
	$(RM) lib/libmy.a

fclean: clean
	$(RM) $(NAME)
	cd lib/my/; make fclean
re: fclean all

.PHONY: all clean fclean re
