/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/25 09:14: by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

extern int mix;
extern int delay;
extern int mapsize;

void			draw_map(t_rend *r, t_rect *rect, t_f *lst)
{
	int 		i;
	int 		j;

	//EARTH
	SDL_SetTextureColorMod(r->t->cv19, 110, 155, 85);
	SDL_RenderCopy(r->rend, r->t->cv19, NULL, &(rect->earth));
	//ASIANS AND COVID19
	i = 0;
	while (i < lst->m->height)
	{
		j = 0;
		while (j < lst->m->width)
		{
			if (lst->m->map[i][j] == -1)
			{
				rect->asian.x = (rect->asian.w * j) + rect->earth.x;
				rect->asian.y = (rect->asian.h * i) + rect->earth.y;
				SDL_SetTextureColorMod(r->t->asian, 194, 1, 20);
				SDL_RenderCopy(r->rend, r->t->asian, NULL, &(rect->asian));
			}
			else if (lst->m->map[i][j] == -2)
			{
				rect->cv19.x = (rect->asian.w * j) + rect->earth.x;
				rect->cv19.y = (rect->asian.h * i) + rect->earth.y;
				SDL_SetTextureColorMod(r->t->cv19, 199, 214, 213);
				SDL_RenderCopy(r->rend, r->t->cv19, NULL, &(rect->cv19));
			}
			j++;
		}
		i++;
	}
	// ft_printf("ally: %d\n", lst->ally_cnt);
	// ft_printf("enemy: %d\n", lst->enemy_cnt);
	// ft_printf("map:: %d\n", lst->field_cnt);
	return;
}

void			draw_playername(t_rend *r, t_rect *rect)
{
	//NAME OF PLAYER_1 that will play for ASIANS
	SDL_RenderCopy(r->rend, r->f->p1_name, NULL, &(rect->p1_name));
	//NAME OF PLAYER_2 that will play for COVID
	SDL_RenderCopy(r->rend, r->f->p2_name, NULL, &(rect->p2_name));
	//PLAYER_3 that will play for EARTH
	SDL_RenderCopy(r->rend, r->f->p3_name, NULL, &(rect->p3_name));
	//ASIANS :
	SDL_RenderCopy(r->rend, r->f->p1_, NULL, &(rect->p1_));
	// COVID19 :
	SDL_RenderCopy(r->rend, r->f->p2_, NULL, &(rect->p2_));
	// EARTH:
	SDL_RenderCopy(r->rend, r->f->p3_, NULL, &(rect->p3_));
}

void			draw_message(t_rend *r, t_rect *rect)
{	
	// CMD + W
	SDL_RenderCopy(r->rend, r->f->k_quit, NULL, &(rect->k_quit));
	// QUIT
	SDL_RenderCopy(r->rend, r->f->quit, NULL, &(rect->quit));
	// SPACE
	SDL_RenderCopy(r->rend, r->f->k_pause, NULL, &(rect->k_pause));
	// PAUSE
	SDL_SetTextureBlendMode(r->f->pause, r->blend_p);
	SDL_RenderCopy(r->rend, r->f->pause, NULL, &(rect->pause));
	// RESUME
	SDL_SetTextureBlendMode(r->f->resume, r->blend_r);
	SDL_RenderCopy(r->rend, r->f->resume, NULL, &(rect->resume));
	// <----- CURSOR BACK
	SDL_RenderCopy(r->rend, r->t->cur_back, NULL, &(rect->cur_back));
	// -----> CURSOR FORWARD
	SDL_RenderCopyEx(r->rend, r->t->cur_forward, NULL, &(rect->cur_forward), 0.0, 0, r->flip_hor);
	// BACK_FORWARD
	SDL_RenderCopy(r->rend, r->f->back_forward, NULL, &(rect->back_forward));
	// /\ CURSOR UP
	SDL_QueryTexture(r->t->cur_up, NULL, NULL, &(rect->cur_up.w), &(rect->cur_up.h));
	SDL_RenderCopyEx(r->rend, r->t->cur_up, NULL, &(rect->cur_up), 90.0, 0, r->flip_non);
	// \/ CURSOR DOWN
	SDL_QueryTexture(r->t->cur_down, NULL, NULL, &(rect->cur_down.w), &(rect->cur_down.h));
	SDL_RenderCopyEx(r->rend, r->t->cur_down, NULL, &(rect->cur_down), 270.0, 0, r->flip_non);
	// SPEED
	SDL_RenderCopy(r->rend, r->f->speed, NULL, &(rect->speed));
	// SPEEDRATE
	SDL_RenderCopy(r->rend, r->f->speedrate, NULL, &(rect->speedrate));
	return ;
}

