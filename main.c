#include "visual.h"
//REFACTOR
/*--------Variable Global
----------Deuxieme fichier
-Petit_buff pour le header
-prendre les infos du header
-Construire le deuxiemes buff avec les info du header
-Construre framebuff avec les infos du buff
*/
//OPTIMISATION
//BONUS (ERRORS, JPG, JPEG, WEBP, BUTTON TO CHANGE IMAGE);

t_visual	*app;
t_img_data	*img_data;
char	*pixels_buff;

int main(int argc, char **argv)
{
	(void)argc;
	bool	running;
	app = malloc(sizeof(t_visual));
	SDL_Event event;	
	app->windowWidth = 1080;
	app->windowHeight = 720;
	img_data = malloc(sizeof(t_img_data));
	if (load_img(argv[1]) == 0)
		return (1);
	app->framebuffer = malloc((size_t)(app->windowWidth) * app->windowHeight * sizeof(uint32_t));
	if (!(app->framebuffer))
    		return (1);
	fill_frame_buff(&img_data);
	free(pixels_buff);
	SDL_Init(SDL_INIT_VIDEO);
	app->window = SDL_CreateWindow(
		argv[1], 
		app->windowWidth, 
		app->windowHeight, 
		0
	);
	app->renderer = SDL_CreateRenderer(
		app->window,
		NULL
	);
	app->texture = SDL_CreateTexture(
		app->renderer,
		SDL_PIXELFORMAT_XRGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		app->windowWidth,
		app->windowHeight 
	);
	running = true;
	while (running)
	{
		while (SDL_PollEvent(&event))
                {
                        if (event.type == SDL_EVENT_QUIT)
                                running = false;
                }
		SDL_GetWindowSizeInPixels(app->window, &(app->windowWidth), &(app->windowHeight));
		printf("Width: %d; Height: %d\n", app->windowWidth, app->windowHeight);
		SDL_UpdateTexture(
			app->texture,
			NULL, 
			app->framebuffer,
			app->windowWidth * sizeof(uint32_t)
		);

		SDL_RenderClear(app->renderer);
		SDL_RenderTexture(app->renderer, app->texture, NULL, NULL);
		SDL_RenderPresent(app->renderer);
		SDL_Delay(1000);
	}
	SDL_DestroyTexture(app->texture);
	SDL_DestroyRenderer(app->renderer);
	SDL_DestroyWindow(app->window);
	SDL_Quit();
	free(img_data);
	return (0);
}
