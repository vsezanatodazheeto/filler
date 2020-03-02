/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:06 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/02 20:49:01 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

int e_pause = 1; // even or 0 - GOING, odd - STOP
int mapsize = 0; // width * height for filler field
SDL_Event       e;

int                 main_v (t_f *lst, t_player *player)
{
	SDL_Window      *win;
    t_rend          r[1];
    t_textur		t[1];
    t_font			f[1];
    t_rect			rect[1];
    t_event			event[1];
	t_f				*fst_lst;

	win = NULL;
	fst_lst = lst;
	mapsize = lst->m->width * lst->m->height;

	if (init_lib() != 0)
		return (1);
	init_t_rend(r, t, f, rect, event, player);
    if (create(&win, r) != 0)
        return (1);
	// RECT
	rect_menu(r, rect);
	rect_bar(r, rect, lst);
	rect_message(r, rect);
	rect_field(r, rect, lst);
    while (r->event->run)
    {
		//CLEAR SCREEN
        SDL_RenderClear(r->rend);
		// KEY EVENTS
		key_event(r, rect, &lst, &fst_lst);

		if (lst->next && e_pause % 2 == 0)
		{
			if (lst->next)
				lst = lst->next;
			r->event->str_score = ft_itoa(lst->ally_cnt * 100 / mapsize);
    		// r->f->p1_score = load_font(&(r->rend), r->event->str_score , FONT_SIZE, white);
			ft_strdel(&r->event->str_score);
			r->event->str_score = ft_itoa(lst->enemy_cnt * 100 / mapsize);
    		// r->f->p2_score = load_font(&(r->rend), ft_strnew_size(&r->event->str_score, 3), FONT_SIZE, white);
			ft_strdel(&r->event->str_score);
		}
		// CHAGNING RESUME / PAUSE
		if (!lst->next)
		{
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
		//RENDERING TEXTURES
		draw_bacground(r, rect);
		draw_menu(r, rect, lst);
		draw_message(r, rect);
		draw_playername(r, rect);
		draw_map(r, rect, lst);
		draw_figure(r, rect, lst);
		draw_map_grid(r, rect, lst);
		//DELAY
		SDL_Delay(r->event->delay);
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