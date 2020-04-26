/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:06 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/04 14:51:31 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vis_filler.h"
#include "../../include/vis_sdl.h"

void				sdl_main(t_f *lst, t_player *player)
{
	SDL_Window		*win;
	SDL_Event		e;
	t_rend			r[1];
	t_textur		t[1];
	t_font			f[1];
	t_rect			rect[1];
	t_event			event[1];
	t_music			music[1];
	t_f				*fst_lst;

	win = NULL;
	fst_lst = lst;
	if (init_lib() != 0)
	{
		ft_printf("{red}unable to load library in INIT_LIB!{eoc}\n");
		return ;
	}
	init_t_rend(r, t, f, rect, event, player, lst);
	if (create(&win, r, music) != 0)
		return ;
	// RECT
	rect_menu(r, rect);
	rect_bar(r, rect, lst);
	rect_message(r, rect);
	rect_field(r, rect, lst);
	while (r->event->run)
	{
		SDL_RenderClear(r->rend);
		// KEY EVENTS
		if (key_event(e, r, &lst, &fst_lst, music) != 0)
			break;
		// KEEP/STOP GAME
		if (keep_stop_game(r, &lst) != 0)
			break ;
		// RENDERING TEXTURES
		draw_bacground(r, rect);
		draw_menu(r, rect, lst);
		draw_message(r, rect);
		draw_playername(r, rect);
		draw_map(r, rect, lst);
		draw_figure(r, rect, lst);
		draw_map_grid(r, rect);
		// DELAY
		SDL_Delay(r->event->delay);
		SDL_RenderPresent(r->rend);
	}
	return (quit(&win, r, music));
}
