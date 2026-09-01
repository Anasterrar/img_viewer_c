NAME = visual_c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

SRC_DIR = src

SRCS = main.c \
	   $(shell find $(SRC_DIR) -type f -name '*.c')

OBJS = $(SRCS:.c=.o)

LIBS = -lSDL3 -lm


# ─────────────────────────────────────────────
# BUILD
# ─────────────────────────────────────────────

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


# ─────────────────────────────────────────────
# CLEAN
# ─────────────────────────────────────────────

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all clean


.PHONY: all clean fclean re