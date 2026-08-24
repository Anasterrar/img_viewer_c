#include "visual.h"

t_img_data	*create_img_data(char *fileName)
{
	t_img_data	*new;
	
	new = malloc(sizeof(t_img_data));
	if (!new)
		return (NULL);
	ft_dump(&(new->name), fileName);
	new->previous = NULL;
	new->next = NULL;	
	return (new);	
}