#include "visual.h"

int	get_comment(t_img_data **img_data, char *header_buff, int *i)
{
	int	j;
	int	len;
	int	index;

	j = 0;
	index = *i;
	while (header_buff[*i] < '0' || header_buff[*i] > '9')
	{
		while(header_buff[*i] != '\n')
			(*i)++;
		(*i)++;
	}
	len = *i - index + 1;
	(*img_data)->comment = malloc(len);
	if (!(*img_data)->comment)
		return (0);
	while (header_buff[index] < '0' || header_buff[index] > '9')
	{
		while(header_buff[index] != '\n')
		{	
			(*img_data)->comment[j] = header_buff[index];
			j++;
			index++;
		}
		(*img_data)->comment[j] = header_buff[index];
		j++;
		index++;
	}
	(*img_data)->comment[j] = '\0';
	return (1);
}