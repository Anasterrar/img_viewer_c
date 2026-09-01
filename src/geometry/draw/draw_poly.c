#include "visual.h"

static t_surface	*create_poly(t_surface *surf, int point_count, int (*point_coordonates)[2])
{
	//check input
	t_surface	*polygon;
	
	t_point	*points_list = geometry.create_point_list(point_count);
	for (int i = 0; i < point_count; i++)
	{
		points_list[i].x = point_coordonates[i][0];
		points_list[i].y = point_coordonates[i][1];
	}
	polygon = surface.create(surf->width , surf->height);
	polygon->mask = true;
	polygon->mask_color = TRANSPARENT;
    surface.fill(polygon, TRANSPARENT);
	for (int i = 0; i < point_count; i++)
	{
		int next;

		next = (i + 1) % point_count;
		bresenham_algorithm(
			polygon,
			(t_point){
				points_list[i].x,
				points_list[i].y
			},
			(t_point){
				points_list[next].x,
				points_list[next].y
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
    free(points_list);
	return (polygon);
}

void    draw_polygon(t_surface *surf, int point_count, int (*point_coordonates)[2])
{
    t_surface   *tmp;

    tmp = create_poly(surf, point_count, point_coordonates);
    if (!tmp)
        return ;
    surface.blit(surf, tmp, 0, 0);
    surface.destroy(tmp);
}

