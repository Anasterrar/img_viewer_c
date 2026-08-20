#include "visual.h"

extern t_img_data      *img_data;

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

int	get_img_data(t_img_data **img_data, char *header_buff)
{
	int	i;
	
	i = 0;
	if (get_type(img_data, header_buff, &i) == 0)
		return (0);
	i++;
	if (get_comment(img_data, header_buff, &i) == 0)
		return (0);
	if (get_dimension(img_data, header_buff, &i) == 0)
		return (0);
	i++;
	if (get_max_value(img_data, header_buff, &i) == 0)
		return (0);
	(*img_data)->pixels_start = i + 1;
	(*img_data)->size = (*img_data)->width * (*img_data)->width * 3 + (*img_data)->pixels_start;
	(*img_data)->pixels_buff = malloc((*img_data)->size);
	return (1);
}

t_img_data	*load_img(char *fileName)
{
	int	fd;
	char    header_buff[HEADER_BUFF_SIZE];
	t_img_data	*img_data;

	img_data = create_img_data(fileName);	
	if (!img_data)
		return (NULL);
	fd = open(fileName, O_RDONLY);
	if (!fd)
	{
		//error_manager
		return (0);
	}
	read(fd, header_buff, HEADER_BUFF_SIZE);
	close(fd);
	//Get img data
	if(get_img_data(&img_data, header_buff) == 0)
		return (NULL);
	fd = open(fileName, O_RDONLY);
        read(fd, img_data->pixels_buff, img_data->size);
	return (img_data);
}

t_img_data	*load_all_img(int argc, char **argv)
{
	int	i;
	t_img_data	*first;
	t_img_data	*tmp;
	t_img_data	*new;
	
	i = 1;
	first = load_img(argv[i]);
	if (!first)
		return (NULL);
	if (argc -1 <= 1)
		return (first);
	i++;
	tmp = first;
	for (; i < argc; i++)
	{
		new = load_img(argv[i]);
		if (!new)
			break;
		tmp->next = new;
		new->previous = tmp;
		tmp = tmp->next;
	}
	tmp = first;
	while (tmp != NULL)
	{
		printf("%s\n", basename(tmp->name));
		tmp = tmp->next;
	}
	return (first);
}
