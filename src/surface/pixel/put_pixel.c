#include "visual.h"

void	put_pixel(t_surface *surf, int pos_x, int pos_y, uint32_t color)
{
	surf->framebuffer[pos_y * surf->width + pos_x] = color;	
}