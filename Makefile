CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

NAME_CLIENT = client
NAME_SERVER = server

SRCS_CLIENT = client.c utils.c
SRCS_SERVER = server.c utils.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

bonus: all

clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
