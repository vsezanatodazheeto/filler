/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:06 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/16 06:34:27 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler_v.h"

int main_v (t_filler *lst)
{
	SDL_Window *win = NULL;
    SDL_Renderer *rend = NULL;
    SDL_Texture *bg = NULL;
    SDL_Texture *m_key = NULL;
    SDL_Texture *m_filler = NULL;
    SDL_Texture *m_p1 = NULL;
    SDL_Texture *m_p2 = NULL;
    SDL_Texture *m_bar = NULL;

    
	int i = 0;
	if (create(&win, &rend) == 1)
		return 1;
    write(1, "aaa\n", 4);
	if (load(&rend, &bg, &m_key, &m_filler, &m_p1, &m_p2, &m_bar) == 1)
		return 1;
    TTF_Font *sans = NULL;
    if(!(sans = TTF_OpenFont("resources/fear.ttf", 28)))
    {
        ;
        // ft_printf("%s\n", IMG_GetError());
    }
    SDL_Color black = {0, 0, 0};
    SDL_Surface *surface = TTF_RenderText_Solid(sans, "Abandlin", black);
    SDL_Texture *t_p1 = SDL_CreateTextureFromSurface(rend, surface);

    int	run = TRUE;
    SDL_Event e;
    SDL_Rect bg_p;
    SDL_Rect m_key_p;
    SDL_Rect m_filler_p;
    SDL_Rect m_p1_p;
    SDL_Rect m_p2_p;
    SDL_Rect m_bar_p;
    SDL_Rect t_p1_p;
    while (run)
    {
        while (SDL_PollEvent(&e) != 0)
            if (e.type == SDL_QUIT)
                run = FALSE;

        //Clear screen
        SDL_RenderClear(rend);
		i = 0;
		while (i < SCREEN_WIDTH * SCREEN_HEIGHT)
        {
            //Top left corner viewport
            bg_p.x = (i % SCREEN_WIDTH);
            bg_p.y = (i / SCREEN_WIDTH) * 32;
            bg_p.w = 32;
            bg_p.h = 32;

            // SDL_RenderSetViewport(rend, &topLeftViewport);
            //Render texture to screen
            SDL_RenderCopy(rend, bg, NULL, &bg_p);
            i = i + 32;
        }

        m_p1_p.x = INDENT;
        m_p1_p.y = INDENT;
        m_p1_p.w = SCREEN_WIDTH / 5;
        m_p1_p.h = BAR_HEIGHT;

        m_p2_p.x = INDENT;
        m_p2_p.y = BAR_HEIGHT + (INDENT * 2);
        m_p2_p.w = SCREEN_WIDTH / 5;
        m_p2_p.h = BAR_HEIGHT;


        m_filler_p.x = INDENT;
        m_filler_p.y = INDENT;
        m_filler_p.w = SCREEN_WIDTH - (INDENT * 2);
        m_filler_p.h = SCREEN_HEIGHT - (BAR_HEIGHT * 2)- (INDENT * 4);

        m_bar_p.x = INDENT;
        m_bar_p.y = m_filler_p.h + (INDENT * 2);
        m_bar_p.w = SCREEN_WIDTH - (INDENT * 2);
        m_bar_p.h = BAR_HEIGHT;

        m_key_p.x = INDENT;
        m_key_p.y = m_filler_p.h + m_key_p.h + (INDENT * 3);
        m_key_p.w = SCREEN_WIDTH - (INDENT * 2);
        m_key_p.h = BAR_HEIGHT;

        t_p1_p.x = 32;
        t_p1_p.y = m_filler_p.h + (INDENT * 2) + (BAR_HEIGHT / 4);
        t_p1_p.w = 200;
        t_p1_p.h = 50;
		SDL_SetTextureColorMod( m_key, 0, 0, 0);
		SDL_SetTextureAlphaMod( m_key, 150);
		// SDL_SetTextureColorMod( m_p1, 64, 64, 64 );
		// SDL_SetTextureAlphaMod( m_p1, 150);
		// SDL_SetTextureColorMod( m_p2, 64, 64, 64 );
		// SDL_SetTextureAlphaMod( m_p2, 150);
        // Render m_key, m_p1, m_p2 to screen
        SDL_RenderCopy(rend, m_filler, NULL, &m_filler_p);
        // SDL_RenderCopy(rend, m_p1, NULL, &m_p1_p);
        // SDL_RenderCopy(rend, m_p2, NULL, &m_p2_p);
        SDL_RenderCopy(rend, m_bar, NULL, &m_bar_p);
        SDL_RenderCopy(rend, m_key, NULL, &m_key_p);
        SDL_RenderCopy(rend, t_p1, NULL, &t_p1_p);
        //Update screen
        SDL_RenderPresent(rend);
    }
    return quit(&win, &rend, &bg, &m_key, &m_p1, &m_p2);
}

// TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
// SDL_Color White = {255, 255, 255};  
// SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White);
// SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
// SDL_Rect Message_rect; //create a rect
// Message_rect.x = 0;  //controls the rect's x coordinate 
// Message_rect.y = 0; // controls the rect's y coordinte
// Message_rect.w = 100; // controls the width of the rect
// Message_rect.h = 100; // controls the height of the rect
// SDL_RenderCopy(renderer, Message, NULL, &Message_rect);



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