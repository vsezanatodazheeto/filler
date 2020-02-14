#include "../include/filler_v.h"

int init(SDL_Window **win, SDL_Surface **scr)
{
	int flags;

    flags = IMG_INIT_PNG;
    if (!(IMG_Init(flags) & flags))
        return 1;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        return 1;
    if (!(*win = SDL_CreateWindow("",
							SDL_WINDOWPOS_UNDEFINED,
							SDL_WINDOWPOS_UNDEFINED,
							680, 680,
							SDL_WINDOW_FULLSCREEN_DESKTOP)))
		return (1);
    *scr = SDL_GetWindowSurface(*win);
    return 0;
}

int load(SDL_Surface **john, SDL_Surface **bg, SDL_Surface **scr)
{
    if(!(*john = IMG_Load("resources/cat.png")))
        return 1;
    if(!(*bg = IMG_Load("resources/bg_3.jpg")))
        return 1;
	if(!(*john = SDL_ConvertSurface(*bg, (*scr)->format, NULL)))
        return 1;
    return 0;
}

int quit(SDL_Window **win, SDL_Surface **scr, SDL_Surface **john)
{
	SDL_FreeSurface(*john);
    SDL_FreeSurface(*scr);
    SDL_DestroyWindow(*win);
    SDL_Quit();
    IMG_Quit();
    return 0;
}