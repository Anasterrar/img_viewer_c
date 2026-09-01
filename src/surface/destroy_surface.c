#include "visual.h"

void    destroy_surface(t_surface *surf)
{
    free(surf->framebuffer);
    //chained list;
    free(surf);
}