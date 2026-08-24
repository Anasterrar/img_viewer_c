#include "visual.h"

extern t_visual *app;

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
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

void	put_pixel(t_surface **surface, int pos_x, int pos_y, uint32_t color)
{
	int	pos;

	pos = pos_y * (*surface)->width + pos_x;
	((*surface)->framebuffer)[pos] = color;	
}

uint32_t pixel(int *index, char **pixels_buff)
{
	uint8_t	a;
        uint8_t r;
        uint8_t g;
        uint8_t b;

	a = 255;
        r = (unsigned char)(*pixels_buff)[(*index)++];
        g = (unsigned char)(*pixels_buff)[(*index)++];
        b = (unsigned char)(*pixels_buff)[(*index)++];

        return ((uint32_t)a << 24) 
	     | ((uint32_t)r << 16)
             | ((uint32_t)g << 8)
             | b;
}