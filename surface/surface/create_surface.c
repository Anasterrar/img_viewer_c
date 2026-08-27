#include "visual.h"

t_surface	*create_surface(int width, int height)
{
	t_surface	*new;
	
	new = malloc(sizeof(t_surface));
	if (!new)
		return (NULL);
	new->framebuffer = malloc((size_t)(width) * height * sizeof(uint32_t));
	new->width = width;
	new->height = height;
	new->size = width * height;
	new->parent = NULL;
	return (new);
}