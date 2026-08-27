NAME = visual_c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes

SRCS = main.c \
       error_handling/errors_img.c \
       geometry/bresenham_algo.c \
       geometry/create/create_line.c \
       geometry/create/create_point.c \
       geometry/create/create_point_list.c \
       geometry/print_point.c \
       geometry/print_point_list.c \
       geometry/create/create_polygone.c \
       geometry/create/create_rect.c \
       geometry/create/create_square.c \
       geometry/create/create_outlines.c \
       geometry/draw/draw_outlines.c \
       geometry/draw/draw_square.c \
       geometry/draw/draw_rect.c \
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
       surface/fill.c \
       surface/clear.c \
       surface/pixel/put_pixel.c \
       surface/pixel/get_pixel.c \
       surface/surface/create_surface.c \
       surface/surface/destroy_surface.c \
       surface/surface/resize_surface.c \
       surface/get/get_surface_size.c \
       surface/get/get_surface_width.c \
       surface/get/get_surface_height.c \
       surface/get/get_surface_pos.c \
       surface/mask/put_mask.c \
       surface/mask/remove_mask.c \
       utils/utils.c \
       utils/math/max.c \
       utils/math/max_list.c \
       utils/math/min.c \
       utils/math/min_list.c \
       utils/math/absolute_value.c \
       visual/visual_destroy.c \
       visual/visual_init.c \
       visual/visual_quit.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lSDL3 -lm

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

a: fclean all

re: a clean 

.PHONY: all clean fclean a re