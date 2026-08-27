#ifndef GEOMETRY_H
#define GEOMETRY_H
//STRUCT
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

//GLOBAL VARIABLE
#define IN 0
#define OUT 2
//FUNCTION
t_point			*create_point();
t_point     	*create_point_list(int point_count);
t_surface       *create_square(int dimension);
t_surface       *create_rect(int width, int height);
t_surface       *create_line(t_point p1, t_point p2);
t_surface		*create_polygone(int point_count, int (*point_coordonates)[2]);
t_surface   	*create_outlines(t_surface *surface,int size, uint32_t color, int in_out);


void    		draw_square(t_surface *surface, int dimension, int pos_x, int pos_y, uint32_t color);
void    		draw_rect(t_surface *surface, int width, int height, int pos_x, int pos_y, uint32_t color);
void			draw_outlines(t_surface *surface, int size, uint32_t color);

void			print_point(t_point point);
void    		print_point_list(int point_count, t_point *point_list);
void            bresenham_algorithm(t_surface *surface, t_point p1, t_point p2);
t_point     get_surface_pos(t_surface *surface, int mod, int part);
#endif