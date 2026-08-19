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

//STRUCT
typedef struct s_img_data {
	char	*type;
	char	*comment;
	int	width;
	int	height;
	int	max_value;
	int	pixels_start;
}	t_img_data;

typedef struct s_visual
{
	int	windowWidth;
	int	windowHeight;
	uint32_t *framebuffer;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
}	t_visual;
//GLOBAL VARIABLE
#define	HEADER_BUFF_SIZE 1000
#define BACKGROUND_COLOR 0x181c70
//FUNCTIONS
uint32_t pixel(int *index);
int   load_img(char *fileName);
void    fill_frame_buff(t_img_data **img_data);
void    print_header(t_img_data *img_data);
uint32_t pixel(int *index);
void    free_all(t_img_data **img_data);
#endif
