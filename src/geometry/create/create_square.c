#include "visual.h"

t_surface	*create_square(int dimension)
{
	t_surface	*square;
	
	square = surface.create(dimension, dimension);
	if (!square)
	{
		//ERROR
		return (NULL);
	}
	return (square);	
}