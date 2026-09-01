#include "visual.h"

void	bresenham_algorithm(t_surface *surface, t_point p1, t_point p2);

t_surface	*create_polygon(int point_count, int (*point_coordonates)[2])
{
	//check input
	int			width;
	int			height;
	int			buff_x[point_count];
	int			buff_y[point_count];
	int			min_x;
	int			min_y;
	t_surface	*polygon;
	
	t_point	*points_list = geometry.create_point_list(point_count);
	for (int i = 0; i < point_count; i++)
	{
		points_list[i].x = point_coordonates[i][0];
		points_list[i].y = point_coordonates[i][1];
		buff_x[i] = points_list[i].x;
		buff_y[i] = points_list[i].y;

	}
	width = max_list(buff_x, point_count) - min_list(buff_x, point_count) + 1;
	height = max_list(buff_y, point_count) - min_list(buff_y, point_count) + 1; 
	polygon = surface.create(width , height);
	polygon->mask = true;
	polygon->mask_color = TRANSPARENT;
	
	min_x = min_list(buff_x, point_count);
	min_y = min_list(buff_y, point_count);
	for (int i = 0; i < point_count; i++)
	{
		int next;

		next = (i + 1) % point_count;
		bresenham_algorithm(
			polygon,
			(t_point){
				points_list[i].x - min_x,
				points_list[i].y - min_y
			},
			(t_point){
				points_list[next].x - min_x,
				points_list[next].y - min_y
			}
		);
		//put_pixel(polygon, points_list[1].x - min_x, points_list[1].y - min_y, BLACK);	
	}

	int	x1_edge;
	int	x2_edge;
	for (int y = 0; y < polygon->height; y++)
	{
		x1_edge = -1;
		x2_edge = -1;

		for (int x = 0; x < polygon->width; x++)
		{
			if (polygon->framebuffer[y * polygon->width + x] == BLACK)
			{
				if (x1_edge == -1)
					x1_edge = x;
				x2_edge = x;
			}
		}

		if (x1_edge != -1 && x2_edge != -1)
		{
			for (int x = 0; x < polygon->width; x++)
			{
				if(x > x1_edge && x < x2_edge)
					polygon->framebuffer[y * polygon->width + x] = BLACK;
				else if(x < x1_edge || x > x2_edge)
					polygon->framebuffer[y * polygon->width + x] = TRANSPARENT;
			}
			
		}
	}
	return (polygon);
}
