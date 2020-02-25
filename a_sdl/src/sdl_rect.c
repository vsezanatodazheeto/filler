/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/25 13:15:50 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

void				field_rect(t_rend *r, t_rect *rect, t_f *lst)
{
	// размеры квадрата азиата
	rect->asian.w = rint(rect->filler.w / lst->m->width);
	rect->asian.h = rint(rect->filler.h / lst->m->height);

	// размеры квадрата сovid
	rect->cv_19.w = rint(rect->filler.w / lst->m->width);
	rect->cv_19.h = rint(rect->filler.h / lst->m->height);

	// размеры и координаты земли
	rect->earth.w = rint(rect->asian.w * lst->m->width);
	rect->earth.h = rint(rect->asian.h * lst->m->height);
	rect->earth.x = INDENT + rint(rect->filler.w / 2) - rint(rect->earth.w / 2);
	rect->earth.y = INDENT + rint(rect->filler.h / 2) - rint(rect->earth.h / 2);
	//...
	// ft_printf("%d\n", rect->earth.w);
	// ft_printf("%d\n", rect->earth.h);
	// ft_printf("%d\n", rect->filler.w);
	// ft_printf("%d\n", rect->filler.h);
}
void				word_rect(t_rend *r, t_rect *rect)
{
	// CMD + W exit
	rect->k_quit.x = rect->filler.w + INDENT + 20;
	rect->k_quit.y = INDENT + 20;
	rect->k_quit.w = 1;
	rect->k_quit.h = 1;
	SDL_QueryTexture(r->f->k_quit, NULL, NULL, &(rect->k_quit.w), &(rect->k_quit.h));
	rect->quit.x = rect->k_quit.x + rect->k_quit.w + 185;
	rect->quit.y = rect->k_quit.y;
	rect->quit.w = 1;
	rect->quit.h = 1;
	SDL_QueryTexture(r->f->quit, NULL, NULL, &(rect->quit.w), &(rect->quit.h));

	// SPACE resume/pause
	rect->k_pause.x = rect->filler.w + INDENT + 20;
	rect->k_pause.y = BAR_HEIGHT + INDENT + 20;
	rect->k_pause.w = 1;
	rect->k_pause.h = 1;
	SDL_QueryTexture(r->f->k_pause, NULL, NULL, &(rect->k_pause.w), &(rect->k_pause.h));
	rect->pause.x = rect->k_pause.x + rect->k_pause.w + 193;
	rect->pause.y = rect->k_pause.y;
	rect->pause.w = 1;
	rect->pause.h = 1;
	SDL_SetTextureBlendMode(r->f->pause, r->blend_p);
	SDL_QueryTexture(r->f->pause, NULL, NULL, &(rect->pause.w), &(rect->pause.h));
	rect->resume.x = rect->k_pause.x + rect->k_pause.w + 169;
	rect->resume.y = rect->k_pause.y;
	rect->resume.w = 1;
	rect->resume.h = 1;
	SDL_SetTextureBlendMode(r->f->resume, r->blend_r);
	SDL_QueryTexture(r->f->resume, NULL, NULL, &(rect->resume.w), &(rect->resume.h));

	return ;
}
void				menu_rect(t_rend *r, t_rect *rect)
{
	// размеры и координаты fillboard
	rect->filler.x = INDENT;
	rect->filler.y = INDENT;
	rect->filler.w = (SCREEN_WIDTH / 1.30) - (INDENT * 4);
	rect->filler.h = SCREEN_HEIGHT - (BAR_HEIGHT) - (INDENT * 3);
	SDL_SetTextureColorMod( r->t->m_filler, 110, 155, 85);
	SDL_SetTextureAlphaMod(r->t->m_filler, 60);

	// размеры и координаты информативного меню	
	rect->key.x = rect->filler.w + INDENT;
	rect->key.y = INDENT;
	rect->key.w = SCREEN_WIDTH - rect->filler.w - (INDENT * 2);
	rect->key.h = rect->filler.h;
	SDL_SetTextureColorMod(r->t->m_key, 213, 160, 33);
	SDL_SetTextureAlphaMod(r->t->m_key, 255);

	// размеры и координаты нижнего BAR'а
	rect->bar.x = INDENT;
	rect->bar.y = rect->filler.h + (INDENT * 2);
	rect->bar.w = INDENT + 128;
	rect->bar.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->m_bar, 44, 36, 25);
	SDL_SetTextureAlphaMod(r->t->m_bar, 255);
	rect->bar_2.x = 1408;
	rect->bar_2.y = rect->filler.h + (INDENT * 2);
	rect->bar_2.w = INDENT + 128;
	rect->bar_2.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->m_bar, 44, 36, 25);
	SDL_SetTextureAlphaMod(r->t->m_bar, 255);
	rect->bar_3.x = rect->bar.w + INDENT;
	rect->bar_3.y = rect->filler.h + (INDENT * 2);
	rect->bar_3.w = 1200;
	rect->bar_3.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->m_bar, 110, 155, 85);
	SDL_SetTextureAlphaMod(r->t->m_bar, 255);

	// полоса для BAR после/перед именем игрока
	rect->bar_bord.x = INDENT + 160;
	rect->bar_bord.y = rect->filler.h + (INDENT * 2);
	rect->bar_bord.w = 16;
	rect->bar_bord.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->m_bar, 74, 66, 55);
	rect->bar_bord_2.x = 1392;
	rect->bar_bord_2.y = rect->filler.h + (INDENT * 2);
	rect->bar_bord_2.w = 16;
	rect->bar_bord_2.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->m_bar, 74, 66, 55);
	return ;
}

