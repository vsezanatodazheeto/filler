/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcomic <pcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:06 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/28 06:34:16 by pcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

int mix = 0;
int delay = 40;
int i = 2; //
int n = 1;
int mapsize = 0;

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

	mapsize = lst->m->width * lst->m->height;
	int kk = 0;
	run = TRUE;

	if (init_lib())
		return (1);

	init_t_rend(r, t, f, rect);

    if (create(&win, r, player))
        return (1);

	menu_rect(r, rect, lst);
	word_rect(r, rect);
	field_rect(r, rect, lst);
	SDL_SetRenderDrawColor(r->rend, 255, 255, 255, 255);
	fst_lst = lst;
    while (run)
    {
		//CLEAR SCREEN
        SDL_RenderClear(r->rend);
		// KEYBOARD EVENTS
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
					r->f->speedrate = load_font(&(r->rend), (char *)SPEEDARRAY[i], FONT_SIZE_2, COLORARRAY[i]);
				}
				if (e.key.keysym.sym == SDLK_DOWN && delay < 80)
				{
					i--;
					delay = delay + 20;
					SDL_SetTextureColorMod( r->t->cur_down, 74, 66, 55);
					r->f->speedrate = load_font(&(r->rend), (char *)SPEEDARRAY[i], FONT_SIZE_2, COLORARRAY[i]);
				}
				if (e.key.keysym.sym == SDLK_RIGHT)
					if (lst->next && n % 2 != 0)
					{
						lst = lst->next;
						SDL_SetTextureColorMod( r->t->cur_forward, 74, 66, 55);
    					r->f->p1_score = load_font(&(r->rend), ft_itoa(lst->ally_cnt * 100 / mapsize), FONT_SIZE, white);
    					r->f->p2_score = load_font(&(r->rend), ft_strnew_size(ft_itoa(lst->enemy_cnt * 100 / mapsize), 3), FONT_SIZE, white);
					}
				if (e.key.keysym.sym == SDLK_LEFT)
					if (lst->prev && n % 2 != 0)
					{
						lst = lst->prev;
						SDL_SetTextureColorMod( r->t->cur_back, 74, 66, 55);
    					r->f->p1_score = load_font(&(r->rend), ft_itoa(lst->ally_cnt * 100 / mapsize), FONT_SIZE, white);
    					r->f->p2_score = load_font(&(r->rend), ft_strnew_size(ft_itoa(lst->enemy_cnt * 100 / mapsize), 3), FONT_SIZE, white);
					}
			}
			if (e.type == SDL_KEYUP)
			{
				// <----- CURSOR BACK
				SDL_SetTextureColorMod( r->t->cur_forward, 255, 255, 255);
				// -----> CURSOR FORWARD
				SDL_SetTextureColorMod( r->t->cur_back, 255, 255, 255);
				// /\ CURSOR UP
				SDL_SetTextureColorMod( r->t->cur_up, 255, 255, 255);
				// \/ CURSOR DOWN
				SDL_SetTextureColorMod( r->t->cur_down, 255, 255, 255);
				// ft_printf("je\n");
			}
		}
		if (lst->next && n % 2 == 0)
		{
			lst = lst->next;
    		r->f->p1_score = load_font(&(r->rend), ft_itoa(lst->ally_cnt * 100 / mapsize), FONT_SIZE, white);
    		r->f->p2_score = load_font(&(r->rend), ft_strnew_size(ft_itoa(lst->enemy_cnt * 100 / mapsize), 3), FONT_SIZE, white);
		}
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
		//RENDERING TEXTURES
		draw_bacground(r, rect);
		draw_menu(r, rect, lst);
		draw_message(r, rect);
		draw_playername(r, rect);
		draw_map(r, rect, lst);
        SDL_RenderPresent(r->rend);
		//DELAY
		SDL_Delay(delay);
		// DRAWING
        SDL_RenderPresent(r->rend);
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