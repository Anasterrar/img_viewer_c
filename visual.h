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
typedef struct img_data {
	char	type[5];
	int	width;
	int	height;
	int	max_value;
}	t_img_data;
//GLOBAL VARIABLE
#define	HEADER_BUFF_SIZE 1000

//FUNCTIONS
//void    setWH(int *width, int *height);
uint32_t pixel(int *index);
//void    loadImg(char *file_name);
int   load_img(char *fileName, t_img_data **img_data);
#endif
