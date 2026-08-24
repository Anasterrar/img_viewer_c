#include "visual.h"

int	get_max_value(t_img_data **img_data, char *header_buff, int *i)
{
	int	j;
	char	mBuff[5];
	
	j = 0;
	while (header_buff[*i] != '\n')
	{
		mBuff[j] = header_buff[*i];
		j++;
		(*i)++;
	}
	mBuff[j] = '\0';
	(*img_data)->max_value = atoi(mBuff);
	if ((*img_data)->max_value <= 0)
		return (0);
	return (1); 
}