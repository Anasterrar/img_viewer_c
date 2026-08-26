#include "visual.h"

t_point	*create_point()
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	if (!new)
		return (NULL);
	return (new);
}