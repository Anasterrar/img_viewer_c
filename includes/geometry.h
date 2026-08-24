#ifndef GEOMETRY_H
#define GEOMETRY_H
//STRUCT
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
//FUNCTION
t_point			*create_point();
t_surface       *create_square(int dimension);
t_surface       *create_rect(int width, int height);
t_surface       *create_line(t_point p1, t_point p2);
t_surface		*create_polygone(int point_count, int **point_coordonates );
void            bresenham_algorithm(t_surface **surface, t_point p1, t_point p2);
#endif