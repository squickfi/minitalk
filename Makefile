CLIENT_NAME = client
SERVER_NAME = server

CLIENT_SRCS = client.c util_funcs.c
SERVER_SRCS = server.c util_funcs.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_DEPS = $(CLIENT_OBJS:.o=.d)
SERVER_DEPS = $(SERVER_OBJS:.o=.d)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME)
	@printf "Client is ready.\n"

$(SERVER_NAME): $(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER_NAME)
	@printf "Server is ready.\n"

clean:
	@$(RM) $(CLIENT_OBJS) $(CLIENT_DEPS) $(SERVER_OBJS) $(SERVER_DEPS)
	@printf "Cleaned.\n"

fclean:
	@$(RM) $(CLIENT_OBJS) $(CLIENT_DEPS) $(SERVER_OBJS) $(SERVER_DEPS)
	@$(RM) $(CLIENT_NAME) $(SERVER_NAME)
	@printf "Cleaned.\n"

re:	fclean all

reclean: re clean

.PHONY: all clean fclean re reclean

include $(wildcard $(CLIENT_DEPS) $(SERVER_DEPS))
