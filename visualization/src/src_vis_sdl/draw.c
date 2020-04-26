/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/04 14:59:20 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vis_filler.h"
#include "../../include/vis_sdl.h"

void		draw_map_grid(t_rend *r, t_rect *rect)
{
	int	i;
	int	j;

	i = 0; // с 0, не с -1!
	while (++i <= rect->earth.h / rect->asian.h - 1)
	{
		j = 0; // с 0, не с -1!
		while (++j <= rect->earth.w / rect->asian.w - 1)
		{
			rect->earth_grid.w = 1;
			rect->earth_grid.h = rect->earth.h;
			rect->earth_grid.x = rect->earth.x + j * rect->asian.w;
			rect->earth_grid.y = rect->earth.y;
			SDL_RenderCopy(r->rend, r->t->earth_grid, NULL, &(rect->earth_grid));
			rect->earth_grid.w = rect->earth.w;
			rect->earth_grid.h = 1;
			rect->earth_grid.x = rect->earth.x;
			rect->earth_grid.y = rect->earth.y + i * rect->asian.h;
			SDL_RenderCopy(r->rend, r->t->earth_grid, NULL, &(rect->earth_grid));
		}
	}
	return ;
}

void		draw_figure(t_rend *r, t_rect *rect, t_f *lst)
{
	int i;
	int j;

	i = -1;
	j = -1;
	if (lst->prev)
	{
		lst = lst->prev;
		while (++i < lst->p->height)
		{
			j = -1;
			while (++j < lst->p->width)
			{
				if (lst->p->piece[i][j] == 1)
				{
					rect->figure.x = rect->asian.w * (j + lst->pos->j) + rect->earth.x;
					rect->figure.y = rect->asian.h * (i + lst->pos->i) + rect->earth.y;
					if (lst->pos->turn == 'O')
						SDL_SetTextureColorMod(r->t->figure, 80, 80, 80);
					else
						SDL_SetTextureColorMod(r->t->figure, 255, 255, 255);
					SDL_RenderCopy(r->rend, r->t->figure, NULL, &(rect->figure));
				}
			}
		}
		lst = lst->next;
	}
	return ;
}

void		draw_map(t_rend *r, t_rect *rect, t_f *lst)
{
	int i;
	int j;

	//EARTH
	SDL_RenderCopy(r->rend, r->t->earth, NULL, &(rect->earth));
	//ASIANS AND COVID19
	i = -1;
	while (++i < lst->m->height)
	{
		j = -1;
		while (++j < lst->m->width)
		{
			if (lst->m->map[i][j] == -1)
			{
				rect->asian.x = (rect->asian.w * j) + rect->earth.x;
				rect->asian.y = (rect->asian.h * i) + rect->earth.y;
				SDL_RenderCopy(r->rend, r->t->asian, NULL, &(rect->asian));
			}
			else if (lst->m->map[i][j] == -2)
			{
				rect->cv19.x = (rect->cv19.w * j) + rect->earth.x;
				rect->cv19.y = (rect->cv19.h * i) + rect->earth.y;
				SDL_RenderCopy(r->rend, r->t->cv19, NULL, &(rect->cv19));
			}
		}
	}
	return ;
}

void		draw_playername(t_rend *r, t_rect *rect)
{
	//NAME OF P1 that will play for ASIANS
	SDL_RenderCopy(r->rend, r->f->p1_name, NULL, &(rect->p1_name));
	//NAME OF P2 that will play for COVID
	SDL_RenderCopy(r->rend, r->f->p2_name, NULL, &(rect->p2_name));
	//NAME OF P3 that will play for EARTH
	SDL_RenderCopy(r->rend, r->f->p3_name, NULL, &(rect->p3_name));
	//ASIANS :
	SDL_RenderCopy(r->rend, r->f->p1_keymenu, NULL, &(rect->p1_keymenu));
	// COVID19 :
	SDL_RenderCopy(r->rend, r->f->p2_keymenu, NULL, &(rect->p2_keymenu));
	// EARTH:
	SDL_RenderCopy(r->rend, r->f->p3_keymenu, NULL, &(rect->p3_keymenu));
	return ;
}

