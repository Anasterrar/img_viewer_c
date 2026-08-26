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
	int		pos_x;
	int		pos_y;
	t_surface	*square;
	t_surface	*rectangle;
	pos_x = 0;
	pos_y = 0;
	
	if (error_input_img(argc, argv))
		return (1);	
	if (!visual_init())
		goto quit;
	first = load_all_img(argc, argv);
	if (first == NULL)
		goto quit;
	tmp = first;
	running = true;
	print_header_img(first);
	square = create_square(100);
	rectangle = create_rect(100, 50);
	fill(square, 0xf5427b);
	fill(rectangle, 0x8df542);
	//draw_outlines(poly, 4, RED);
	//put_pixel(poly, poly->width / 2, poly->height / 2, RED);
	
	//fill(poly, RED);
	//t_surface	*outlines = create_outlines(tmp->loaded_img, 10, RED, IN);
	pos_x = 10;
	pos_y = 10;
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
				if (event.key.key == SDLK_Q)
					pos_x -= 2;
				if (event.key.key == SDLK_D)
					pos_x += 2;
				if (event.key.key == SDLK_Z)
					pos_y -= 2;
				if (event.key.key == SDLK_S)
					pos_y += 2;
			}
        }
		fill(app->screen, BACKGROUND_COLOR);
        //blit(app->screen, tmp->loaded_img, pos_x, pos_y);
        //blit(app->screen, square, 1080 / 3, 720 / 3);
        blit(app->screen, rectangle, 1080 - 200, 50);
		draw_rect(tmp->loaded_img, 200, 50, 0, 0, BLACK);
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
		visual_destroy();
		free_all_img(&first);
		return (1);
}
