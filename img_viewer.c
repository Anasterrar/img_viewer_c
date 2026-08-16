#include "visual.h"

extern char    *pixel_buff;
void	print_header(t_img_data	*img_data)
{
	printf("---type---\n%s\n---width---\n%d\n---height---\n%d\n---max_value---\n%d\n",
                img_data->type,
                img_data->width,
                img_data->height,
                img_data->max_value
	);
}

int	get_img_data(t_img_data **img_data, char *header_buff)
{
	int	i;
	int	y;
	char	width[5];
	char	height[5];
	char	max_value[4];
	
	i = 0;
	y = 0;
	while (header_buff[i] != '\n')
	{
		(*img_data)->type[y] = header_buff[i];
		i++;
		y++;
	}
	(*img_data)->type[y] = '\0';
	i++;
	while (header_buff[i] < '0' || header_buff[i] > '9')
	{
		while(header_buff[i] != '\n')
			i++;
		i++;
	}
	y = 0;
	while (header_buff[i] != ' ')
	{
		width[y] = header_buff[i];
		i++;
		y++;
	}
	width[y] = '\0';
	i++;
	y = 0;
        while (header_buff[i] != '\n')
        {
                height[y] = header_buff[i];
                i++;
                y++;
        }
        height[y] = '\0';
	i++;
	y = 0;
	while (header_buff[i] != '\n')
	{	
		max_value[y] = header_buff[i];
		y++;
		i++;
	}
	max_value[y] = '\0';
	(*img_data)->width = atoi(width);
	(*img_data)->height = atoi(height);
	(*img_data)->max_value = atoi(max_value);
	return (i + 1);
}


int	load_img(char *fileName, t_img_data **img_data)
{
	int	fd;
	int	header_len;
	char	header_buff[HEADER_BUFF_SIZE];
	
	if (!img_data)
		return (-1);
	fd = open(fileName, O_RDONLY);
	if (!fd)
	{
		//error_manager
		return (-1);
	}
	read(fd, header_buff, HEADER_BUFF_SIZE);
	close(fd);
	header_len = get_img_data(img_data, header_buff);
	printf("%d", (*img_data)->width * (*img_data)->height + header_len);
	pixel_buff = malloc((*img_data)->width * (*img_data)->height * 3 + header_len);
	fd = open(fileName, O_RDONLY);
        read(fd, pixel_buff, (*img_data)->width * (*img_data)->height * 3 + header_len);
	print_header(*img_data);
	return (header_len);
}
