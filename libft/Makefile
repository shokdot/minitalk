NAME = libft.a
SRC = $(wildcard *.c)
HEADER = $(wildcard ./headers/*.h)
OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

all:$(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re:fclean all

.PHONY: all clean fclean re
