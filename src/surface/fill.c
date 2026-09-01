#include "visual.h"

void	fill(t_surface *surf, uint32_t color)
{
	if (!surf->mask)
	{
		for (int i = 0; i < surf->size; i++)
			surf->framebuffer[i] = color;
	}
	else
	{
		for (int i = 0; i < surf->size; i++)
		{
			if (surf->framebuffer[i] != surf->mask_color)
				surf->framebuffer[i] = color;
		}
	}
}