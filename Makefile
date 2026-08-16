NAME = visual_c

CC = gcc

SRCS = main.c\
       img_viewer.c

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) $(shell pkg-config --cflags --libs sdl3) -o $(NAME)

clean:
	rm -rf $(NAME)
re: clean all
