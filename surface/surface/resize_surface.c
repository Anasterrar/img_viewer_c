#include "visual.h"

void    resize_surface(t_surface *surface, int new_width, int new_height)
{
    uint32_t    *new;
    uint32_t    *tmp;
    if (new_width * new_height < 4)
        return;

    new = malloc((size_t)(new_width) * new_height * sizeof(uint32_t));
    if (!new)
        return;
    for (int y = 0; y < new_height; y++)
	{
		for (int x = 0; x < new_width; x++)
		{
			if (x < surface->width && y < surface->height)
				new[y * new_width + x] = surface->framebuffer[y * surface->width + x];
			else
				new[y * new_width + x] = TRANSPARENT;
		}
	}
    if (new_width > surface->width || new_height > surface->height)
    {
        surface->mask = true;
        surface->mask_color = TRANSPARENT;
    }
    surface->width = new_width;
    surface->height = new_height;
    surface->size = new_width * new_height;
    tmp = surface->framebuffer;
    surface->framebuffer = new;
    free(tmp);
    
}