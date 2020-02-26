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

extern int keker;
extern int delay;

void				draw_map(t_rend *r, t_rect *rect, t_f *lst)
{
	int i;
	int j;

	//РЕНДЕР ДЛЯ ЗЕМЛИ
	SDL_SetTextureColorMod(r->t->cv_19, 110, 155, 85);
	SDL_RenderCopy(r->rend, r->t->cv_19, NULL, &(rect->earth));
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
				rect->cv_19.x = (rect->asian.w * j) + rect->earth.x;
				rect->cv_19.y = (rect->asian.h * i) + rect->earth.y;
				SDL_SetTextureColorMod(r->t->cv_19, 199, 214, 213);
				SDL_RenderCopy(r->rend, r->t->cv_19, NULL, &(rect->cv_19));
			}
			j++;
		}
		i++;
	}
	ft_printf("ally: %d\n", lst->ally_cnt);
	ft_printf("enemy: %d\n", lst->enemy_cnt);
	ft_printf("map:: %d\n", lst->field_cnt);
	return;
}
void draw_player(t_rend *r, t_rect *rect)
{	
	//ASIANS :
	rect->p1_.x = rect->filler.w + INDENT + 20;
	rect->p1_.y = rect->p1_name.y - INDENT - 20;
	rect->p1_.w = 1;
	rect->p1_.h = 1;
	SDL_QueryTexture(r->f->p1_, NULL, NULL, &(rect->p1_.w), &(rect->p1_.h));
	SDL_RenderCopy(r->rend, r->f->p1_, NULL, &(rect->p1_));
	
	// COVID19 :
	rect->p2_.x = rect->filler.w + INDENT + 20;
	rect->p2_.y = rect->p2_name.y - INDENT - 20;
	rect->p2_.w = 1;
	rect->p2_.h = 1;
	SDL_QueryTexture(r->f->p2_, NULL, NULL, &(rect->p2_.w), &(rect->p2_.h));
	SDL_RenderCopy(r->rend, r->f->p2_, NULL, &(rect->p2_));

	// EARTH:
	rect->p3_.x = rect->filler.w + INDENT + 20;
	rect->p3_.y = rect->p3_name.y - INDENT - 24;
	rect->p3_.w = 1;
	rect->p3_.h = 1;
	SDL_QueryTexture(r->f->p3_, NULL, NULL, &(rect->p3_.w), &(rect->p3_.h));
	SDL_RenderCopy(r->rend, r->f->p3_, NULL, &(rect->p3_));



	return ;
}

void				draw_player_name(t_rend *r, t_rect *rect)
{
	//PLAYER_1 that will play for ASIANS
	rect->p1_name.x = rect->filler.w + INDENT + 20;
	rect->p1_name.y = rect->key.h - (INDENT * 5 - 8);
	rect->p1_name.w = 1;
	rect->p1_name.h = 1;
	SDL_QueryTexture(r->f->p1_name, NULL, NULL, &(rect->p1_name.w), &(rect->p1_name.h));
	SDL_RenderCopy(r->rend, r->f->p1_name, NULL, &(rect->p1_name));
	//PLAYER_2 that will play for COVID
	rect->p2_name.x = rect->filler.w + INDENT + 20;
	rect->p2_name.y = rect->key.h - INDENT;
	rect->p2_name.w = 1;
	rect->p2_name.h = 1;
	SDL_QueryTexture(r->f->p2_name, NULL, NULL, &(rect->p2_name.w), &(rect->p2_name.h));
	SDL_RenderCopy(r->rend, r->f->p2_name, NULL, &(rect->p2_name));
	//PLAYER_3 that will play for EARTH
	rect->p3_name.x = rect->filler.w + INDENT + 20;
	rect->p3_name.y = rect->key.h - (INDENT * 8 + 14);
	rect->p3_name.w = 1;
	rect->p3_name.h = 1;
	SDL_QueryTexture(r->f->p3_name, NULL, NULL, &(rect->p3_name.w), &(rect->p3_name.h));
	SDL_RenderCopy(r->rend, r->f->p3_name, NULL, &(rect->p3_name));
}

