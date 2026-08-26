#include "visual.h"

t_surface	*create_square(int dimension)
{
	t_surface	*square;
	
	square = create_surface(dimension, dimension);
	if (!square)
	{
		//ERROR
		return (NULL);
	}
	return (square);	
}