#include "visual.h"

void    destroy_surface(t_surface *surface)
{
    free(surface->framebuffer);
    //chained list;
    free(surface);
}