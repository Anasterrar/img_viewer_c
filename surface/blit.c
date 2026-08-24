#include "visual.h"

void	blit(t_surface **surface_under, t_surface *surface_over, int pos_x, int pos_y)
{
	int		x;
	int		y;
	int		dst_x;
	int		dst_y;
	uint32_t	alpha;

	y = 0;
	while (y < surface_over->height)
	{
		x = 0;
		while (x < surface_over->width)
		{
			dst_x = x + pos_x;
			dst_y = y + pos_y;
			if (dst_x >= 0 && dst_x < (*surface_under)->width
				&& dst_y >= 0 && dst_y < (*surface_under)->height)
			{	alpha = (surface_over->framebuffer[y * surface_over->width + x]) >> 24;
				if (alpha == 0)
				{
					x++;
					continue;
				}
				(*surface_under)->framebuffer[
					dst_y * (*surface_under)->width + dst_x
				] = surface_over->framebuffer[
					y * surface_over->width + x
				];
			}
			x++;
		}
		y++;
	}
}