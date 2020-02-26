/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:06 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/26 20:22:35 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

int keker = 0;
int delay = 40;
int i = 2;

int                 main_v (t_f *lst, t_player *player)
{
	SDL_Window      *win = NULL;
    t_rend          r[1];
    t_textur		t[1];
    t_font			f[1];
    t_rect			rect[1];
    SDL_Event       e;
	t_f				*fst_lst;
	int				run;
	
	int n = 1;
	int kk = 0;
	run = TRUE;

	if (init_lib())
		return (1);

	init_t_rend(r, t, f, rect);

    if (create(&win, r, player))
        return (1);

	menu_rect(r, rect);
	word_rect(r, rect);
	field_rect(r, rect, lst);
	SDL_SetRenderDrawColor(r->rend, 255, 255, 255, 255);
	fst_lst = lst;
    while (run)
    {
		//Clear screen
        SDL_RenderClear(r->rend);
		//RENDERING TEXTURES
		draw_bacground(r, rect);
		draw_menu(r, rect);
		draw_message(r, rect);
		draw_player_name(r, rect);
		draw_player(r, rect);
		draw_map(r, rect, lst);
		SDL_Delay(0);
        SDL_RenderPresent(r->rend);
		// checking keyboard events
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
				if (e.key.keysym.sym == SDLK_UP && delay > 0)
				{
					i++;
					delay = delay - 20;
					SDL_SetTextureColorMod( r->t->cur_up, 74, 66, 55);
					r->f->speedrate = load_font(&(r->rend), (char *)SPEEDARRAY[i], FONT_SIZE_2, white);
				}
				if (e.key.keysym.sym == SDLK_DOWN && delay < 80)
				{
					i--;
					delay = delay + 20;
					SDL_SetTextureColorMod( r->t->cur_down, 74, 66, 55);
					r->f->speedrate = load_font(&(r->rend), (char *)SPEEDARRAY[i], FONT_SIZE_2, white);
				}
        	}
		}
		if (lst->next && n % 2 == 0)
			lst = lst->next;
		if (!lst->next && n % 2 == 0)
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
			lst = fst_lst;
		}
		SDL_Delay(delay);
        SDL_RenderPresent(r->rend);
		// rect->kek.x = 0 + kk;
		// rect->kek.y = 0 + kk;
		// rect->kek.w = 32;
		// rect->kek.h = 32;
		// SDL_SetTextureColorMod(r->t->kek, 0, 0, 255);
		// SDL_RenderCopy(r->rend, r->t->kek, NULL, &(rect->kek));
		// kk++;
		// if (rect->kek.x > SCREEN_HEIGHT || rect->kek.y > SCREEN_WIDTH)
		// 	kk = 0;
		
    }
    return quit(&win, r);
}

// ПОНАДОБИТСЯ ДЛЯ BAR
// SDL_SetRenderTarget(r, destiny);
// SDL_SetBlendMod(r, SDL_BLENDMODE_NONE);
// SDL_RenderCopy(r, source, destiny);
// SDL_SetBlendMod(r, SDL_BLENDMODE_BLEND);
// for(/* Each mask as m*/){ */
//     SDL_SetColorMod(m, c[i].r, c[i].g, c[i].b);
//     SDL_RenderCopy(r, source, destiny);