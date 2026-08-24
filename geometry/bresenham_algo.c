#include "visual.h"

void	bresenham_algorithm(t_surface **surface, t_point p1, t_point p2)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;
	int	e2;

	x0 = p1.x;
	y0 = p1.y;
	x1 = p2.x;
	y1 = p2.y;

	dx = absolute_value(x1 - x0);
	dy = absolute_value(y1 - y0) * -1;

	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;

	error = dx + dy;

	while (1)
	{
		put_pixel(surface, x0, y0, 0xFFFFFFFF);

		if (x0 == x1 && y0 == y1)
			break;

		e2 = 2 * error;

		if (e2 >= dy)
		{
			error += dy;
			x0 += sx;
		}

		if (e2 <= dx)
		{
			error += dx;
			y0 += sy;
		}
	}
	for (int i = 0; i < (*surface)->size; i++)
	{
		if (((*surface)->framebuffer[i]) == 0xFFFFFFFF)
			((*surface)->framebuffer[i]) = 0x01000000;
		else
			((*surface)->framebuffer[i]) = TRANSPARENT;
	}
}