CFLAGS = -Wall -Wextra -Werror
SRC = client.c server.c
OBJ = $(SRC:.c=.o)
AR = ar rc
NAME = client_server
LIBFT = ./libft/libft.a
RM = rm -f

all: server client

server: server.o $(LIBFT)
	$(CC) $(CFLAGS) server.o -L ./libft -lft -o server

client: client.o $(LIBFT)
	$(CC) $(CFLAGS) client.o -L ./libft -lft -o client

$(LIBFT):
	@make -C ./libft

clean:
	@$(RM) $(OBJ)
	@make clean -C ./libft/

fclean: clean
	@$(RM) server client
	@make fclean -C ./libft/

re: fclean all

test: $(OBJ) all clean
	./server

.PHONY: all server client clean fclean re test
