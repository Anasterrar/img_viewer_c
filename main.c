#include "visual.h"
//REFACTOR
/*
-Petit_buff pour le header
-prendre les infos du header
-Construire le deuxiemes buff avec les info du header
-Construre framebuff avec les infos du buff
*/
//OPTIMISATION
//BONUS (ERRORS, JPG, JPEG, WEBP, BUTTON TO CHANGE IMAGE);

char	*pixel_buff;

uint32_t pixel(int *index)
{
        uint8_t r;
        uint8_t g;
        uint8_t b;

        r = (unsigned char)pixel_buff[(*index)++];
        g = (unsigned char)pixel_buff[(*index)++];
        b = (unsigned char)pixel_buff[(*index)++];

        return ((uint32_t)r << 16)
             | ((uint32_t)g << 8)
             | b;
}

int main(int argc, char **argv)
{
	(void)argc;
	int	header_index;
	bool	running;
	t_img_data      *img_data;
	uint32_t        *framebuffer;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	SDL_Event event;

	img_data = malloc(sizeof(t_img_data));
	header_index = load_img(argv[1], &img_data);
	framebuffer = malloc((size_t)(img_data)->width * (img_data)->height * sizeof(uint32_t));
	if (!framebuffer)
    		return (1);
	for (int i = 0; i < (img_data)->width  * (img_data)->height; i++)
		framebuffer[i] = pixel(&header_index);
	free(pixel_buff);
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(
		argv[1], 
		(img_data)->width, 
		(img_data)->height, 
		0
	);
	renderer = SDL_CreateRenderer(
		window,
		NULL
	);
	texture = SDL_CreateTexture(
		renderer,
		SDL_PIXELFORMAT_XRGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		(img_data)->width,
		(img_data)->height 
	);
	running = true;
	while (running)
	{
		while (SDL_PollEvent(&event))
                {
                        if (event.type == SDL_EVENT_QUIT)
                                running = false;
                }
		SDL_UpdateTexture(
			texture,
			NULL, 
			framebuffer,
			(img_data)->width  * sizeof(uint32_t)
		);

		SDL_RenderClear(renderer);
		SDL_RenderTexture(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	free(img_data);
	return (0);

}
