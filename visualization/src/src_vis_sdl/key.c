/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:53:36 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/04 14:55:17 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vis_filler.h"
#include "../../include/vis_sdl.h"

int				key_event(SDL_Event e, t_rend *r, t_f **lst, t_f **fst_lst, t_music *music)
{
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			SDL_DestroyTexture(r->f->space);
			r->f->cmdw = load_font(&(r->rend), CMDW, FONT_SIZE, grey);
			r->event->run = FALSE;
		}
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE) // ESC
			{
				SDL_DestroyTexture(r->f->space);
				r->f->cmdw = load_font(&(r->rend), CMDW, FONT_SIZE, grey);
				r->event->run = FALSE;
			}
			if (e.key.keysym.sym == SDLK_r) // R
			{
				// MUSIC
				if (r->event->pause == 1)
				{
					Mix_PlayMusic(music->fastest, 10);
					Mix_VolumeMusic(MIX_MAX_VOLUME);
				}
				*lst = *fst_lst;
				SDL_DestroyTexture(r->f->re);
				if (!(r->f->re = load_font(&(r->rend), R, FONT_SIZE, grey)))
					return (1);
				if (score_recount(r, *lst) != 0)
					return (1);
				r->event->pause++;
				blendmode_swap(r);
			}
			if (e.key.keysym.sym == SDLK_SPACE) // SPACE
			{
				// MUSIC
				if (r->event->pause == 1)
				{
					Mix_PlayMusic(music->fastest, 10);
					Mix_VolumeMusic(MIX_MAX_VOLUME);
				}
				if ((*lst)->next)
				{
					SDL_DestroyTexture(r->f->space);
					if (!(r->f->space = load_font(&(r->rend), SPACE, FONT_SIZE, grey)))
						return (1);
				}
				r->event->pause++;
				blendmode_swap(r);
			}
			if (e.key.keysym.sym == SDLK_UP && r->event->delay > DELAY_MIN) // UP
			{
				r->event->color++;
				r->event->delay -= DELAY_STEP;
				SDL_SetTextureColorMod(r->t->cur_up, 74, 66, 55);
				SDL_DestroyTexture(r->f->speedrate);
				if (!(r->f->speedrate = load_font(&(r->rend), (char *)SPEEDARRAY[r->event->color], FONT_SIZE_2, COLORARRAY[r->event->color])))
					return (1);
			}
			if (e.key.keysym.sym == SDLK_DOWN && r->event->delay < DELAY_MAX) // DOWN
			{
				r->event->color--;
				r->event->delay += DELAY_STEP;
				SDL_SetTextureColorMod(r->t->cur_down, 74, 66, 55);
				SDL_DestroyTexture(r->f->speedrate);
				if (!(r->f->speedrate = load_font(&(r->rend), (char *)SPEEDARRAY[r->event->color], FONT_SIZE_2, COLORARRAY[r->event->color])))
					return (1);
			}
			if (e.key.keysym.sym == SDLK_RIGHT) // RIGHT
				if ((*lst)->next && r->event->pause % 2 != 0)
				{
					*lst = (*lst)->next;
					SDL_SetTextureColorMod(r->t->cur_forward, 74, 66, 55);
					if (score_recount(r, *lst) != 0)
						return (1);
				}
			if (e.key.keysym.sym == SDLK_LEFT) // LEFT
				if ((*lst)->prev && r->event->pause % 2 != 0)
				{
					*lst = (*lst)->prev;
					SDL_SetTextureColorMod(r->t->cur_back, 74, 66, 55);
					if (score_recount(r, *lst) != 0)
						return (1);
				}
			if (e.key.keysym.sym == SDLK_n) // N
				(Mix_VolumeMusic(MIX_MAX_VOLUME) == MIX_MAX_VOLUME) ? Mix_VolumeMusic(0) : Mix_VolumeMusic(MIX_MAX_VOLUME);
		}
		if (e.type == SDL_KEYUP)
		{
			// R
			SDL_DestroyTexture(r->f->re);
			if (!(r->f->re = load_font(&(r->rend), R, FONT_SIZE, white)))
				return (1);
			// SPACE
			SDL_DestroyTexture(r->f->space);
			if (!(r->f->space = load_font(&(r->rend), SPACE, FONT_SIZE, white)))
				return (1);
			// <----- CURSOR BACK
			SDL_SetTextureColorMod(r->t->cur_forward, 255, 255, 255);
			// -----> CURSOR FORWARD
			SDL_SetTextureColorMod(r->t->cur_back, 255, 255, 255);
			// /\ CURSOR UP
			SDL_SetTextureColorMod(r->t->cur_up, 255, 255, 255);
			// \/ CURSOR DOWN
			SDL_SetTextureColorMod(r->t->cur_down, 255, 255, 255);
		}
	}
	return (0);
}

int				keep_stop_game(t_rend *r, t_f **lst)
{
	if ((*lst)->next && r->event->pause % 2 == 0)
	{
		if ((*lst)->next)
			*lst = (*lst)->next;
		if (score_recount(r, *lst) != 0)
			return (1);
	}
	// CHAGNING RESUME / PAUSE AT THE END OF GAME
	if (!(*lst)->next)
	{
		if (r->event->pause % 2 == 0)
		{
			blendmode_swap(r);
			r->event->pause++;
		}
	}
	return (0);
}
