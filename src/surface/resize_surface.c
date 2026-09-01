#include "visual.h"

void    resize_surface(t_surface *surf, int new_width, int new_height)
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
			if (x < surf->width && y < surf->height)
				new[y * new_width + x] = surf->framebuffer[y * surf->width + x];
			else
				new[y * new_width + x] = TRANSPARENT;
		}
	}
    if (new_width > surf->width || new_height > surf->height)
    {
        surf->mask = true;
        surf->mask_color = TRANSPARENT;
    }
    surf->width = new_width;
    surf->height = new_height;
    surf->size = new_width * new_height;
    tmp = surf->framebuffer;
    surf->framebuffer = new;
    free(tmp);
    
}