void		draw_message(t_rend *r, t_rect *rect)
{
	// CMD + W
	SDL_RenderCopy(r->rend, r->f->cmdw, NULL, &(rect->cmdw));
	// QUIT
	SDL_RenderCopy(r->rend, r->f->quit, NULL, &(rect->quit));
	// SPACE
	SDL_RenderCopy(r->rend, r->f->space, NULL, &(rect->space));
	// PAUSE
	SDL_SetTextureBlendMode(r->f->pause, r->blend_p);
	SDL_RenderCopy(r->rend, r->f->pause, NULL, &(rect->pause));
	// RESUME
	SDL_SetTextureBlendMode(r->f->resume, r->blend_r);
	SDL_RenderCopy(r->rend, r->f->resume, NULL, &(rect->resume));
	// R
	SDL_RenderCopy(r->rend, r->f->re, NULL, &(rect->re));
	// REPLAY
	SDL_RenderCopy(r->rend, r->f->replay, NULL, &(rect->replay));
	// <----- CURSOR BACK
	SDL_RenderCopy(r->rend, r->t->cur_back, NULL, &(rect->cur_back));
	// -----> CURSOR FORWARD
	SDL_RenderCopyEx(r->rend, r->t->cur_forward, NULL, &(rect->cur_forward), 0.0, 0, r->flip_hor);
	// BACK_FORWARD
	SDL_RenderCopy(r->rend, r->f->back_forward, NULL, &(rect->back_forward));
	// /\ CURSOR UP
	SDL_RenderCopyEx(r->rend, r->t->cur_up, NULL, &(rect->cur_up), 90.0, 0, r->flip_non);
	// \/ CURSOR DOWN
	SDL_RenderCopyEx(r->rend, r->t->cur_down, NULL, &(rect->cur_down), 270.0, 0, r->flip_non);
	// SPEED
	SDL_RenderCopy(r->rend, r->f->speed, NULL, &(rect->speed));
	// SPEEDRATE
	SDL_RenderCopy(r->rend, r->f->speedrate, NULL, &(rect->speedrate));
	return ;
}

void		draw_menu(t_rend *r, t_rect *rect, t_f *lst)
{
	// FILLBOARD
	SDL_RenderCopy(r->rend, r->t->fillboard, NULL, &(rect->fillboard));
	// MENU KEY
	SDL_RenderCopy(r->rend, r->t->keymenu, NULL, &(rect->keymenu));
	// LEFT BAR
	SDL_SetTextureAlphaMod(r->t->bar_left, 125);
	SDL_RenderCopy(r->rend, r->t->bar_left, NULL, &(rect->bar_left));
	// RIGHT BAR
	SDL_SetTextureAlphaMod(r->t->bar_right, 125);
	SDL_RenderCopy(r->rend, r->t->bar_right, NULL, &(rect->bar_right));
	// CENTER BAR
	SDL_RenderCopy(r->rend, r->t->bar_center, NULL, &(rect->bar_center));
	// PROGRESS BAR P1
	rect->bar_center_p1.w = 1200 * (lst->ally_cnt * 100 / r->event->mapsize) / 100;
	SDL_RenderCopy(r->rend, r->t->bar_center_p1, NULL, &(rect->bar_center_p1));
	// PROGRESS BAR P2
	rect->bar_center_p2.x = 1408 - (1200 * (lst->enemy_cnt * 100 / r->event->mapsize) / 100);
	rect->bar_center_p2.w = 1200 * (lst->enemy_cnt * 100 / r->event->mapsize) / 100;
	SDL_RenderCopy(r->rend, r->t->bar_center_p2, NULL, &(rect->bar_center_p2));

	// DELIMITER BAR
	SDL_RenderCopy(r->rend, r->t->bar_delimiter, NULL, &(rect->bar_delimiter));
	SDL_RenderCopy(r->rend, r->t->bar_delimiter, NULL, &(rect->bar_delimiter_2));
	// ASIANS BAR
	SDL_RenderCopy(r->rend, r->f->p1_bar, NULL, &(rect->p1_bar));
	// COVID19 BAR
	SDL_RenderCopy(r->rend, r->f->p2_bar, NULL, &(rect->p2_bar));

	// SCORE P1 (ASIANS)
	rect->p1_score.x = rect->bar_delimiter.x + INDENT / 1.2;
	rect->p1_score.y = rect->bar_delimiter.y + INDENT / 2.8;
	SDL_QueryTexture(r->f->p1_score, NULL, NULL, &(rect->p1_score.w), &(rect->p1_score.h));
	SDL_RenderCopy(r->rend, r->f->p1_score, NULL, &(rect->p1_score));
	// SCORE P2 (COVID19)
	rect->p2_score.x = rect->bar_delimiter_2.x - INDENT * 2;
	rect->p2_score.y = rect->bar_delimiter_2.y + INDENT / 2.8;
	SDL_QueryTexture(r->f->p2_score, NULL, NULL, &(rect->p2_score.w), &(rect->p2_score.h));
	SDL_RenderCopy(r->rend, r->f->p2_score, NULL, &(rect->p2_score));
	return ;
}

void		draw_bacground(t_rend *r, t_rect *rect)
{
	int i;

	i = 0;
	while (i < SCREEN_WIDTH * SCREEN_HEIGHT
	+ 2 * (SCREEN_HEIGHT + SCREEN_WIDTH))
	{
		if (rect->bg.x >= SCREEN_WIDTH)
			r->event->shift = 0;
		rect->bg.x = (i % (SCREEN_WIDTH + 32) - INDENT) + r->event->shift;
		rect->bg.y = (i / (SCREEN_WIDTH + 32)) * 32 - INDENT + r->event->shift;
		rect->bg.w = INDENT;
		rect->bg.h = INDENT;
		SDL_SetTextureColorMod(r->t->bg, 115, 115, 115);
		SDL_RenderCopy(r->rend, r->t->bg, NULL, &(rect->bg));
		i = i + INDENT;
	}
	r->event->shift++;
	return ;
}
