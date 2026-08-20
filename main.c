#include "visual.h"
//Errors
//free_all
//Afficher le header dans le terminal de facon stylisé, ascii art
//Zoom
//BONUS (JPG, JPEG, WEBP);

t_visual	*app;

int main(int argc, char **argv)
{
	t_img_data	*first;
	t_img_data	*tmp;
	bool		running;
	app = malloc(sizeof(t_visual));
	SDL_Event event;	
	app->windowWidth = WIDTH_DEFAULT;
	app->windowHeight = HEIGHT_DEFAULT;
	first = load_all_img(argc, argv);
	if (first == NULL)
		return (1);
	app->framebuffer = malloc((size_t)(app->windowWidth) * app->windowHeight * sizeof(uint32_t));
	if (!(app->framebuffer))
    		return (1);
	fill_frame_buff(first);
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
	tmp = first;
	running = true;
	while (running)
	{
		while (SDL_PollEvent(&event))
                {
                        if (event.type == SDL_EVENT_QUIT)
                                running = false;
			if (event.type == SDL_EVENT_KEY_DOWN)
			{
				if (event.key.key == SDLK_ESCAPE)
					running = false;
				if (tmp->previous != NULL && event.key.key == SDLK_LEFT)
				{
					
					tmp = tmp->previous;
					fill_frame_buff(tmp);
				}
				if (tmp->next != NULL && event.key.key == SDLK_RIGHT)
				{
					tmp = tmp->next;
					fill_frame_buff(tmp);
				}
			}
                }
		SDL_GetWindowSizeInPixels(app->window, &(app->windowWidth), &(app->windowHeight));
		//printf("Width: %d; Height: %d\n", app->windowWidth, app->windowHeight);
		SDL_UpdateTexture(
			app->texture,
			NULL, 
			app->framebuffer,
			app->windowWidth * sizeof(uint32_t)
		);

		SDL_RenderClear(app->renderer);
		SDL_RenderTexture(app->renderer, app->texture, NULL, NULL);
		SDL_RenderPresent(app->renderer);
		//SDL_Delay(1000);
	}
	SDL_DestroyTexture(app->texture);
	SDL_DestroyRenderer(app->renderer);
	SDL_DestroyWindow(app->window);
	SDL_Quit();
	//free(first);
	return (0);
}
