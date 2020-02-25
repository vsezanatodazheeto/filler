/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:06 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/25 14:06:40 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

int keker = 0;
int delay = 40;

int                 main_v (t_f *lst, t_player *player)
{
	SDL_Window      *win = NULL;
    t_rend          r[1];
    t_textur		t[1];
    t_font			f[1];
    t_rect			rect[1];
    SDL_Event       e;
	int				run;
	int				i;

    
	i = 0;
	int n = 1;
	run = TRUE;

	if (init_lib())
		return (1);

	init_t_rend(r, t, f, rect);

    if (create(&win, r, player))
        return (1);

	menu_rect(r, rect);
	word_rect(r, rect);
	field_rect(r, rect, lst);
    while (run)
    {
		i = 0;
		// checking keyboard events
		SDL_Delay(40);
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				run = FALSE;
            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_SPACE)
                {
					n++;
					if (r->blend_p == BLEND_OFF)
					{
						r->blend_p = BLEND_ON;
						r->blend_r = BLEND_OFF;
					}
					else
					{
						r->blend_p = BLEND_OFF;
						r->blend_r = BLEND_ON;
					}
                }
				if (e.key.keysym.sym == SDLK_LEFT && delay < 80)
				{
					delay = delay + 20;
					SDL_SetTextureColorMod( r->t->cur_2, 74, 66, 55);
				}
				if (e.key.keysym.sym == SDLK_RIGHT && delay > 0)
				{
					delay = delay - 20;
					SDL_SetTextureColorMod( r->t->cur, 74, 66, 55);
				}
        	}
		}
		//Clear screen
        SDL_RenderClear(r->rend);
		//RENDERING TEXTURES
		draw_bacground(r, rect);
		draw_fillboard(r, rect);
		draw_keyboard(r, rect);
		draw_bar(r, rect);
		draw_bar_bord(r, rect);
		draw_msg_quit(r, rect);
		draw_msg_pause(r, rect);
        draw_msg_cursor_back(r, rect);
        draw_msg_cursor_forward(r, rect);
		draw_player_name(r, rect);
		draw_player(r, rect);
		draw_map(r, rect, lst);
        // Update screen
		if (lst->next && n % 2 == 0)
			lst = lst->next;
        SDL_RenderPresent(r->rend);
		SDL_Delay(delay);
    }
    return quit(&win, r);
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

// ПОНАДОБИТСЯ ДЛЯ BAR
// SDL_SetRenderTarget(r, destiny);
// SDL_SetBlendMod(r, SDL_BLENDMODE_NONE);
// SDL_RenderCopy(r, source, destiny);
// SDL_SetBlendMod(r, SDL_BLENDMODE_BLEND);
// for(/* Each mask as m*/){ */
//     SDL_SetColorMod(m, c[i].r, c[i].g, c[i].b);
//     SDL_RenderCopy(r, source, destiny);