// void draw_player(t_rend *r, t_rect *rect)
// {
// 	rect->p1.x = INDENT + 10;
// 	rect->p1.y = rect->filler.h + (INDENT * 2) + 10;
// 	rect->p1.w = 1;
// 	rect->p1.h = 1;
// 	SDL_QueryTexture(r->f->p1, NULL, NULL, &(rect->p1.w), &(rect->p1.h));
// 	SDL_RenderCopy(r->rend, r->f->p1, NULL, &(rect->p1));
// 	rect->p2.x = SCREEN_WIDTH - (INDENT * 2) - 130;
// 	rect->p2.y = rect->filler.h + (INDENT * 2) + 10;
// 	rect->p2.w = 1;
// 	rect->p2.h = 1;
// 	SDL_QueryTexture(r->f->p2, NULL, NULL, &(rect->p2.w), &(rect->p2.h));
// 	SDL_RenderCopy(r->rend, r->f->p2, NULL, &(rect->p2));
// 	// это отдельная функция
// 	rect->p1.x = rect->filler.w + INDENT + 20;
// 	rect->p1.y = rect->p1_name.y - INDENT - 20;
// 	rect->p1.w = 1;
// 	rect->p1.h = 1;
// 	SDL_QueryTexture(r->f->p1_, NULL, NULL, &(rect->p1.w), &(rect->p1.h));
// 	SDL_RenderCopy(r->rend, r->f->p1_, NULL, &(rect->p1));
// 	rect->p2.x = rect->filler.w + INDENT + 20;
// 	rect->p2.y = rect->p2_name.y - INDENT - 20;
// 	rect->p2.w = 1;
// 	rect->p2.h = 1;
// 	SDL_QueryTexture(r->f->p2_, NULL, NULL, &(rect->p2.w), &(rect->p2.h));
// 	SDL_RenderCopy(r->rend, r->f->p2_, NULL, &(rect->p2));
// 	return ;
// }

