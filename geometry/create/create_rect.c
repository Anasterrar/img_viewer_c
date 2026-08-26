#include "visual.h"

t_surface	*create_rect(int width, int height)
{
	t_surface	*rect;
	
	rect = create_surface(width, height);
	if (!rect)
	{
		//ERROR
		return (NULL);
	}
	return (rect);
}