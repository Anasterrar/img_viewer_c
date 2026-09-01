#include "visual.h"

t_point			*create_point();
t_point     	*create_point_list(int point_count);
t_surface       *create_square(int dimension);
t_surface       *create_rect(int width, int height);
t_surface       *create_line(t_point p1, t_point p2);
t_surface		*create_polygon(int point_count, int (*point_coordonates)[2]);
t_surface   	*create_outlines(t_surface *surface,int size, uint32_t color, int in_out);
void    		draw_square(t_surface *surface, int dimension, int pos_x, int pos_y, uint32_t color);
void    		draw_rect(t_surface *surface, int width, int height, int pos_x, int pos_y, uint32_t color);
void            draw_polygon(t_surface *surf, int point_count, int (*point_coordonates)[2]);
void			draw_outlines(t_surface *surface, int size, uint32_t color);
void			print_point(t_point point);
void    		print_point_list(int point_count, t_point *point_list);
bool    		colide_point(t_point point, t_surface *surface);

t_geometry_api geometry =
{
    .create_point = create_point,
    .create_point_list = create_point_list,
    .create_square = create_square,
    .create_rect = create_rect,
    .create_line = create_line,
    .create_polygone = create_polygon,
    .create_outlines = create_outlines,
    .draw_square = draw_square,

    .draw_rect = draw_rect,
    .draw_outlines = draw_outlines,
    .print_point = print_point,
    .print_point_list = print_point_list,
    .colide_point = colide_point,
    .draw_polygon = draw_polygon,
};