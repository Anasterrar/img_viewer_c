#include "visual.h"
//free surface
//Ajouter option CENTERED, Top/bottom left/right à blit
//Zoom
//BLITE et BLITE_TRANSFORME_SCALE
//BONUS (JPG, JPEG, WEBP);

t_visual	*app;

void	app_destroy()
{
	if (app->screen)
	{
		free(app->screen->framebuffer);
		free(app->screen);
	}
	if (app->window)
		SDL_DestroyWindow(app->window);
	if (app->texture)
		SDL_DestroyTexture(app->texture);
	if (app->renderer)
        	SDL_DestroyRenderer(app->renderer);
        SDL_Quit();
	free(app);
        app = NULL;
}

int	app_init()
{
	app = malloc(sizeof(t_visual));
	if (!app)
		goto error;
	app->window = NULL;
	app->renderer = NULL;
	app->texture = NULL;
	if (!SDL_Init(SDL_INIT_VIDEO))
		goto error;
	app->windowWidth = WIDTH_DEFAULT;
	app->windowHeight = HEIGHT_DEFAULT;
	app->window = SDL_CreateWindow(
                "Image Visual",
                app->windowWidth,
                app->windowHeight,
                SDL_WINDOW_RESIZABLE
        );
	if (!app->window)
		goto error;
        app->renderer = SDL_CreateRenderer(
                app->window,
                NULL
        );
	if (!app->renderer)
		goto error;
        app->texture = SDL_CreateTexture(
                app->renderer,
                SDL_PIXELFORMAT_XRGB8888,
                SDL_TEXTUREACCESS_STREAMING,
                app->windowWidth,
                app->windowHeight
        );
	if (!app->texture)
		goto error;
	app->screen = create_surface(app->windowWidth, app->windowHeight);
        if (!(app->screen))
                goto error;
	return (1);
	error:
		app_destroy();
		return (0);
}

int main(int argc, char **argv)
{
	t_img_data	*first;
	t_img_data	*tmp;
	SDL_Event 	event;
	bool		running;
	int		pos_x;
	int		pos_y;

	pos_x = 0;
	pos_y = 0;
	
	if (error_input(argc, argv))
		return (1);	
	if (!app_init())
		goto quit;
	first = load_all_img(argc, argv);
	if (first == NULL)
		goto quit;
	tmp = first;
	running = true;
	print_header(first);
		
	while (running)
	{
		ft_fill(&(app->screen), BACKGROUND_COLOR);
		ft_blit(&(app->screen), tmp->loaded_img, pos_x, pos_y);
		while (SDL_PollEvent(&event))
                {
                        if (event.type == SDL_EVENT_QUIT)
			{
                                running = false;
				goto quit;
			}
				
			if (event.type == SDL_EVENT_KEY_DOWN)
			{
				if (event.key.key == SDLK_ESCAPE)
				{
					running = false;
					goto quit;
				}
				if (tmp->previous != NULL && event.key.key == SDLK_LEFT)
				{
					
					tmp = tmp->previous;
					ft_fill(&(app->screen), BACKGROUND_COLOR);
                  			ft_blit(&(app->screen), tmp->loaded_img, pos_x, pos_y);
					print_header(tmp);
				}
				if (tmp->next != NULL && event.key.key == SDLK_RIGHT)
				{
					tmp = tmp->next;
					ft_fill(&(app->screen), BACKGROUND_COLOR);
                  			ft_blit(&(app->screen), tmp->loaded_img, pos_x, pos_y);
					print_header(tmp);
				}
				if (event.key.key == SDLK_Z)
					pos_y = max(0, pos_y - 10);
				if (event.key.key == SDLK_Q)
					pos_x = max(0, pos_x - 10);
				if (event.key.key == SDLK_S)
					pos_y = min(app->windowHeight - tmp->height, pos_y + 10);
				if (event.key.key == SDLK_D)
					pos_x = min(app->windowWidth - tmp->width, pos_x + 10);
			}
                }
		SDL_GetWindowSizeInPixels(app->window, &(app->windowWidth), &(app->windowHeight));
		//printf("Width: %d; Height: %d\n", app->windowWidth, app->windowHeight);
		SDL_UpdateTexture(
			app->texture,
			NULL, 
			app->screen->framebuffer,
			app->windowWidth * sizeof(uint32_t)
		);

		SDL_RenderClear(app->renderer);
		SDL_RenderTexture(app->renderer, app->texture, NULL, NULL);
		SDL_RenderPresent(app->renderer);
		//SDL_Delay(1000);
	}
	quit:
		app_destroy();
		free_all(&first);
		return (1);
}
