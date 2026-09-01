#include "visual.h"

t_point     *create_point_list(int point_count)
{
    t_point		*points_list = malloc(sizeof(t_point) * point_count);

    if (!points_list)
        return (NULL);
    return (points_list);
}