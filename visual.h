#ifndef VISUAL_H
#define VISUAL_H
//INCLUDES
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>

//STRUCT

typedef struct s_surface
{
	uint32_t		*framebuffer;
	int			width;
	int			height;
	int			size;
}	t_surface;

typedef struct s_img_data {
	char			*name;
	char			*type;
	char			*comment;
	int			width;
	int			height;
	int			max_value;
	int			pixels_start;
	int			size;
	char			*pixels_buff;
	t_surface		*loaded_img;
	struct s_img_data	*previous;
	struct s_img_data	*next;
}	t_img_data;

typedef struct s_visual
{
	int			windowWidth;
	int			windowHeight;
	t_surface		*screen;
	SDL_Window 		*window;
	SDL_Renderer 		*renderer;
	SDL_Texture 		*texture;
}	t_visual;

//GLOBAL VARIABLE
#define WIDTH_DEFAULT 1080
#define	HEIGHT_DEFAULT 720
#define	HEADER_BUFF_SIZE 1000
#define BACKGROUND_COLOR 0x181c70
#define ERROR_ARGUMENT_MISSING "Error: no argument provided\n"
//FUNCTIONS
//A ranger

t_surface       *create_surface(int width, int height);
t_img_data      *create_img_data(char *fileName);
t_img_data      *load_all_img(int argc, char **argv);
t_img_data	*load_img(char *fileName);
uint32_t        pixel(int *index, char **pixels_buff);
int     	ft_strlen(char *str);
int     	ft_dump(char **data, char *str);
void    	create_frame(t_img_data **img_data);
void		print_header(t_img_data *img_data);
void		free_all(t_img_data **img_data);
void    	ft_blit(t_surface **surface, t_surface *image, int pos_x, int pos_y);
void    	ft_fill(t_surface **surface, uint32_t color);
int     	error_input(int argc, char **argv);
int		min(int n1, int n2);
int		max(int n1, int n2);
#endif
