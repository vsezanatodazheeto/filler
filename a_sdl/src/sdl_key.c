/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:53:36 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/03 19:10:27 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

// extern SDL_Event e;

void		key_event(SDL_Event e, t_rend *r, t_rect *rect, t_f **lst, t_f **fst_lst)
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
			if (e.key.keysym.sym == SDLK_r) // R
			{
				*lst = *fst_lst;
				if (score_recount(r, *lst) != 0)
				{
					ft_printf("here\n");
					break ;
				}
				r->event->pause++;
				blendmode_swap(r);
			}
			if (e.key.keysym.sym == SDLK_SPACE) // SPACE
			{
				if ((*lst)->next)
				{
					SDL_DestroyTexture(r->f->space);
					r->f->space = load_font(&(r->rend), SPACE, FONT_SIZE, grey);
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
				r->f->speedrate = load_font(&(r->rend), (char *)SPEEDARRAY[r->event->color], FONT_SIZE_2, COLORARRAY[r->event->color]);
			}
			if (e.key.keysym.sym == SDLK_DOWN && r->event->delay < DELAY_MAX) // DOWN
			{
				r->event->color--;
				r->event->delay += DELAY_STEP;
				SDL_SetTextureColorMod(r->t->cur_down, 74, 66, 55);
				SDL_DestroyTexture(r->f->speedrate);
				r->f->speedrate = load_font(&(r->rend), (char *)SPEEDARRAY[r->event->color], FONT_SIZE_2, COLORARRAY[r->event->color]);
			}
			if (e.key.keysym.sym == SDLK_RIGHT) // RIGHT
				if ((*lst)->next && r->event->pause % 2 != 0)
				{
					*lst = (*lst)->next;
					SDL_SetTextureColorMod(r->t->cur_forward, 74, 66, 55);
					if (score_recount(r, *lst) != 0)
					{
						ft_printf("here\n");
						break;
					}
				}
			if (e.key.keysym.sym == SDLK_LEFT) // LEFT
				if ((*lst)->prev && r->event->pause % 2 != 0)
				{
					*lst = (*lst)->prev;
					SDL_SetTextureColorMod(r->t->cur_back, 74, 66, 55);
					if (score_recount(r, *lst) != 0)
					{
						ft_printf("here\n");
						break ;
					}
				}
		}
		if (e.type == SDL_KEYUP)
		{
			// SPACE
			SDL_DestroyTexture(r->f->space);
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