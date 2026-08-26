#include "visual.h"

void    print_point_list(int point_count, t_point *point_list)
{
    for (int i = 0; i < point_count; i++)
            print_point(point_list[i]);
}