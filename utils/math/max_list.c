#include "visual.h"

int     max_list(int *n_list, int size)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (n_list[i] > n_list[max])
			max = i;
		i++;
	}
	return (n_list[max]);
}