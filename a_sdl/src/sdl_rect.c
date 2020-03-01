/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/01 22:28:44 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

extern int mapsize; // width * height for filler field

void				field_rect(t_rend *r, t_rect *rect, t_f *lst)
{
	// размеры квадрата ASIANS
	rect->asian.w = rect->filler.w / lst->m->width;
	rect->asian.h = rect->filler.h / lst->m->height;
	// размеры квадрата COVID
	rect->cv19.w = rect->filler.w / lst->m->width;
	rect->cv19.h = rect->filler.h / lst->m->height;
	// размеры и координаты земли EARTH
	rect->earth.w = rect->asian.w * lst->m->width;
	rect->earth.h = rect->asian.h * lst->m->height;
	rect->earth.x = INDENT + rect->filler.w / 2 - rect->earth.w / 2;
	rect->earth.y = INDENT + rect->filler.h / 2 - rect->earth.h / 2;
	SDL_SetTextureColorMod(r->t->earth, 100, 200, 200);
	SDL_SetTextureAlphaMod(r->t->earth, 255);
	// размеры и координаты сетки  GRID
	rect->earth_grid.x = INDENT + rect->filler.w / 2 - rect->earth.w / 2;
	rect->earth_grid.y = INDENT + rect->filler.h / 2 - rect->earth.h / 2;
	rect->earth_grid.w = 1;
	rect->earth_grid.h = 1;
	SDL_SetTextureColorMod(r->t->earth_grid, 44, 36, 25);
	SDL_SetTextureAlphaMod(r->t->earth_grid, 255);
}

