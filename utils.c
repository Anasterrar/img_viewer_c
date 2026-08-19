#include "visual.h"
extern char * pixels_buff;
extern t_visual	*app;

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_all(t_img_data **img_data)
{
	free((*img_data)->type);
	free((*img_data)->comment);
	free((*img_data));
}

void    print_header(t_img_data *img_data)
{
	printf("---Type---\n%s\n", img_data->type);
	if (ft_strlen(img_data->comment) > 0)
		printf("---Comment---\n%s", img_data->comment);
	printf("---Width---\n%d\n", img_data->width);
	printf("---Height---\n%d\n", img_data->height);
	printf("---Max-Value---\n%d\n", img_data->max_value);
}

uint32_t pixel(int *index)
{
        uint8_t r;
        uint8_t g;
        uint8_t b;

        r = (unsigned char)pixels_buff[(*index)++];
        g = (unsigned char)pixels_buff[(*index)++];
        b = (unsigned char)pixels_buff[(*index)++];

        return ((uint32_t)r << 16)
             | ((uint32_t)g << 8)
             | b;
}

void    fill_frame_buff(t_img_data **img_data)
{
        int     i;
	int	pixel_index;
        int     offset_x;
        int     offset_y;

        i = 0;
	pixel_index = (*img_data)->pixels_start;
        offset_x = (app->windowWidth - (*img_data)->width) / 2;
        offset_y = (app->windowHeight - (*img_data)->height) / 2;
        printf("Offset_x: %d\nOffset_y: %d\n", offset_x, offset_y);
        for (; i < app->windowWidth * offset_y; i++)
                (app->framebuffer)[i] = BACKGROUND_COLOR;
        for (; i < app->windowWidth * ((*img_data)->height + offset_y); i++)
        {
                if (i % app->windowWidth < offset_x
                        ||i % app->windowWidth >= offset_x + (*img_data)->width)
                        (app->framebuffer)[i] = BACKGROUND_COLOR;
                else
                        (app->framebuffer)[i] = pixel(&pixel_index);
        }
        for (; i < app->windowWidth * app->windowHeight; i++)
                (app->framebuffer)[i] = BACKGROUND_COLOR;
}
