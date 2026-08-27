#include "visual.h"

void	put_pixel(t_surface *surface, int pos_x, int pos_y, uint32_t color)
{
	surface->framebuffer[pos_y * surface->width + pos_x] = color;	
}