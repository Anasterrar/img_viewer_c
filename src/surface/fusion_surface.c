#include "visual.h"

static t_surface   *fusion_left(t_surface *surf1, t_surface *surf2)
{
    t_surface   *new;
    int         t_width;
    int         t_height;
    
    t_width = surf1->width + surf2->width;
    t_height = max(surf1->height, surf2->height);
    new = surface.create(t_width, t_height);
    for (int y = 0; y < t_height; y++)
    {
        for (int x = 0; x < surf1->width; x++)
        {
            if (y < surf1->height)
                put_pixel(new, x, y, get_pixel(surf1, x, y));
            else if(y >= surf1->height)
                put_pixel(new, x, y, TRANSPARENT);
        }
    }
    for (int y = 0; y < t_height; y++)
    {
        for (int x = surf1->width; x < t_width; x++)
        {
            if (y < surf2->height)
                put_pixel(new, x, y, get_pixel(surf2, x - surf1->width, y));
            else if(y >= surf2->height)
                put_pixel(new, x, y, TRANSPARENT);
        }
    }
    return(new);
    
}

static t_surface   *fusion_bottom(t_surface *surf1, t_surface *surf2)
{
    t_surface   *new;
    int         t_width;
    int         t_height;

    t_width = max(surf1->width, surf2->width);
    t_height = surf1->height + surf2->height;
    new = surface.create(t_width, t_height);
    for (int y = 0; y < surf1->height; y++)
    {
        for (int x = 0; x < t_width; x++)
        {
            if (x < surf1->width)
                put_pixel(new, x, y, get_pixel(surf1, x, y));
            else if(x >= surf1->width)
                put_pixel(new, x, y, TRANSPARENT);
        }
    }
    for (int y = surf1->height; y < t_height; y++)
    {
        for (int x = 0; x < t_width; x++)
        {
            if (x < surf2->width)
                put_pixel(new, x, y, get_pixel(surf2, x, y - surf1->height));
            else if(x >= surf2->width)
                put_pixel(new, x, y, TRANSPARENT);
        }
    }
    return(new);
}

t_surface   *fusion_surface(t_surface *surf1, t_surface *surf2, int way)
{
    t_surface   *new;

    if (way == LEFT)
        new = fusion_left(surf1, surf2);

    else if (way == BOTTOM)
        new = fusion_bottom(surf1, surf2);
    else
    {
        //error
        return (NULL);
    }
    return (new);
}