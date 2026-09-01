#include "visual.h"

void    print_surface_data(t_surface *surf)
{
    printf("Width: %d\n", surf->width);
    printf("Height: %d\n", surf->height);
    printf("Size: %d\n", surf->size);
    printf("(pos_x and pos_y get by last blit)\n");
    printf("pos_x: %d\n", surf->pos_x);
    printf("pos_y: %d\n", surf->pos_y);
    if (surf->mask)
    {
        printf("Mask: true\n");
        printf("Mask_color: %08" PRIX32 "\n", surf->mask_color);
    }
    else
        printf("Mask: false\n");
}