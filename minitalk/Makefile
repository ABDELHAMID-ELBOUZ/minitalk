NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_SERVER = server.c utils.c ft_itoa.c
SRCS_CLIENT = client.c utils.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(NAME)

$(NAME): server client

server: $(OBJS_SERVER)
	$(CC) $(OBJS_SERVER)  -o server

client: $(OBJS_CLIENT)
	$(CC) $(OBJS_CLIENT) -o client

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f server client

re: fclean all
