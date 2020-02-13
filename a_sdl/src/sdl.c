/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 06:27:08 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/13 23:35:04 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler_v.h"

void quit(SDL_Window *win, SDL_Surface *scr, SDL_Surface *img_1)
{
    SDL_FreeSurface(img_1);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

int		init_v(SDL_Window *win, SDL_Surface *scr)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return 1;
	win = SDL_CreateWindow("CS: 1.6 2D",
							  SDL_WINDOWPOS_UNDEFINED,
							  SDL_WINDOWPOS_UNDEFINED,
							  640, 640,
							  SDL_WINDOW_SHOWN);
	scr = SDL_GetWindowSurface(win);
	return (0);
	
}

int load(SDL_Surface *img_1) {
    img_1 = SDL_LoadBMP("src/preview.bmp");
    if (img_1 == NULL) {
        return 1;
    }
    return 0;
}

int		main_v()
{
	SDL_Window *win = NULL;
	SDL_Surface *scr = NULL;
	SDL_Surface *img_1 = NULL;
	
	if (init_v(win, scr) == 1) {
        return 1;
    }
    if (load(img_1) == 1) {
        return 1;
	}
	// int run = TRUE;
	// SDL_Event e;
    SDL_Rect r;

    int x = 100;
    int y = 100;

    r.x = x;
    r.y = y;

	// 	write(1, "aaaa\n", 5);
	// SDL_FillRect(scr, NULL, SDL_MapRGB(scr->format, 255, 255, 255));
	// SDL_BlitSurface(img_1, NULL, scr, NULL);
	// SDL_UpdateWindowSurface(win);
	// while (run)
	// {
	// 	write(1, "aaaa\n", 5);
	// 	while (SDL_PollEvent(&e))
	// 	{
	// 		if (e.type == SDL_QUIT)
	// 		{
	// 			run = FALSE;
    //         }

    //         if (e.type == SDL_KEYDOWN) {
    //             if (e.key.keysym.sym == SDLK_UP) {
    //                 y -= 1;
    //             }
    //             if (e.key.keysym.sym == SDLK_DOWN) {
    //                 y += 1;
    //             }
    //             if (e.key.keysym.sym == SDLK_RIGHT) {
    //                 x += 1;
    //             }
    //             if (e.key.keysym.sym == SDLK_LEFT) {
    //                 x -= 1;
    //             }
    //         }
    //     }
    //     r.x = x;
    //     r.y = y;

    //     SDL_FillRect(scr, NULL, SDL_MapRGB(scr -> format, 255, 255, 255));

    //     SDL_BlitSurface(img_1, NULL, scr, &r);

    //     SDL_UpdateWindowSurface(win);
    // }
    // SDL_BlitSurface(img_1, NULL, scr, NULL);
    // SDL_UpdateWindowSurface(win);

    // SDL_Delay(200000);

	SDL_FillRect(scr, NULL, SDL_MapRGB(scr->format, 0, 0, 0));
	SDL_BlitSurface(img_1, NULL, scr, &r);
	SDL_UpdateWindowSurface(win);
	int close = 0;
	while (!close)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type)
			{
				if (event.type == SDL_QUIT)
					close = 1;
				break;
			}
		}
		SDL_Delay(1000 / 60);
	}




    // quit(win, scr, img_1);
    return 0;
}