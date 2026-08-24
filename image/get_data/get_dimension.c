#include "visual.h"

int	get_dimension(t_img_data **img_data, char *header_buff, int *i)
{
	int	j;
	char	wBuff[5];
	char    hBuff[5];
	
	j = 0;
	while (header_buff[*i] != ' ')
	{
		wBuff[j] = header_buff[*i];
		(*i)++;
		j++;
	}
	wBuff[j] = '\0';
	(*i)++;
	j = 0;
	while (header_buff[*i] != '\n')
	{
		hBuff[j] = header_buff[*i];
		(*i)++;
		j++;
	}
	hBuff[j] = '\0';
	(*img_data)->width = atoi(wBuff);
	(*img_data)->height = atoi(hBuff);
	if ((*img_data)->width * (*img_data)->height == 0)
		return (0);
	return (1);
}