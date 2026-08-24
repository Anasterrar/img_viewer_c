#include "visual.h"

extern t_visual *app;

void	visual_destroy()
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