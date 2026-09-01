#include "visual.h"

void    create_frame(t_img_data **img_data)
{
        int     i;
		int	pixel_index;

        i = 0;
		pixel_index = (*img_data)->pixels_start;
        for (; i < (*img_data)->width * (*img_data)->height; i++)
			((*img_data)->loaded_img->framebuffer)[i] = pixel(&pixel_index, &((*img_data)->pixels_buff));
}