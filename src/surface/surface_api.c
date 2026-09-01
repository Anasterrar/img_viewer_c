#include "visual.h"

t_surface       *create_surface(int width, int height);
t_surface   	*copy_surface(t_surface *surf);
t_surface   	*fusion_surface(t_surface *surf1, t_surface *surf2, int way);
t_surface   	*split(t_surface *surf, int split_x_y, int way);
void			resize_surface(t_surface *surf, int width, int height);
void   			crop_surface(t_surface *surf, t_point p1, t_point p2);
void			destroy_surface(t_surface *surf);
void    		move_surface(t_surface *surf, int add_pos_x, int add_pos_y);
void    		put_mask(t_surface *surf, uint32_t color);
void    		change_mask(t_surface *surf, uint32_t color);
void    		remove_mask(t_surface *surf);
void    	    blit(t_surface *surf_under, t_surface *surf_over, int pos_x, int pos_y);
void    		clear(t_surface *surf);
void    	    fill(t_surface *surf, uint32_t color);
uint32_t		get_pixel(t_surface *surf, int pos_x, int pos_y);
void			put_pixel(t_surface *surf, int pos_x, int pos_y, uint32_t color);
int     		get_surface_size(t_surface *surf);
int     		get_surface_width(t_surface *surf);
int     		get_surface_height(t_surface *surf);
void			flip(t_surface *surf, int way);
void   	 		print_surface_data(t_surface *surf);
t_point     	get_surface_pos(t_surface *surf, int mod, int part);
void			blit_with_mask(t_surface *surf_under, t_surface *surf_over, int pos_x, int pos_y);
void    		blit_mask(t_surface *surf_under, t_surface *surf_over, int pos_x, int pos_y);
bool    		colide_surface(t_surface *surf1, t_surface *surf2);

t_surface_api surface =
{
    .create = create_surface,
    .copy = copy_surface,
    .resize = resize_surface,
    .destroy = destroy_surface,

    .fusion = fusion_surface,
    .split = split,

    .move = move_surface,

    .put_mask = put_mask,
    .remove_mask = remove_mask,

    .blit = blit,

    .clear = clear,
    .fill = fill,

    .get_pixel = get_pixel,
    .put_pixel = put_pixel,

    .get_size = get_surface_size,
    .get_width = get_surface_width,
    .get_height = get_surface_height,
    .get_pos = get_surface_pos,
    .flip = flip,

    .colide = colide_surface,

    .print_data = print_surface_data
};