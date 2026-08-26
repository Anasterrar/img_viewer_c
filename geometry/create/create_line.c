#include "visual.h"

t_surface	*create_line(t_point p1, t_point p2)
{
	//check
	t_surface	*line;
	int		surface_width;
	int		surface_height;
	int		min_x;
	int		min_y;
	
	surface_width = absolute_value(p1.x - p2.x) + 1;
	surface_height = absolute_value(p1.y - p2.y) + 1;	
	line = create_surface(surface_width, surface_height);
	//printf("%d %d", lign->width, lign->height);
	if (!line)
		return (NULL);
	min_x = min(p1.x, p2.x); 
	min_y = min(p1.y, p2.y);
	bresenham_algorithm(line,(t_point){p1.x - min_x, p1.y - min_y}, (t_point){p2.x - min_x, p2.y - min_y});
	return	(line);
}