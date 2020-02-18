/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/18 20:58:41 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler_v.h"

void				draw_player(t_rend *r, t_rect *rect)
{
	rect->p1.x = INDENT + 10;
	rect->p1.y = rect->filler.h + (INDENT * 2) + 10;
	rect->p1.w = rect->key.w;
	rect->p1.h = BAR_HEIGHT;
	SDL_QueryTexture(r->f->p1, NULL, NULL, &(rect->p1.w), &(rect->p1.h));
	SDL_RenderCopy(r->rend, r->f->p1, NULL, &(rect->p1));
	rect->p2.x = SCREEN_WIDTH - (INDENT * 2) - (r->player->p2_len * 18) ;
	rect->p2.y = rect->filler.h + (INDENT * 2) + 10;
	rect->p2.w = (r->player->p2_len * 18);
	rect->p2.h = BAR_HEIGHT;
	SDL_QueryTexture(r->f->p2, NULL, NULL, &(rect->p2.w), &(rect->p2.h));
	SDL_RenderCopy(r->rend, r->f->p2, NULL, &(rect->p2));
	return ;
}

void				draw_msg_cursor_forward(t_rend *r, t_rect *rect)
{
	rect->cur.x = rect->filler.w + INDENT + 20;
	rect->cur.y = BAR_HEIGHT * 3 + INDENT + 28;
	rect->cur.w = 60;
	rect->cur.h = 30;
	SDL_RenderCopy(r->rend, r->t->cur, NULL, &(rect->cur));
	rect->forward.x = rect->cur.x + rect->cur.w + 170;
	rect->forward.y = BAR_HEIGHT * 3 + INDENT + 20;
	rect->forward.w = rect->key.w;
	rect->forward.h = 	BAR_HEIGHT;
	SDL_QueryTexture(r->f->forward, NULL, NULL, &(rect->forward.w), &(rect->forward.h));
	SDL_RenderCopy(r->rend, r->f->forward, NULL, &(rect->forward));
	return ;
}

void				draw_msg_cursor_back(t_rend *r, t_rect *rect)
{
	rect->cur.x = rect->filler.w + INDENT + 20;
	rect->cur.y = BAR_HEIGHT * 2 + INDENT + 28;
	rect->cur.w = 60;
	rect->cur.h = 30;
	SDL_RenderCopyEx(r->rend, r->t->cur, NULL, &(rect->cur), 0.0, 0, r->flip);
	rect->back.x = rect->cur.x + rect->cur.w + 228;
	rect->back.y = BAR_HEIGHT * 2 + INDENT + 20;
	rect->back.w = rect->key.w;
	rect->back.h = 	BAR_HEIGHT;
	SDL_QueryTexture(r->f->back, NULL, NULL, &(rect->back.w), &(rect->back.h));
	SDL_RenderCopy(r->rend, r->f->back, NULL, &(rect->back));
	return ;
}

void				draw_msg_pause(t_rend *r, t_rect *rect)
{
	rect->k_pause.x = rect->filler.w + INDENT + 20;
	rect->k_pause.y = BAR_HEIGHT + INDENT + 20;
	rect->k_pause.w = rect->key.w;
	rect->k_pause.h = BAR_HEIGHT;
	SDL_QueryTexture(r->f->k_pause, NULL, NULL, &(rect->k_pause.w), &(rect->k_pause.h));
	SDL_RenderCopy(r->rend, r->f->k_pause, NULL, &(rect->k_pause));
	rect->pause.x = rect->k_pause.x + rect->k_pause.w + 168;
	rect->pause.y = rect->k_pause.y;
	rect->pause.w = rect->key.w;
	rect->pause.h = BAR_HEIGHT;
	SDL_SetTextureBlendMode(r->f->pause, r->blend_p);
	SDL_QueryTexture(r->f->pause, NULL, NULL, &(rect->pause.w), &(rect->pause.h));
	SDL_RenderCopy(r->rend, r->f->pause, NULL, &(rect->pause));
	rect->resume.x = rect->k_pause.x + rect->k_pause.w + 144;
	rect->resume.y = rect->k_pause.y;
	rect->resume.w = rect->key.w;
	rect->resume.h = BAR_HEIGHT;
	SDL_SetTextureBlendMode(r->f->resume, r->blend_r);
	SDL_QueryTexture(r->f->resume, NULL, NULL, &(rect->resume.w), &(rect->resume.h));
	SDL_RenderCopy(r->rend, r->f->resume, NULL, &(rect->resume));
	return ;
}

