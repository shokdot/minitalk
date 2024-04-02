CFLAGS = -Wall -Wextra -Werror
SRC = client.c server.c
OBJ = $(SRC:.c=.o)

all: server client

server: server.o

client: client.o

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f server client

re: fclean all

test: $(OBJ) all clean
	./server
