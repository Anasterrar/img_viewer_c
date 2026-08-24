#ifndef VISUAL_H
#define VISUAL_H
//INCLUDES
#include <math.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
//HEADER
#include "surface.h"
#include "image.h"
#include "math.h"
#include "geometry.h"
#include "utils.h"
#include "errors.h"
//GLOBAL VARIABLE
#define WIDTH_DEFAULT 1080
#define	HEIGHT_DEFAULT 720

typedef struct s_visual
{
	int					windowWidth;
	int					windowHeight;
	t_surface			*screen;
	SDL_Window 			*window;
	SDL_Renderer 		*renderer;
	SDL_Texture 		*texture;
}	t_visual;

#define BACKGROUND_COLOR 0x181c70
#define	TRANSPARENT	 0x00FFFFFF
int		visual_init();
void	visual_destroy();

#endif
