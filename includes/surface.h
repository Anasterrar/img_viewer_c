#ifndef SURFACE_H
#define SURFACE_H
// STRUCT
typedef struct s_surface
{
	int					width;
	int					height;
	int					size;
	int					pos_x;
	int					pos_y;
	bool				mask;
	struct s_surface 	*parent;
	uint32_t			mask_color;
	uint32_t			*framebuffer;
}	t_surface;

// GLOBALE VARIABLE
#define TOP_LEFT 0
#define TOP_MIDDLE 1
#define TOP_RIGHT 2
#define MIDDLE_LEFT 3
#define MIDDLE_CENTER 4
#define MIDDLE_RIGHT 5
#define BOTTOM_LEFT 6
#define BOTTOM_MIDDLE 7
#define BOTTOM_RIGHT 8

#define	RELATIVE 0
#define GLOBAL 1

// FUNCTION
t_surface       *create_surface(int width, int height);
void			resize_surface(t_surface *surface, int width, int height);
void			destroy_surface(t_surface *surface);
void    		put_mask(t_surface *surface, uint32_t color);
void    		remove_mask(t_surface *surface);
void    	    blit(t_surface *surface_under, t_surface *surface_over, int pos_x, int pos_y);
void    		clear(t_surface *surface);
void    	    fill(t_surface *surface, uint32_t color);
uint32_t		get_pixel(t_surface *surface, int pos_x, int pos_y);
void			put_pixel(t_surface *surface, int pos_x, int pos_y, uint32_t color);
int     		get_surface_size(t_surface *surface);
int     		get_surface_width(t_surface *surface);
int     		get_surface_height(t_surface *surface);

//free all
#endif