#include "visual.h"

void	blit_with_mask(t_surface *surf_under, t_surface *surf_over, int pos_x, int pos_y)
{
	for (int y = 0; y < surf_over->height && y < surf_under->height; y++)
    {
        for (int x = 0; x < surf_over->width && x < surf_under->width; x++)
            put_pixel(surf_under, x + pos_x, y + pos_y, get_pixel(surf_over, x, y));
    }
    
	surf_over->parent = surf_under;
	surf_over->pos_x = pos_x;
	surf_over->pos_y = pos_y;
}