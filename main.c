#include "visual.h"


char    buff[BUFF_SIZE];

void	setWH(int *width, int *height)
{
	char	w[5];
	char	h[5];
	int	i;
	int	y;

	i = 0;
	y = 0;
	//Format P6 P3 etc
	while (buff[i] != '\n')
		i++;
	i++;
	//Comment
	if(buff[i] < '0' || buff[i] > '9')
	{
		while(buff[i] != '\n')
			i++;
	}
	//WIDTH
	while (buff[i] != ' ')
	{
		w[y] = buff[i];
		i++;
		y++;
	}
	w[y] = '\0';
	y = 0;
	//HEIGHT
	while (buff[i] != '\n')
        {
                  h[y] = buff[i];
                  i++;
		 y++;
        }
	h[y] = '\0';
	*width = atoi(w);
	*height = atoi(h);
}

uint32_t pixel(int *index)
{
        uint8_t r;
        uint8_t g;
        uint8_t b;

        r = (unsigned char)buff[(*index)++];
        g = (unsigned char)buff[(*index)++];
        b = (unsigned char)buff[(*index)++];

        return ((uint32_t)r << 16)
             | ((uint32_t)g << 8)
             | b;
}

void    loadImg(char *file_name)
{
        int     fd;
        ssize_t numRead;

        fd = open(file_name, O_RDONLY);
        if (fd == -1)
                return ;
        numRead = read(fd, buff, BUFF_SIZE);
        close(fd);
}

int main(int argc, char **argv)
{
	int	width;
	int	height;
	bool	running;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	SDL_Event event;
	loadImg(argv[1]);
	setWH(&width, &height);
	int	i = 0;
	uint32_t        framebuffer[width * height];
	int	indexbuff = 15;
	for (int i = 0; i < height * width; i++)
		framebuffer[i] = pixel(&indexbuff);
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(
		"SDL Teste", 
		width, 
		height, 
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
		width,
		height
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
			width * sizeof(uint32_t)
		);

		SDL_RenderClear(renderer);
		SDL_RenderTexture(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);

}
