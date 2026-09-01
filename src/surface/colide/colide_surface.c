#include "visual.h"

bool    colide_surface(t_surface *surf1, t_surface *surf2)
{
    t_point pos_s1;
    t_point pos_s2;

    pos_s1 = surface.get_pos(surf1, GLOBAL, TOP_LEFT);
    pos_s2 = surface.get_pos(surf2, GLOBAL, TOP_LEFT);

    if (pos_s1.x + surf1->width <= pos_s2.x
		|| pos_s2.x + surf2->width <= pos_s1.x
		|| pos_s1.y + surf1->height <= pos_s2.y
		|| pos_s2.y + surf2->height <= pos_s1.y)
		return (false);
    return (true);
}