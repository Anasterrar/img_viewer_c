#ifndef SURFACE_H
#define SURFACE_H
// STRUCT
typedef struct s_surface
{
	uint32_t		*framebuffer;
	int				width;
	int				height;
	int				size;
	bool			mask;
	uint32_t		mask_color;
}	t_surface;

// GLOBALE VARIABLE
#define TOP_LEFT 1
#define TOP_MIDDLE 2
#define TOP_RIGHT 3
#define MIDDLE_LEFT 4
#define MIDDLE_CENTERED 5
#define MIDDLE_RIGHT 6
#define BOTTOM_LEFT 7
#define BOTTOM_MIDDLE 8
#define BOTTOM_RIGHT 9

// FUNCTION
t_surface       *create_surface(int width, int height);
void    	    blit(t_surface *surface_under, t_surface *surface_over, int pos_x, int pos_y);
void    	    fill(t_surface *surface, uint32_t color);

//destroy
//free all
#endif