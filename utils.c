#include "visual.h"
#define RESET   "\033[0m"
#define BLUE    "\033[38;5;39m"
#define BOLD    "\033[1m"
#define CYAN    "\033[38;5;51m"

extern t_visual *app;

int	min(int n1, int n2)
{
	return (n1 <= n2 ? n1 : n2);
}

int	max(int n1, int n2)
{
	return (n1 >= n2 ? n1 : n2);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_surface	*create_surface(int width, int height)
{
	t_surface	*new;
	
	new = malloc(sizeof(t_surface));
	if (!new)
		return (NULL);
	new->framebuffer = malloc((size_t)(width) * height * sizeof(uint32_t));
	new->width = width;
	new->height = height;
	new->size = width * height;
	return (new);
}

t_img_data	*create_img_data(char *fileName)
{
	t_img_data	*new;
	
	new = malloc(sizeof(t_img_data));
	if (!new)
		return (NULL);
	ft_dump(&(new->name), fileName);
	new->previous = NULL;
	new->next = NULL;	
	return (new);	
}

int	ft_dump(char **data, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str) + 1;
	(*data)= malloc(len);
	if (!(*data))
		return (0);
	while (i < len)
	{
		(*data)[i] = str[i];
		i++;
	}
	return (1);		
}

void	free_all(t_img_data **img_data)
{	
	t_img_data	*tmp;
	
	while (*img_data != NULL)
	{
		tmp = (*img_data)->next;
		free((*img_data)->name);
		free((*img_data)->type);
		free((*img_data)->comment);
		free((*img_data)->pixels_buff);
		free((*img_data)->loaded_img->framebuffer);
		free((*img_data)->loaded_img);
		free(*img_data);
		(*img_data) = tmp;
	}
}

void    print_header(t_img_data *img_data)
{
	system("clear");
	printf("\n");
        printf(BLUE "╔══════════════════════════════════════════════╗" RESET "\n");
        printf(BLUE "║" RESET "                                              " BLUE "║" RESET "\n");
        printf(BLUE "║" RESET "              " BOLD CYAN "✦  IMAGE VIEWER  ✦" RESET
                "             " BLUE " ║" RESET "\n\n");	
	printf("  Name: %s\n", img_data->name);
        printf("  Type: %s\n", img_data->type);
        if (ft_strlen(img_data->comment) > 0)
                printf("  Comment:\n   %s", img_data->comment);
        printf("  Width: %d\n", img_data->width);
        printf("  Height: %d\n", img_data->height);
        printf("  Max-Value: %d\n", img_data->max_value);
	
        printf(BLUE "║" RESET "                                              " BLUE "║" RESET "\n");
        printf(BLUE "╚══════════════════════════════════════════════╝" RESET "\n");
        printf("\n");
}

uint32_t pixel(int *index, char **pixels_buff)
{
        uint8_t r;
        uint8_t g;
        uint8_t b;

        r = (unsigned char)(*pixels_buff)[(*index)++];
        g = (unsigned char)(*pixels_buff)[(*index)++];
        b = (unsigned char)(*pixels_buff)[(*index)++];

        return ((uint32_t)r << 16)
             | ((uint32_t)g << 8)
             | b;
}

void    create_frame(t_img_data **img_data)
{
        int     i;
	int	pixel_index;

        i = 0;
	pixel_index = (*img_data)->pixels_start;
        for (; i < (*img_data)->width * (*img_data)->height; i++)
		((*img_data)->loaded_img->framebuffer)[i] = pixel(&pixel_index, &((*img_data)->pixels_buff));
}

void    ft_fill(t_surface **surface, uint32_t color)
{
	int	i;

	i = 0;
	for (; i < (*surface)->size; i++)
		((*surface)->framebuffer)[i] = color;
}

void	ft_blit(t_surface **surface, t_surface *image, int pos_x, int pos_y)
{
	int	x;
	int	y;
	int	dst_x;
	int	dst_y;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			dst_x = x + pos_x;
			dst_y = y + pos_y;
			if (dst_x >= 0 && dst_x < (*surface)->width
				&& dst_y >= 0 && dst_y < (*surface)->height)
			{
				(*surface)->framebuffer[
					dst_y * (*surface)->width + dst_x
				] = image->framebuffer[
					y * image->width + x
				];
			}
			x++;
		}
		y++;
	}
}

