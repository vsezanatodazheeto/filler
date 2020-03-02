/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:53:36 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/02 20:48:40 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

extern int mapsize;
extern int e_pause;
extern SDL_Event e;

void		key_event(t_rend *r, t_rect *rect, t_f **lst, t_f **fst_lst)
{
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			r->f->cmdw = load_font(&(r->rend), CMDW, FONT_SIZE, grey);
			r->event->run = FALSE;
		}
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_r) // R
			{
				*lst = *fst_lst;
				r->event->str_score = ft_itoa((*lst)->ally_cnt * 100 / mapsize);
				// r->f->p1_score = load_font(&(r->rend), r->event->str_score, FONT_SIZE, white);
				ft_strdel(&r->event->str_score);
				r->event->str_score = ft_itoa((*lst)->enemy_cnt * 100 / mapsize);
				// r->f->p2_score = load_font(&(r->rend), ft_strnew_size(&r->event->str_score, 3), FONT_SIZE, white);
				ft_strdel(&r->event->str_score);
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
			if (e.key.keysym.sym == SDLK_SPACE) // SPACE
			{
				if ((*lst)->next)
					r->f->space = load_font(&(r->rend), SPACE, FONT_SIZE, grey);
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
			if (e.key.keysym.sym == SDLK_UP && r->event->delay > DELAY_MIN) // UP
			{
				r->event->color++;
				r->event->delay -= DELAY_STEP;
				SDL_SetTextureColorMod(r->t->cur_up, 74, 66, 55);
				r->f->speedrate = load_font(&(r->rend), (char *)SPEEDARRAY[r->event->color], FONT_SIZE_2, COLORARRAY[r->event->color]);
			}
			if (e.key.keysym.sym == SDLK_DOWN && r->event->delay < DELAY_MAX) // DOWN
			{
				r->event->color--;
				r->event->delay += DELAY_STEP;
				SDL_SetTextureColorMod(r->t->cur_down, 74, 66, 55);
				r->f->speedrate = load_font(&(r->rend), (char *)SPEEDARRAY[r->event->color], FONT_SIZE_2, COLORARRAY[r->event->color]);
			}
			if (e.key.keysym.sym == SDLK_RIGHT) // RIGHT
				if ((*lst)->next && e_pause % 2 != 0)
				{
					*lst = (*lst)->next;
					SDL_SetTextureColorMod(r->t->cur_forward, 74, 66, 55);
					r->event->str_score = ft_itoa((*lst)->ally_cnt * 100 / mapsize);
					// r->f->p1_score = load_font(&(r->rend), r->event->str_score, FONT_SIZE, white);
					ft_strdel(&r->event->str_score);
					r->event->str_score = ft_itoa((*lst)->enemy_cnt * 100 / mapsize);
					// r->f->p2_score = load_font(&(r->rend), ft_strnew_size(&r->event->str_score, 3), FONT_SIZE, white);
					ft_strdel(&r->event->str_score);
				}
			if (e.key.keysym.sym == SDLK_LEFT) // LEFT
				if ((*lst)->prev && e_pause % 2 != 0)
				{
					*lst = (*lst)->prev;
					SDL_SetTextureColorMod(r->t->cur_back, 74, 66, 55);
					r->event->str_score = ft_itoa((*lst)->ally_cnt * 100 / mapsize);
					// r->f->p1_score = load_font(&(r->rend), r->event->str_score, FONT_SIZE, white);
					ft_strdel(&r->event->str_score);
					r->event->str_score = ft_itoa((*lst)->enemy_cnt * 100 / mapsize);
					// r->f->p2_score = load_font(&(r->rend), ft_strnew_size(&r->event->str_score, 3), FONT_SIZE, white);
					ft_strdel(&r->event->str_score);
				}
		}
		if (e.type == SDL_KEYUP)
		{
			// SPACE
			r->f->space = load_font(&(r->rend), SPACE, FONT_SIZE, white);
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
	return ;
}