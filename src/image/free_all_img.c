#include "visual.h"

void	free_all_img(t_img_data **img_data)
{	
	t_img_data	*tmp;
	
	while (*img_data != NULL)
	{
		tmp = (*img_data)->next;
		free((*img_data)->name);
		free((*img_data)->type);
		free((*img_data)->comment);
		free((*img_data)->pixels_buff);
		free((*img_data)->loaded_img->framebuffer);
		free((*img_data)->loaded_img);
		free(*img_data);
		(*img_data) = tmp;
	}
}