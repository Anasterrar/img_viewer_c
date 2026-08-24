#ifndef SURFACE_H
#define SURFACE_H

typedef struct s_surface
{
	uint32_t		*framebuffer;
	int			width;
	int			height;
	int			size;
}	t_surface;

t_surface       *create_surface(int width, int height);
void    	    blit(t_surface **surface_under, t_surface *surface_over, int pos_x, int pos_y);
void    	    fill(t_surface **surface, uint32_t color);
//destroy
//free all
#endif