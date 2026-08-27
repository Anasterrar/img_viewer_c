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
	t_surface	*outlines;
	bool 		is_outlines = false;

	SDL_Event 	event;
	bool		running;
	int		pos_x;
	int		pos_y;
	pos_x = 10;
	pos_y = 10;
	
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
	outlines = create_outlines(tmp->loaded_img, 10, 0x630da8, IN);
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
				if (event.key.key == SDLK_H)
				{
					is_outlines = is_outlines ? false : true ;
				}
				if (event.key.key == SDLK_O)
				{
					draw_outlines(tmp->loaded_img, 4, RED);
				}
					
			}
        }
		/*
		print_point(get_surface_pos(tmp->loaded_img, GLOBAL, TOP_LEFT));
		printf("SIZE:%d\n", get_surface_size(tmp->loaded_img));
		printf("WIDTH:%d\n", get_surface_width(tmp->loaded_img));
		printf("HEIGHT:%d\n", get_surface_height(tmp->loaded_img));
		*/
		fill(app->screen, BACKGROUND_COLOR);
		blit(app->screen, tmp->loaded_img, 10, 10);
		blit(app->screen, outlines, pos_x, pos_y);
    
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
