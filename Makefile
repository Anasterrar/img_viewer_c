NAME = visual_c

CC = gcc

INCLUDES = -I includes

SRCS = main.c \
       error_handling/errors_img.c \
       geometry/bresenham_algo.c \
       geometry/create_line.c \
       geometry/create_point.c \
       geometry/create_polygone.c \
       geometry/create_rect.c \
       geometry/create_square.c \
       image/create_frame.c \
       image/create_img.c \
       image/free_all_img.c \
       image/load_all_img.c \
       image/print_header_img.c \
       image/get_data/get_comment.c \
       image/get_data/get_dimension.c \
       image/get_data/get_img_data.c \
       image/get_data/get_max_value.c \
       image/get_data/get_type.c \
       surface/blit.c \
       surface/create_surface.c \
       surface/fill.c \
       utils/utils.c \
       utils/math/max.c \
       utils/math/max_list.c \
       utils/math/min.c \
       utils/math/min_list.c \
       utils/math/absolute_value.c \
       visual/visual_destroy.c \
       visual/visual_init.c \
       visual/visual_quit.c

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) $(shell pkg-config --cflags --libs sdl3) $(INCLUDES) -lm -o $(NAME)

clean:
	rm -rf $(NAME)
re: clean all
