#include "visual.h"

void	blit(t_surface *surface_under, t_surface *surface_over,
		int pos_x, int pos_y)
{
	int		x;
	int		y;
	int		src_x;
	int		src_y;
	uint32_t	pixel;

	y = pos_y;
	while (y < pos_y + surface_over->height)
	{
		x = pos_x;
		while (x < pos_x + surface_over->width)
		{
			if (x >= 0 && x < surface_under->width
				&& y >= 0 && y < surface_under->height)
			{
				src_x = x - pos_x;
				src_y = y - pos_y;

				pixel = surface_over->framebuffer[
					src_y * surface_over->width + src_x];

				if (surface_under->framebuffer[
						y * surface_under->width + x] != TRANSPARENT && pixel != TRANSPARENT)
				{
					surface_under->framebuffer[
						y * surface_under->width + x] = pixel;
				}
			}
			x++;
		}
		y++;
	}
}