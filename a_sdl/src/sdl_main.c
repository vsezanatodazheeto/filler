/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:06 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/29 20:10:26 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

int e_run = TRUE; // Rendering
int e_eog = 0; //END OF GAME
int e_shift = 0; // 1 pixel e_shift fot background
int e_delay = 40;
int e_pause = 1; // even or 0 - GOING, odd - STOP
int e_side = 0; // 0 - list->next 1 - list->prev
int mapsize = 0; // width * height for filler field
int e_color = 2; // 2 - white, elementary color (0, 1, 2, 3, 4)

int                 main_v (t_f *lst, t_player *player)
{
	SDL_Window      *win;
    SDL_Event       e;
    t_rend          r[1];
    t_textur		t[1];
    t_font			f[1];
    t_rect			rect[1];
	t_f				*fst_lst;
	char			*str_score;

	str_score = NULL;
	win = NULL;
	mapsize = lst->m->width * lst->m->height;

	if (init_lib())
	{
		ft_printf("{red}something wrong with init_lib{eoc}\n");
		return (1);
	}
	init_t_rend(r, t, f, rect);
    if (create(&win, r, player))
	{
		ft_printf("{red}something wrong with create{eoc}\n");
        return (1);
	}

	menu_rect(r, rect, lst);
	word_rect(r, rect);
	field_rect(r, rect, lst);
	SDL_SetRenderDrawColor(r->rend, 255, 255, 255, 255);
	fst_lst = lst;
    while (e_run)
    {
		//CLEAR SCREEN
        SDL_RenderClear(r->rend);
		// KEYBOARD EVENTS
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				r->f->k_quit = load_font(&(r->rend), K_QUIT, FONT_SIZE ,brown);
				e_run = FALSE;
			}
            if (e.type == SDL_KEYDOWN)
            {
				if (e.key.keysym.sym == SDLK_r)						// R
				{
					lst = fst_lst;
					e_pause++;
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
                if (e.key.keysym.sym == SDLK_SPACE)					// SPACE
                {
					if (lst->next)
						r->f->k_pause = load_font(&(r->rend), K_PAUSE, FONT_SIZE ,brown);
					e_pause++;
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
				if (e.key.keysym.sym == SDLK_UP && e_delay > 0)		// UP
				{
					e_color++;
					e_delay = e_delay - 20;
					SDL_SetTextureColorMod( r->t->cur_up, 74, 66, 55);
					r->f->speedrate = load_font(&(r->rend), (char *)SPEEDARRAY[e_color], FONT_SIZE_2, COLORARRAY[e_color]);
				}
				if (e.key.keysym.sym == SDLK_DOWN && e_delay < 80)	// DOWN
				{
					e_color--;
					e_delay = e_delay + 20;
					SDL_SetTextureColorMod( r->t->cur_down, 74, 66, 55);
					r->f->speedrate = load_font(&(r->rend), (char *)SPEEDARRAY[e_color], FONT_SIZE_2, COLORARRAY[e_color]);
				}
				if (e.key.keysym.sym == SDLK_RIGHT)					// RIGHT
					if (lst->next && e_pause % 2 != 0)
					{
						lst = lst->next;
						SDL_SetTextureColorMod( r->t->cur_forward, 74, 66, 55);
						str_score = ft_itoa(lst->ally_cnt * 100 / mapsize);
    					r->f->p1_score = load_font(&(r->rend), str_score, FONT_SIZE, white);
						ft_strdel(&str_score);
						str_score = ft_itoa(lst->enemy_cnt * 100 / mapsize);
    					r->f->p2_score = load_font(&(r->rend), ft_strnew_size(&str_score, 3), FONT_SIZE, white);
						ft_strdel(&str_score);
					}
				if (e.key.keysym.sym == SDLK_LEFT)					// LEFT
					if (lst->prev && e_pause % 2 != 0)
					{
						lst = lst->prev;
						SDL_SetTextureColorMod( r->t->cur_back, 74, 66, 55);
						str_score = ft_itoa(lst->ally_cnt * 100 / mapsize);
    					r->f->p1_score = load_font(&(r->rend), str_score, FONT_SIZE, white);
						ft_strdel(&str_score);
						str_score = ft_itoa(lst->enemy_cnt * 100 / mapsize);
    					r->f->p2_score = load_font(&(r->rend), ft_strnew_size(&str_score, 3), FONT_SIZE, white);
						ft_strdel(&str_score);
					}
			}
			if (e.type == SDL_KEYUP)
			{
				// SPACE
				r->f->k_pause = load_font(&(r->rend), K_PAUSE, FONT_SIZE, white);
				// <----- CURSOR BACK
				SDL_SetTextureColorMod( r->t->cur_forward, 255, 255, 255);
				// -----> CURSOR FORWARD
				SDL_SetTextureColorMod( r->t->cur_back, 255, 255, 255);
				// /\ CURSOR UP
				SDL_SetTextureColorMod( r->t->cur_up, 255, 255, 255);
				// \/ CURSOR DOWN
				SDL_SetTextureColorMod( r->t->cur_down, 255, 255, 255);
			}
		}
		if (lst->next && e_pause % 2 == 0)
		{
			if (lst->next && e_side == 0)
				lst = lst->next;
			str_score = ft_itoa(lst->ally_cnt * 100 / mapsize);
    		r->f->p1_score = load_font(&(r->rend), str_score , FONT_SIZE, white);
			ft_strdel(&str_score);
			str_score = ft_itoa(lst->enemy_cnt * 100 / mapsize);
    		r->f->p2_score = load_font(&(r->rend), ft_strnew_size(&str_score, 3), FONT_SIZE, white);
			ft_strdel(&str_score);
		}
		if (!lst->next)
		{
			e_eog = 1;
			if (e_pause % 2 == 0)
			{
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
				e_pause++;
			}
		}
		if (lst->next && e_eog == 1)
		{
			e_eog = 0;
		}
		//RENDERING TEXTURES
		draw_bacground(r, rect);
		draw_menu(r, rect, lst);
		draw_message(r, rect);
		draw_playername(r, rect);
		draw_map(r, rect, lst);
		draw_figure(r, rect, lst);
		//DELAY
		SDL_Delay(e_delay);
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
// upd не понадобилось))))))000))))))