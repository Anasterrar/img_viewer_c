#include "visual.h"

void	fill(t_surface *surface, uint32_t color)
{
	if (!surface->mask)
	{
		for (int i = 0; i < surface->size; i++)
			surface->framebuffer[i] = color;
	}
	else
	{
		for (int i = 0; i < surface->size; i++)
		{
			if (surface->framebuffer[i] != surface->mask_color)
				surface->framebuffer[i] = color;
		}
	}
}