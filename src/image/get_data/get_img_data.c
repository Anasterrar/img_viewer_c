#include "visual.h"

int	get_img_data(t_img_data **img_data, char *header_buff)
{
	int	i;
    (*img_data)->size = (*img_data)->width * (*img_data)->width * 3 + (*img_data)->pixels_start;	
	i = 0;
	if (get_type(img_data, header_buff, &i) == 0)
		return (0);
	i++;
	if (get_comment(img_data, header_buff, &i) == 0)
		return (0);
	if (get_dimension(img_data, header_buff, &i) == 0)
		return (0);
	i++;
	if (get_max_value(img_data, header_buff, &i) == 0)
		return (0);
	(*img_data)->pixels_start = i + 1;
	(*img_data)->size = (*img_data)->width * (*img_data)->height * 3 + (*img_data)->pixels_start;
	(*img_data)->pixels_buff = malloc((*img_data)->size);
	(*img_data)->loaded_img = surface.create((*img_data)->width, (*img_data)->height);
	return (1);
}