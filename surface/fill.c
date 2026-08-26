#include "visual.h"

void    fill(t_surface *surface, uint32_t color)
{
	color |= 0xFF000000;
	for (int i = 0; i < surface->size; i++)
		if (surface->framebuffer[i] != TRANSPARENT)
			surface->framebuffer[i] = color;
}