void				draw_msg_quit(t_rend *r, t_rect *rect)
{
	rect->k_quit.x = rect->filler.w + INDENT + 20;
	rect->k_quit.y = INDENT + 20;
	rect->k_quit.w = rect->key.w;
	rect->k_quit.h = BAR_HEIGHT;
	SDL_QueryTexture(r->f->k_quit, NULL, NULL, &(rect->k_quit.w), &(rect->k_quit.h));
	SDL_RenderCopy(r->rend, r->f->k_quit, NULL, &(rect->k_quit));
	rect->quit.x = rect->k_quit.x + rect->k_quit.w + 160;
	rect->quit.y = rect->k_quit.y;
	rect->quit.w = rect->key.w;
	rect->quit.h = BAR_HEIGHT;
	SDL_QueryTexture(r->f->quit, NULL, NULL, &(rect->quit.w), &(rect->quit.h));
	SDL_RenderCopy(r->rend, r->f->quit, NULL, &(rect->quit));
	return ;
}

void				draw_bar(t_rend *r, t_rect *rect)
{
	rect->bar.x = INDENT;
	rect->bar.y = rect->filler.h + (INDENT * 2);
	rect->bar.w = SCREEN_WIDTH - (INDENT * 2);
	rect->bar.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->m_bar, 0, 0, 0);
	SDL_SetTextureAlphaMod(r->t->m_bar, 255);
	SDL_RenderCopy(r->rend, r->t->m_bar, NULL, &(rect->bar));
	return ;
}

void				draw_keyboard(t_rend *r, t_rect *rect)
{
	rect->key.x = rect->filler.w + INDENT;
	rect->key.y = INDENT;
	rect->key.w = SCREEN_WIDTH - rect->filler.w - (INDENT * 2);
	rect->key.h = rect->filler.h;
	SDL_SetTextureColorMod(r->t->m_key, 0, 0, 0);
	SDL_SetTextureAlphaMod(r->t->m_key, 255);
	SDL_RenderCopy(r->rend, r->t->m_key, NULL, &(rect->key));
	return ;
}

void				draw_fillboard(t_rend *r, t_rect *rect)
{
	rect->filler.x = INDENT;
	rect->filler.y = INDENT;
	rect->filler.w = (SCREEN_WIDTH / 1.30) - (INDENT * 4);
	rect->filler.h = SCREEN_HEIGHT - (BAR_HEIGHT) - (INDENT * 3);
	SDL_SetTextureColorMod( r->t->m_filler, 0, 0, 0);
	SDL_SetTextureAlphaMod(r->t->m_filler, 120);
	SDL_RenderCopy(r->rend, r->t->m_filler, NULL, &(rect->filler));
	return ;
}

void				draw_bacground(t_rend *r, t_rect *rect)
{
	int 			i;

	i = 0;
	while (i < SCREEN_WIDTH * SCREEN_HEIGHT)
	{
		//viewport
		rect->bg.x = (i % SCREEN_WIDTH);
		rect->bg.y = (i / SCREEN_WIDTH) * 32;
		rect->bg.w = 32;
		rect->bg.h = 32;

		// SDL_RenderSetViewport(rend, &topLeftViewport);
		//Render texture to screen
		SDL_RenderCopy(r->rend, r->t->bg, NULL, &(rect->bg));
		i = i + 32;
	}
	return ;
}