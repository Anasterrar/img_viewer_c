#include "visual.h"

t_surface	*create_polygone(int point_count, int **point_coordonates )
{
	//check input
	t_point		*points_list = malloc(sizeof(t_point) * point_count);
	t_surface	*polygone;
	
	for (int i = 0; i < point_count; i++)
	{
		points_list[i].x = point_coordonates[i][0];
		points_list[i].y = point_coordonates[i][1];
	}
	//polygone = create_surface()
	return (polygone);
}