void				draw_message(t_rend *r, t_rect *rect)
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
	SDL_QueryTexture(r->t->cur_back, NULL, NULL, &(rect->cur_back.w), &(rect->cur_back.h));
	SDL_RenderCopy(r->rend, r->t->cur_back, NULL, &(rect->cur_back));
	SDL_SetTextureColorMod( r->t->cur_back, 255, 255, 255);
	// -----> CURSOR FORWARD
	SDL_QueryTexture(r->t->cur_forward, NULL, NULL, &(rect->cur_forward.w), &(rect->cur_forward.h));
	SDL_RenderCopyEx(r->rend, r->t->cur_forward, NULL, &(rect->cur_forward), 0.0, 0, r->flip_hor);
	SDL_SetTextureColorMod( r->t->cur_forward, 255, 255, 255);
	// BACK_FORWARD
	SDL_RenderCopy(r->rend, r->f->back_forward, NULL, &(rect->back_forward));

	// /\ CURSOR UP
	SDL_QueryTexture(r->t->cur_up, NULL, NULL, &(rect->cur_up.w), &(rect->cur_up.h));
	SDL_RenderCopyEx(r->rend, r->t->cur_up, NULL, &(rect->cur_up), 90.0, 0, r->flip_non);
	SDL_SetTextureColorMod( r->t->cur_up, 255, 255, 255);
	// \/ CURSOR DOWN
	SDL_QueryTexture(r->t->cur_down, NULL, NULL, &(rect->cur_down.w), &(rect->cur_down.h));
	SDL_RenderCopyEx(r->rend, r->t->cur_down, NULL, &(rect->cur_down), 270.0, 0, r->flip_non);
	SDL_SetTextureColorMod( r->t->cur_down, 255, 255, 255);
	// SPEED
	SDL_RenderCopy(r->rend, r->f->speed, NULL, &(rect->speed));
	// SPEEDRATE
	SDL_RenderCopy(r->rend, r->f->speedrate, NULL, &(rect->speedrate));
	return ;
}

void				draw_menu(t_rend *r, t_rect *rect)
{	
	// FILLBOARD
	SDL_RenderCopy(r->rend, r->t->m_filler, NULL, &(rect->filler));
	// MENU KEY
	SDL_RenderCopy(r->rend, r->t->m_key, NULL, &(rect->key));
	// LEFT BAR
	SDL_RenderCopy(r->rend, r->t->m_bar_left, NULL, &(rect->bar_left));
	// RIGHT BAR
	SDL_RenderCopy(r->rend, r->t->m_bar_right, NULL, &(rect->bar_right));
	// CENTER BAR
	SDL_RenderCopy(r->rend, r->t->m_bar_center, NULL, &(rect->bar_center));
	// DELIMITER BAR
	SDL_RenderCopy(r->rend, r->t->m_bar_delimiter, NULL, &(rect->bar_bord));
	SDL_RenderCopy(r->rend, r->t->m_bar_delimiter, NULL, &(rect->bar_bord_2));
	// ASIANS BAR
	SDL_RenderCopy(r->rend, r->f->p1, NULL, &(rect->p1));
	// COVID19 BAR
	SDL_RenderCopy(r->rend, r->f->p2, NULL, &(rect->p2));
	return ;
}

void				draw_bacground(t_rend *r, t_rect *rect)
{
	int 			i;

	i = 0;
	while (i < SCREEN_WIDTH * SCREEN_HEIGHT + 2 * SCREEN_HEIGHT + 2 * SCREEN_WIDTH)
	{
		if (rect->bg.x >= SCREEN_WIDTH)
		{
			keker = 0;
		}
		rect->bg.x = (i % (SCREEN_WIDTH + 32) - INDENT) + keker;
		rect->bg.y = (i / (SCREEN_WIDTH + 32)) * 32 - INDENT+ keker;
		rect->bg.w = 32;
		rect->bg.h = 32;
		// SDL_RenderSetViewport(rend, &topLeftViewport);
		//Render texture to screen
		SDL_SetTextureColorMod( r->t->bg, 75, 66, 55);
		SDL_RenderCopy(r->rend, r->t->bg, NULL, &(rect->bg));
		i = i + INDENT;
	}
	keker++;
	return ;
}