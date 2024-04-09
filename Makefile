CFLAGS = -Wall -Wextra -Werror
SRC = client.c server.c
BONUS_SRC = client_bonus.c server_bonus.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
AR = ar rc
NAME = client_server
LIBFT = ./libft/libft.a
RM = rm -f

all: server client

bonus: server_bonus client_bonus

server: server.o $(LIBFT)
	@$(CC) $(CFLAGS) server.o -L ./libft -lft -o server

client: client.o $(LIBFT)
	@$(CC) $(CFLAGS) client.o -L ./libft -lft -o client

server_bonus: server_bonus.o $(LIBFT)
	@$(CC) $(CFLAGS) server_bonus.o -L ./libft -lft -o server_bonus

client_bonus: client_bonus.o $(LIBFT)
	@$(CC) $(CFLAGS) client_bonus.o -L ./libft -lft -o client_bonus

$(LIBFT):
	@make -C ./libft

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@make clean -C ./libft/

fclean: clean
	@$(RM) server client client_bonus server_bonus
	@make fclean -C ./libft/

re: fclean all

.PHONY: all bonus server client server_bonus client_bonus clean fclean re
