NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread

INCLUDES = -Iincludes/

SRCS =	src/clean_up.c \
		src/events.c \
		src/forks.c \
		src/init.c \
		src/init_utils.c \
		src/log.c \
		src/main.c \
		src/monitor.c \
		src/utils.c

OBJ_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