void				word_rect(t_rend *r, t_rect *rect)
{
	// CMD + W
	rect->k_quit.x = rect->filler.w + INDENT + 20;
	rect->k_quit.y = INDENT + 20;
	rect->k_quit.w = 1;
	rect->k_quit.h = 1;
	SDL_QueryTexture(r->f->k_quit, NULL, NULL, &(rect->k_quit.w), &(rect->k_quit.h));
	// QUIT
	rect->quit.x = rect->k_quit.x + rect->k_quit.w + 185;
	rect->quit.y = rect->k_quit.y;
	rect->quit.w = 1;
	rect->quit.h = 1;
	SDL_QueryTexture(r->f->quit, NULL, NULL, &(rect->quit.w), &(rect->quit.h));

	// SPACE
	rect->k_pause.x = rect->filler.w + INDENT + 20;
	rect->k_pause.y = BAR_HEIGHT + INDENT + 20;
	rect->k_pause.w = 1;
	rect->k_pause.h = 1;
	SDL_QueryTexture(r->f->k_pause, NULL, NULL, &(rect->k_pause.w), &(rect->k_pause.h));
	// PAUSE
	rect->pause.x = rect->k_pause.x + rect->k_pause.w + 193;
	rect->pause.y = rect->k_pause.y;
	rect->pause.w = 1;
	rect->pause.h = 1;
	SDL_QueryTexture(r->f->pause, NULL, NULL, &(rect->pause.w), &(rect->pause.h));
	// RESUME
	rect->resume.x = rect->k_pause.x + rect->k_pause.w + 169;
	rect->resume.y = rect->k_pause.y;
	rect->resume.w = 1;
	rect->resume.h = 1;
	SDL_QueryTexture(r->f->resume, NULL, NULL, &(rect->resume.w), &(rect->resume.h));

	// <----- CURSOR BACK
	rect->cur_back.x = rect->filler.w + INDENT + 8;
	rect->cur_back.y = BAR_HEIGHT * 2 + INDENT + 10;
	rect->cur_back.w = 60;
	rect->cur_back.h = 30;
	SDL_QueryTexture(r->t->cur_back, NULL, NULL, &(rect->cur_back.w), &(rect->cur_back.h));
	// -----> CURSOR FORWARD
	rect->cur_forward.x = rect->filler.w + INDENT + 60;
	rect->cur_forward.y = rect->cur_back.y;
	rect->cur_forward.w = 60;
	rect->cur_forward.h = 30;	
	SDL_QueryTexture(r->t->cur_forward, NULL, NULL, &(rect->cur_forward.w), &(rect->cur_forward.h));
	// BACK_FORWARD
	rect->back_forward.x = rect->cur_forward.x + rect->cur_forward.w + 48;
	rect->back_forward.y = BAR_HEIGHT * 2 + INDENT + 20;
	rect->back_forward.w = 1;
	rect->back_forward.h = 1;
	SDL_QueryTexture(r->f->back_forward, NULL, NULL, &(rect->back_forward.w), &(rect->back_forward.h));

	// /\ CURSOR UP
	rect->cur_up.x = rect->filler.w + INDENT + 14;
	rect->cur_up.y = BAR_HEIGHT * 2 + (INDENT * 3) + 10;
	rect->cur_up.w = 60;
	rect->cur_up.h = 30;
	// \/ CURSOR DOWN
	rect->cur_down.x = rect->cur_up.x + 40;
	rect->cur_down.y = BAR_HEIGHT * 2 + INDENT * 3 + 10;
	rect->cur_down.w = 60;
	rect->cur_down.h = 30;
	// SPEED
	rect->speed.x = rect->cur_down. x + 190;
	rect->speed.y = BAR_HEIGHT * 3 + INDENT + 20;
	rect->speed.w = 1;
	rect->speed.h = 1;
	SDL_QueryTexture(r->f->speed, NULL, NULL, &(rect->speed.w), &(rect->speed.h));
	// SPEEDRATE
	rect->speedrate.x = rect->cur_down. x + 308;
	rect->speedrate.y = BAR_HEIGHT * 3 + INDENT + 26;
	rect->speedrate.w = 1;
	rect->speedrate.h = 1;
	SDL_QueryTexture(r->f->speedrate, NULL, NULL, &(rect->speedrate.w), &(rect->speedrate.h));

	//NAME OF PLAYER_1 that will play for ASIANS
	rect->p1_name.x = rect->filler.w + INDENT + 20;
	rect->p1_name.y = rect->key.h - (INDENT * 5 - 8);
	rect->p1_name.w = 1;
	rect->p1_name.h = 1;
	SDL_QueryTexture(r->f->p1_name, NULL, NULL, &(rect->p1_name.w), &(rect->p1_name.h));
	//NAME OF PLAYER_2 that will play for COVID
	rect->p2_name.x = rect->filler.w + INDENT + 20;
	rect->p2_name.y = rect->key.h - INDENT;
	rect->p2_name.w = 1;
	rect->p2_name.h = 1;
	SDL_QueryTexture(r->f->p2_name, NULL, NULL, &(rect->p2_name.w), &(rect->p2_name.h));
	//PLAYER_3 that will play for EARTH
	rect->p3_name.x = rect->filler.w + INDENT + 20;
	rect->p3_name.y = rect->key.h - (INDENT * 8 + 14);
	rect->p3_name.w = 1;
	rect->p3_name.h = 1;
	SDL_QueryTexture(r->f->p3_name, NULL, NULL, &(rect->p3_name.w), &(rect->p3_name.h));

	//ASIANS :
	rect->p1_.x = rect->filler.w + INDENT + 20;
	rect->p1_.y = rect->p1_name.y - INDENT - 20;
	rect->p1_.w = 1;
	rect->p1_.h = 1;
	SDL_QueryTexture(r->f->p1_, NULL, NULL, &(rect->p1_.w), &(rect->p1_.h));
	// COVID19 :
	rect->p2_.x = rect->filler.w + INDENT + 20;
	rect->p2_.y = rect->p2_name.y - INDENT - 20;
	rect->p2_.w = 1;
	rect->p2_.h = 1;
	SDL_QueryTexture(r->f->p2_, NULL, NULL, &(rect->p2_.w), &(rect->p2_.h));
	// EARTH:
	rect->p3_.x = rect->filler.w + INDENT + 20;
	rect->p3_.y = rect->p3_name.y - INDENT - 24;
	rect->p3_.w = 1;
	rect->p3_.h = 1;
	SDL_QueryTexture(r->f->p3_, NULL, NULL, &(rect->p3_.w), &(rect->p3_.h));
	return ;
}

