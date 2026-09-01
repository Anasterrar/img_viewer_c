#include "visual.h"

void	blit(t_surface *surf_under, t_surface *surf_over, int pos_x, int pos_y)
{
	uint32_t	pixel;

	for (int y = 0; y < surf_over->height && y < surf_under->height; y++)
    {
        for (int x = 0; x < surf_over->width && x < surf_under->width; x++)
		{
			pixel = surf_over->framebuffer[y * surf_over->width + x];
			if (pixel == TRANSPARENT || (surf_over->mask && pixel == surf_over->mask_color))
				continue;
			else
				put_pixel(surf_under, x + pos_x, y + pos_y, pixel);
		}
    }
	surf_over->parent = surf_under;
	surf_over->pos_x = pos_x;
	surf_over->pos_y = pos_y;
}