// void				draw_player_name(t_rend *r, t_rect *rect)
// {
// 	rect->p1_name.x = rect->filler.w + INDENT + 20;
// 	rect->p1_name.y = rect->key.h - (INDENT * 5);
// 	rect->p1_name.w = 1;
// 	rect->p1_name.h = 1;
// 	SDL_QueryTexture(r->f->p1_name, NULL, NULL, &(rect->p1_name.w), &(rect->p1_name.h));
// 	SDL_RenderCopy(r->rend, r->f->p1_name, NULL, &(rect->p1_name));
// 	rect->p2_name.x = rect->filler.w + INDENT + 20;
// 	rect->p2_name.y = rect->key.h - INDENT;
// 	rect->p2_name.w = 1;
// 	rect->p2_name.h = 1;
// 	SDL_QueryTexture(r->f->p2_name, NULL, NULL, &(rect->p2_name.w), &(rect->p2_name.h));
// 	SDL_RenderCopy(r->rend, r->f->p2_name, NULL, &(rect->p2_name));
// }

// void				draw_msg_cursor_forward(t_rend *r, t_rect *rect)
// {
// 	rect->cur.x = rect->filler.w + INDENT + 20;
// 	rect->cur.y = BAR_HEIGHT * 3 + INDENT + 28;
// 	rect->cur.w = 60;
// 	rect->cur.h = 30;
// 	SDL_RenderCopy(r->rend, r->t->cur, NULL, &(rect->cur));
// 	rect->forward.x = rect->cur.x + rect->cur.w + 195;
// 	rect->forward.y = BAR_HEIGHT * 3 + INDENT + 20;
// 	rect->forward.w = 1;
// 	rect->forward.h = 1;
// 	SDL_QueryTexture(r->f->forward, NULL, NULL, &(rect->forward.w), &(rect->forward.h));
// 	SDL_RenderCopy(r->rend, r->f->forward, NULL, &(rect->forward));
// 	return ;
// }

// void				draw_msg_cursor_back(t_rend *r, t_rect *rect)
// {
// 	rect->cur.x = rect->filler.w + INDENT + 20;
// 	rect->cur.y = BAR_HEIGHT * 2 + INDENT + 28;
// 	rect->cur.w = 60;
// 	rect->cur.h = 30;
// 	SDL_RenderCopyEx(r->rend, r->t->cur, NULL, &(rect->cur), 0.0, 0, r->flip);
// 	rect->back.x = rect->cur.x + rect->cur.w + 255;
// 	rect->back.y = BAR_HEIGHT * 2 + INDENT + 20;
// 	rect->back.w = 1;
// 	rect->back.h = 1;
// 	SDL_QueryTexture(r->f->back, NULL, NULL, &(rect->back.w), &(rect->back.h));
// 	SDL_RenderCopy(r->rend, r->f->back, NULL, &(rect->back));
// 	return ;
// }

// void				draw_msg_pause(t_rend *r, t_rect *rect)
// {
// 	rect->k_pause.x = rect->filler.w + INDENT + 20;
// 	rect->k_pause.y = BAR_HEIGHT + INDENT + 20;
// 	rect->k_pause.w = 1;
// 	rect->k_pause.h = 1;
// 	SDL_QueryTexture(r->f->k_pause, NULL, NULL, &(rect->k_pause.w), &(rect->k_pause.h));
// 	SDL_RenderCopy(r->rend, r->f->k_pause, NULL, &(rect->k_pause));
// 	rect->pause.x = rect->k_pause.x + rect->k_pause.w + 193;
// 	rect->pause.y = rect->k_pause.y;
// 	rect->pause.w = 1;
// 	rect->pause.h = 1;
// 	SDL_SetTextureBlendMode(r->f->pause, r->blend_p);
// 	SDL_QueryTexture(r->f->pause, NULL, NULL, &(rect->pause.w), &(rect->pause.h));
// 	SDL_RenderCopy(r->rend, r->f->pause, NULL, &(rect->pause));
// 	rect->resume.x = rect->k_pause.x + rect->k_pause.w + 169;
// 	rect->resume.y = rect->k_pause.y;
// 	rect->resume.w = 1;
// 	rect->resume.h = 1;
// 	SDL_SetTextureBlendMode(r->f->resume, r->blend_r);
// 	SDL_QueryTexture(r->f->resume, NULL, NULL, &(rect->resume.w), &(rect->resume.h));
// 	SDL_RenderCopy(r->rend, r->f->resume, NULL, &(rect->resume));
// 	return ;
// }

