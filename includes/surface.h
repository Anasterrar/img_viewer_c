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

#define HORIZONTAL 0
#define VERTICAL 1
#define BOTH 2

#define LEFT 0
#define BOTTOM 1
// FUNCTION
void        put_pixel(t_surface *surface, int pos_x, int pos_y, uint32_t color);
uint32_t    get_pixel(t_surface *surf, int pos_x, int pos_y);
//free all
typedef struct s_surface_api
{
    t_surface *(*create)(int width, int height);
    t_surface *(*copy)(t_surface *surface);
    void       (*resize)(t_surface *surface, int width, int height);
    void       (*destroy)(t_surface *surface);
    t_surface *(*fusion)(t_surface *surface1, t_surface *surface2, int way);
    t_surface *(*split)(t_surface *surface, int split_x_y, int way);
    void       (*move)(t_surface *surface, int add_pos_x, int add_pos_y);
    void       (*put_mask)(t_surface *surface, uint32_t color);
    void       (*remove_mask)(t_surface *surface);
    void       (*blit)(t_surface *surface_under,
                       t_surface *surface_over,
                       int pos_x,
                       int pos_y);
    void       (*clear)(t_surface *surface);
    void       (*fill)(t_surface *surface, uint32_t color);
    uint32_t   (*get_pixel)(t_surface *surface, int pos_x, int pos_y);
    void       (*put_pixel)(t_surface *surface, int pos_x, int pos_y,
                            uint32_t color);
    int        (*get_size)(t_surface *surface);
    int        (*get_width)(t_surface *surface);
    int        (*get_height)(t_surface *surface);
	t_point    (*get_pos)(t_surface *surface, int mod, int part);
    void       (*flip)(t_surface *surface, int way);
    bool       (*colide)(t_surface *surface1, t_surface *surface2);
    void       (*print_data)(t_surface *surface);

} t_surface_api;
#endif