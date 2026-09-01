#include "visual.h"

static t_point get_offset(t_surface *surf, int part)
{    
    t_point  offset;

    offset = (t_point){0, 0};
    if (part == 0)
    {
        offset.x = 0;
        offset.y = 0;
    }
    if (part == 1)
    {
        offset.x = surf->width / 2;
        offset.y = 0;
    }
    if (part == 2)
    {
        offset.x = surf->width;
        offset.y = 0;
    }
    if (part == 3)
    {
        offset.x = 0;
        offset.y = surf->height / 2;
    }
    if (part == 4)
    {
        offset.x = surf->width / 2;
        offset.y = surf->height / 2;
    }
    if (part == 5)
    {
        offset.x = surf->width;
        offset.y = surf->height / 2;
    }
    if (part == 6)
    {
        offset.x = 0;
        offset.y = surf->height;
    }
    if (part == 7)
    {
        offset.x = surf->width / 2;
        offset.y = surf->height;
    }
    if (part == 8)
    {
        offset.x = surf->width;
        offset.y = surf->height;
    }
    return (offset);
}

t_point     get_surface_pos(t_surface *surf, int mod, int part)
{
    t_point     pos;
    t_point     offset_parent;
    t_surface   *tmp;

    if (!surf->parent)
    {
        //error
        return (t_point){-1, -1};;
    }
    pos = get_offset(surf, part);
    pos.x += surf->pos_x;
    pos.y += surf->pos_y;
    if (mod == 1)
    {
        tmp = surf;
        offset_parent = (t_point){0, 0};
        while (tmp->parent->parent != NULL)
        {
            offset_parent.x += tmp->parent->pos_x;
            offset_parent.y += tmp->parent->pos_y;
            tmp = tmp->parent;
        }
        pos.x += offset_parent.x;
        pos.y += offset_parent.y;  
    }
    return (pos);
}