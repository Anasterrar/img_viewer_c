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
	t_surface	*triangle;
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
	fill(&square, 0xf5427b);
	fill(&rectangle, 0x8df542);
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
				if (event.key.key == SDLK_Z)
					pos_y = max(0, pos_y - 10);
				if (event.key.key == SDLK_Q)
					pos_x = max(0, pos_x - 10);
				if (event.key.key == SDLK_S)
					pos_y = min(app->windowHeight - tmp->height, pos_y + 10);
				if (event.key.key == SDLK_D)
					pos_x = min(app->windowWidth - tmp->width, pos_x + 10);
				
				/*
				if (event.key.key == SDLK_I)
                                        t_pos_y = max(0, t_pos_y - 10);
                                if (event.key.key == SDLK_J)
                                        t_pos_x = max(0, t_pos_x - 10);
                                if (event.key.key == SDLK_L)
                                        t_pos_y = min(tmp->loaded_img->height - 30, t_pos_y + 10);
                                if (event.key.key == SDLK_K)
                                        t_pos_x = min(tmp->loaded_img->width - 99, t_pos_x + 10);
				*/
			}
                }
		
			fill(&(app->screen), BACKGROUND_COLOR);
        	blit(&(app->screen), tmp->loaded_img, pos_x, pos_y);
            //blit(&(app->screen), square, 1080 / 3, 720 / 3);
            blit(&(app->screen), rectangle, 1080 - 200, 50);

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