void			draw_menu(t_rend *r, t_rect *rect, t_f *lst)
{	
	// FILLBOARD
	SDL_RenderCopy(r->rend, r->t->m_filler, NULL, &(rect->filler));
	// MENU KEY
	SDL_RenderCopy(r->rend, r->t->m_key, NULL, &(rect->key));
	// LEFT BAR
	SDL_SetTextureAlphaMod(r->t->m_bar_left, 125);
	SDL_RenderCopy(r->rend, r->t->m_bar_left, NULL, &(rect->bar_left));
	// RIGHT BAR
	SDL_SetTextureAlphaMod(r->t->m_bar_right, 125);
	SDL_RenderCopy(r->rend, r->t->m_bar_right, NULL, &(rect->bar_right));
	// CENTER BAR
	SDL_RenderCopy(r->rend, r->t->m_bar_center, NULL, &(rect->bar_center));
	// PROGRESS BAR P1
	rect->bar_center_p1.w = 1200 * (lst->ally_cnt * 100 / mapsize) / 100;
	SDL_RenderCopy(r->rend, r->t->m_bar_center_p1, NULL, &(rect->bar_center_p1));
	// PROGRESS BAR P2
	rect->bar_center_p2.x = 1408 - (1200 * (lst->enemy_cnt * 100 / mapsize) / 100);
	rect->bar_center_p2.w = 1200 * (lst->enemy_cnt * 100 / mapsize) / 100;
	SDL_RenderCopy(r->rend, r->t->m_bar_center_p2, NULL, &(rect->bar_center_p2));

	// DELIMITER BAR
	SDL_RenderCopy(r->rend, r->t->m_bar_delimiter, NULL, &(rect->bar_bord));
	SDL_RenderCopy(r->rend, r->t->m_bar_delimiter, NULL, &(rect->bar_bord_2));
	// ASIANS BAR
	SDL_RenderCopy(r->rend, r->f->p1, NULL, &(rect->p1));
	// COVID19 BAR
	SDL_RenderCopy(r->rend, r->f->p2, NULL, &(rect->p2));

	// SCORE P1 (ASIANS)
	rect->p1_score.x = rect->bar_bord.x + INDENT / 1.2;
	rect->p1_score.y = rect->bar_bord.y + INDENT / 2.8;
	SDL_QueryTexture(r->f->p1_score, NULL, NULL, &(rect->p1_score.w), &(rect->p1_score.h));
	SDL_RenderCopy(r->rend, r->f->p1_score, NULL, &(rect->p1_score));
	// SCORE P2 (COVID19)
	rect->p2_score.x = rect->bar_bord_2.x - INDENT * 2;
	rect->p2_score.y = rect->bar_bord_2.y + INDENT / 2.8;
	SDL_QueryTexture(r->f->p2_score, NULL, NULL, &(rect->p2_score.w), &(rect->p2_score.h));
	SDL_RenderCopy(r->rend, r->f->p2_score, NULL, &(rect->p2_score));
	return ;
}

void			draw_bacground(t_rend *r, t_rect *rect)
{
	int 		i;

	i = 0;
	while (i < SCREEN_WIDTH * SCREEN_HEIGHT + 2 * SCREEN_HEIGHT + 2 * SCREEN_WIDTH)
	{
		if (rect->bg.x >= SCREEN_WIDTH)
			mix = 0;
		rect->bg.x = (i % (SCREEN_WIDTH + 32) - INDENT) + mix;
		rect->bg.y = (i / (SCREEN_WIDTH + 32)) * 32 - INDENT+ mix;
		rect->bg.w = 32;
		rect->bg.h = 32;
		SDL_SetTextureColorMod( r->t->bg, 75, 66, 55);
		SDL_RenderCopy(r->rend, r->t->bg, NULL, &(rect->bg));
		i = i + INDENT;
	}
	mix++;
	return ;
}