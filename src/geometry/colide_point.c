#include "visual.h"

t_point     	get_surface_pos(t_surface *surface, int mod, int part);

bool    colide_point(t_point point, t_surface *surface)
{
    t_point     surf_pos;
    
    surf_pos = get_surface_pos(surface, GLOBAL, TOP_LEFT);
    if (point.x >= surf_pos.x
        && point.x <= surf_pos.x + surface->width
        && point.y > surf_pos.y
        && point.y <= surf_pos.y + surface->height
    )
        return(true);
    return (false);
}