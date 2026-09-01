#include "visual.h"

//free surface
//Ajouter option CENTERED, Top/bottom left/right à blit
//Zoom
//BONUS (JPG, JPEG, WEBP);

t_visual	*app;


int main(int argc, char **argv)
{
	t_img_data	*first;
	t_img_data	*tmp;
	SDL_Event 	event;
	bool		running;
	if (error_input_img(argc, argv))
		return (1);	
	if (!visual_init())
		goto quit;
	first = load_all_img(argc, argv);
	if (first == NULL)
		goto quit;
	tmp = first;
	geometry.draw_polygon(tmp->loaded_img, 3, (int [][2]){{300, 0},{100, 200},{400, 300}});
	running = true;
	while (running)
	{
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
					print_header_img(tmp);
				}
				if (tmp->next != NULL && event.key.key == SDLK_RIGHT)
				{
					tmp = tmp->next;
					print_header_img(tmp);
				}
			}
        }
		surface.fill(app->screen, BACKGROUND_COLOR);
		surface.blit(app->screen, tmp->loaded_img, 10, 10);
		SDL_UpdateTexture(
			app->texture,
			NULL, 
			app->screen->framebuffer,
			app->windowWidth * sizeof(uint32_t)
		);

		SDL_RenderClear(app->renderer);
		SDL_RenderTexture(app->renderer, app->texture, NULL, NULL);
		SDL_RenderPresent(app->renderer);

	}
	quit:
		visual_destroy();
		free_all_img(&first);
		return (1);
}
