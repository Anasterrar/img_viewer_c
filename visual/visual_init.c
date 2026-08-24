#include "visual.h"

extern t_visual *app;

int	visual_init()
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
		visual_destroy();
		return (0);
}