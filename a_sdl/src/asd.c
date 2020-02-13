/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 06:27:08 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/14 00:05:56 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler_v.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int init(SDL_Window **win, SDL_Surface **scr) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

	int flags = IMG_INIT_PNG;
    if ( !( IMG_Init( flags ) & flags ) ) {
        return 1;
    }
	
    *win = SDL_CreateWindow("События", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (*win == NULL) {
        return 1;
    }

    *scr = SDL_GetWindowSurface(*win);

    return 0;
}

int load(SDL_Surface **john, SDL_Surface **scr) {
    *john = IMG_Load("cat.png");
    if (*john == NULL) {
        return 1;
    }
	*john = SDL_ConvertSurface(*john, (*scr)->format, NULL);
    if (*john == NULL) {
        return 1;
    }
    return 0;
}

int quit(SDL_Window **win, SDL_Surface **scr, SDL_Surface **john) {
	SDL_FreeSurface(*john);
    
    SDL_FreeSurface(*scr);
    SDL_DestroyWindow(*win);

    SDL_Quit();
    IMG_Quit();
    return 0;
}
int main_v (int argc, char ** args) {
	SDL_Window *win = NULL;
	SDL_Surface *scr = NULL;
	SDL_Surface *john = NULL;

	if (init(&win, &scr) == 1)
	{
		return 1;
	}

	if (load(&john, &scr) == 1)
	{
		return 1;
	}
	SDL_Rect bg_cat;
    bg_cat.w = SCREEN_WIDTH;
    bg_cat.h = SCREEN_HEIGHT;
    bg_cat.x = 0;
    bg_cat.y = 0;
	
	SDL_BlitScaled(john, NULL, scr, &bg_cat);

    SDL_UpdateWindowSurface(win);

    SDL_Delay(2000);

    int	run = TRUE;
    SDL_Event e;
    SDL_Rect r;

    int x = 0;
    int y = 0;

    r.x = x;
    r.y = y;

    while (run) {
        while(SDL_PollEvent(&e) != NULL) {
            if (e.type == SDL_QUIT) {
                run = FALSE;
            }

            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_UP) {
                    y -= 1;
                }
                if (e.key.keysym.sym == SDLK_DOWN) {
                    y += 1;
                }
                if (e.key.keysym.sym == SDLK_RIGHT) {
                    x += 6;
                }
                if (e.key.keysym.sym == SDLK_LEFT) {
                    x -= 6;
                }
            }
        }
        r.x = x;
        r.y = y;

        SDL_FillRect(scr, NULL, SDL_MapRGB(scr -> format, 255, 255, 255));

        SDL_BlitSurface(john, NULL, scr, &r);

        SDL_UpdateWindowSurface(win);
    }

    return quit(&win, &scr, &john);
}