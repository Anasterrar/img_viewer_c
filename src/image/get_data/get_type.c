#include "visual.h"

int	get_type(t_img_data **img_data, char *header_buff, int *i)
{
	int	j;
	int	len;
	int	index;

	j = 0;
	index = *i;
	while (header_buff[*i] != '\n')
		(*i)++;
	len = *i - index + 1;
	(*img_data)->type = malloc(len);
	if (!((*img_data)->type))
		return (0);
	while (index < *i)
	{
		(*img_data)->type[j] = header_buff[index];
		index++;
		j++;
	}
	(*img_data)->type[j] = '\0';
	return (1);
}