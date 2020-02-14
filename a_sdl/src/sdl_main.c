/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:06 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/14 22:48:50 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler_v.h"

int main_v (int argc, char ** args)
{
	SDL_Window *win = NULL;
    SDL_Texture *textur = NULL;
    SDL_Renderer *rend = NULL;
	SDL_Surface *scr = NULL;
	// SDL_Surface *bg = NULL;

	if (init(&win, &rend, &scr) == 1)
		return 1;
	if (load(&textur, &rend) == 1)
		return 1;

    int	run = TRUE;
    SDL_Event e;
    //While application is running
    while (run)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
                run = FALSE;
        }
        //Clear screen
        SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(rend);

        //Top left corner viewport
        SDL_Rect topLeftViewport;
        topLeftViewport.x = 0;
        topLeftViewport.y = 0;
        topLeftViewport.w = SCREEN_WIDTH / 2;
        topLeftViewport.h = SCREEN_HEIGHT / 2;
        SDL_RenderSetViewport(rend, &topLeftViewport);
        //Render texture to screen
        SDL_RenderCopy(rend, textur, NULL, NULL);

        //Top right viewport
        SDL_Rect topRightViewport;
        topRightViewport.x = SCREEN_WIDTH / 2;
        topRightViewport.y = 0;
        topRightViewport.w = SCREEN_WIDTH / 2;
        topRightViewport.h = SCREEN_HEIGHT / 2;
        SDL_RenderSetViewport(rend, &topRightViewport);
        //Render texture to screen
        SDL_RenderCopy(rend, textur, NULL, NULL);

        //Bottom viewport
        SDL_Rect bottomViewport;
        bottomViewport.x = 0;
        bottomViewport.y = SCREEN_HEIGHT / 2;
        bottomViewport.w = SCREEN_WIDTH;
        bottomViewport.h = SCREEN_HEIGHT / 2;
        SDL_RenderSetViewport(rend, &bottomViewport);
        //Render texture to screen
        SDL_RenderCopy(rend, textur, NULL, NULL);
        //Update screen
        SDL_RenderPresent(rend);
    }
    return quit(&win, &rend, &textur);
}








// SDL_Rect r;

// int x = 0;
// int y = 0;

// r.x = x;
// r.y = y;

// while (run) {
//     while(SDL_PollEvent(&e)) {
//         if (e.type == SDL_QUIT) {
//             run = FALSE;
//         }

//         if (e.type == SDL_KEYDOWN) {
//             if (e.key.keysym.sym == SDLK_UP) {
//                 y -= 1;
//             }
//             if (e.key.keysym.sym == SDLK_DOWN) {
//                 y += 1;
//             }
//             if (e.key.keysym.sym == SDLK_RIGHT) {
//                 x += 6;
//             }
//             if (e.key.keysym.sym == SDLK_LEFT) {
//                 x -= 6;
//             }
//         }
//     }
//     r.x = x;
//     r.y = y;

//     SDL_FillRect(scr, NULL, SDL_MapRGB(scr->format, 255, 255, 255));
//     SDL_BlitSurface(bg, NULL, scr, &r);
//     SDL_UpdateWindowSurface(win);
// }











// SDL_Window *win = NULL;
//     SDL_Texture *textur = NULL;
//     SDL_Renderer *rend = NULL;
// 	SDL_Surface *scr = NULL;
// 	// SDL_Surface *bg = NULL;

// 	if (init(&win, &rend, &scr) == 1)
// 		return 1;
// 	if (load(&textur, &rend) == 1)
// 		return 1;

//     int	run = TRUE;
//     SDL_Event e;
//     //While application is running
//     while (run)
//     {
//         //Handle events on queue
//         while (SDL_PollEvent(&e) != 0)
//         {
//             //User requests quit
//             if (e.type == SDL_QUIT)
//                 run = FALSE;
//         }
//         //Clear screen
//         SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
//         SDL_RenderClear(rend);

//         //Top left corner viewport
//         SDL_Rect topLeftViewport;
//         topLeftViewport.x = 0;
//         topLeftViewport.y = 0;
//         topLeftViewport.w = SCREEN_WIDTH / 2;
//         topLeftViewport.h = SCREEN_HEIGHT / 2;
//         SDL_RenderSetViewport(rend, &topLeftViewport);
//         //Render texture to screen
//         SDL_RenderCopy(rend, textur, NULL, NULL);

//         //Top right viewport
//         SDL_Rect topRightViewport;
//         topRightViewport.x = SCREEN_WIDTH / 2;
//         topRightViewport.y = 0;
//         topRightViewport.w = SCREEN_WIDTH / 2;
//         topRightViewport.h = SCREEN_HEIGHT / 2;
//         SDL_RenderSetViewport(rend, &topRightViewport);
//         //Render texture to screen
//         SDL_RenderCopy(rend, textur, NULL, NULL);

//         //Bottom viewport
//         SDL_Rect bottomViewport;
//         bottomViewport.x = 0;
//         bottomViewport.y = SCREEN_HEIGHT / 2;
//         bottomViewport.w = SCREEN_WIDTH;
//         bottomViewport.h = SCREEN_HEIGHT / 2;
//         SDL_RenderSetViewport(rend, &bottomViewport);
//         //Render texture to screen
//         SDL_RenderCopy(rend, textur, NULL, NULL);
//         //Update screen
//         SDL_RenderPresent(rend);
//     }
//     return quit(&win, &rend, &textur);