void				menu_rect(t_rend *r, t_rect *rect, t_f *lst)
{
	// размеры и координаты fillboard
	rect->filler.x = INDENT;
	rect->filler.y = INDENT;
	rect->filler.w = (SCREEN_WIDTH / 1.30) - (INDENT * 4);
	rect->filler.h = SCREEN_HEIGHT - (BAR_HEIGHT) - (INDENT * 3);
	SDL_SetTextureColorMod( r->t->m_filler, 40, 40, 40);
	SDL_SetTextureAlphaMod(r->t->m_filler, 150);

	// размеры и координаты KEYS MENU
	rect->key.x = rect->filler.w + INDENT;
	rect->key.y = INDENT;
	rect->key.w = SCREEN_WIDTH - rect->filler.w - (INDENT * 2);
	rect->key.h = rect->filler.h;
	SDL_SetTextureColorMod(r->t->m_key, 15, 25, 50);
	SDL_SetTextureAlphaMod(r->t->m_key, 255);

	

	// размеры и координаты нижнего BAR
	// left
	rect->bar_left.x = INDENT;
	rect->bar_left.y = rect->filler.h + (INDENT * 2);
	rect->bar_left.w = INDENT + 128;
	rect->bar_left.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->m_bar_left, 40, 40, 40);
	// right
	rect->bar_right.x = 1408;
	rect->bar_right.y = rect->filler.h + (INDENT * 2);
	rect->bar_right.w = INDENT + 128;
	rect->bar_right.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->m_bar_right, 40, 40, 40);
	// center
	rect->bar_center.x = rect->bar_left.w + INDENT;
	rect->bar_center.y = rect->filler.h + (INDENT * 2);
	rect->bar_center.w = 1200;
	rect->bar_center.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->m_bar_center, 100, 200, 200);
	SDL_SetTextureAlphaMod(r->t->m_bar_center, 255);

	// полоса для BAR после/перед именем игрока
	rect->bar_bord.x = INDENT + 160;
	rect->bar_bord.y = rect->filler.h + (INDENT * 2);
	rect->bar_bord.w = 16;
	rect->bar_bord.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->m_bar_delimiter, 115, 115, 115);
	rect->bar_bord_2.x = 1392;
	rect->bar_bord_2.y = rect->filler.h + (INDENT * 2);
	rect->bar_bord_2.w = 16;
	rect->bar_bord_2.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->m_bar_delimiter, 115, 115, 115);

	// PROGRESS BAR P1
	rect->bar_center_p1.x = rect->bar_left.w + INDENT;
	rect->bar_center_p1.y = rect->filler.h + (INDENT * 2);
	rect->bar_center_p1.w = 1200 * (lst->ally_cnt * 100 / mapsize) / 100;
	rect->bar_center_p1.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->m_bar_center_p1, 194, 1, 20);
	// PROGRESS BAR P2
	rect->bar_center_p2.x = 1408 - (1200 * (lst->enemy_cnt * 100 / mapsize) / 100);
	rect->bar_center_p2.y = rect->filler.h + (INDENT * 2);
	rect->bar_center_p2.w = 1200 * (lst->enemy_cnt * 100 / mapsize) / 100;
	rect->bar_center_p2.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->m_bar_center_p2, 255, 220, 55);

	// BAR NAMES
	// asians
	rect->p1.x = INDENT + 20;
	rect->p1.y = rect->filler.h + (INDENT * 2) + 10;
	rect->p1.w = 1;
	rect->p1.h = 1;
	SDL_QueryTexture(r->f->p1, NULL, NULL, &(rect->p1.w), &(rect->p1.h));
	// covid19
	SDL_RenderCopy(r->rend, r->f->p2_, NULL, &(rect->p2));
	rect->p2.x = SCREEN_WIDTH - (INDENT * 2) - 110;
	rect->p2.y = rect->filler.h + (INDENT * 2) + 10;
	rect->p2.w = 1;
	rect->p2.h = 1;
	SDL_QueryTexture(r->f->p2, NULL, NULL, &(rect->p2.w), &(rect->p2.h));
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