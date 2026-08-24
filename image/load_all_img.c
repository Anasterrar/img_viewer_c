#include "visual.h"

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
	create_frame(&img_data);
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