// void				draw_msg_quit(t_rend *r, t_rect *rect)
// {
// 	rect->k_quit.x = rect->filler.w + INDENT + 20;
// 	rect->k_quit.y = INDENT + 20;
// 	rect->k_quit.w = 1;
// 	rect->k_quit.h = 1;
// 	SDL_QueryTexture(r->f->k_quit, NULL, NULL, &(rect->k_quit.w), &(rect->k_quit.h));
// 	SDL_RenderCopy(r->rend, r->f->k_quit, NULL, &(rect->k_quit));
// 	rect->quit.x = rect->k_quit.x + rect->k_quit.w + 185;
// 	rect->quit.y = rect->k_quit.y;
// 	rect->quit.w = 1;
// 	rect->quit.h = 1;
// 	SDL_QueryTexture(r->f->quit, NULL, NULL, &(rect->quit.w), &(rect->quit.h));
// 	SDL_RenderCopy(r->rend, r->f->quit, NULL, &(rect->quit));
// 	return ;
// }

// void				draw_bar(t_rend *r, t_rect *rect)
// {
// 	rect->bar.x = INDENT;
// 	rect->bar.y = rect->filler.h + (INDENT * 2);
// 	rect->bar.w = SCREEN_WIDTH - (INDENT * 2);
// 	rect->bar.h = BAR_HEIGHT;
// 	SDL_SetTextureColorMod(r->t->m_bar, 0, 0, 0);
// 	SDL_SetTextureAlphaMod(r->t->m_bar, 255);
// 	SDL_RenderCopy(r->rend, r->t->m_bar, NULL, &(rect->bar));
// 	return ;
// }

// void				draw_keyboard(t_rend *r, t_rect *rect)
// {
// 	rect->key.x = rect->filler.w + INDENT;
// 	rect->key.y = INDENT;
// 	rect->key.w = SCREEN_WIDTH - rect->filler.w - (INDENT * 2);
// 	rect->key.h = rect->filler.h;
// 	SDL_SetTextureColorMod(r->t->m_key, 0, 0, 0);
// 	SDL_SetTextureAlphaMod(r->t->m_key, 255);
// 	SDL_RenderCopy(r->rend, r->t->m_key, NULL, &(rect->key));
// 	return ;
// }

// void				draw_fillboard(t_rend *r, t_rect *rect)
// {
// 	rect->filler.x = INDENT;
// 	rect->filler.y = INDENT;
// 	rect->filler.w = (SCREEN_WIDTH / 1.30) - (INDENT * 4);
// 	rect->filler.h = SCREEN_HEIGHT - (BAR_HEIGHT) - (INDENT * 3);
// 	SDL_SetTextureColorMod( r->t->m_filler, 0, 0, 0);
// 	SDL_SetTextureAlphaMod(r->t->m_filler, 120);
// 	SDL_RenderCopy(r->rend, r->t->m_filler, NULL, &(rect->filler));
// 	return ;
// }

// void				draw_bacground(t_rend *r, t_rect *rect)
// {
// 	int 			i;

// 	i = 0;
// 	while (i < SCREEN_WIDTH * SCREEN_HEIGHT)
// 	{
// 		//viewport
// 		rect->bg.x = (i % SCREEN_WIDTH);
// 		rect->bg.y = (i / SCREEN_WIDTH) * 32;
// 		rect->bg.w = 32;
// 		rect->bg.h = 32;

// 		// SDL_RenderSetViewport(rend, &topLeftViewport);
// 		//Render texture to screen
// 		SDL_RenderCopy(r->rend, r->t->bg, NULL, &(rect->bg));
// 		i = i + 32;
// 	}
// 	return ;
// }