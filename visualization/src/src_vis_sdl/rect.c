/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:11:34 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/04 16:11:36 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vis_filler.h"
#include "../../include/vis_sdl.h"

void				rect_field(t_rend *r, t_rect *rect, t_f *lst)
{
	// размеры квадрата ASIANS
	rect->asian.w = rect->fillboard.w / lst->m->width;
	rect->asian.h = rect->fillboard.h / lst->m->height;
	(rect->asian.w > rect->asian.h) ? (rect->asian.w = rect->asian.h) : (rect->asian.h = rect->asian.w);
	SDL_SetTextureColorMod(r->t->asian, 194, 1, 20);
	// размеры квадрата COVID
	rect->cv19.w = rect->asian.w;
	rect->cv19.h = rect->asian.h;
	SDL_SetTextureColorMod(r->t->cv19, 255, 220, 55);
	// размеры и координаты земли FIGURE
	rect->figure.w = rect->asian.w;
	rect->figure.h = rect->asian.h;
	// размеры и координаты земли EARTH
	rect->earth.w = rect->asian.w * lst->m->width;
	rect->earth.h = rect->asian.h * lst->m->height;
	rect->earth.x = INDENT + rect->fillboard.w / 2 - rect->earth.w / 2;
	rect->earth.y = INDENT + rect->fillboard.h / 2 - rect->earth.h / 2;
	SDL_SetTextureColorMod(r->t->earth, 100, 200, 200);
	SDL_SetTextureAlphaMod(r->t->earth, 255);
	// размеры и координаты сетки  GRID в отрисовке
	SDL_SetTextureColorMod(r->t->earth_grid, 40, 40, 40);
	SDL_SetTextureAlphaMod(r->t->earth_grid, 255);
}

void				rect_message(t_rend *r, t_rect *rect)
{
	// CMD + W
	rect->cmdw.x = rect->fillboard.w + INDENT + 20;
	rect->cmdw.y = INDENT + 20;
	rect->cmdw.w = 1;
	rect->cmdw.h = 1;
	SDL_QueryTexture(r->f->cmdw, NULL, NULL, &(rect->cmdw.w), &(rect->cmdw.h));
	// QUIT
	rect->quit.x = rect->cmdw.x + rect->cmdw.w + 274;
	rect->quit.y = rect->cmdw.y;
	rect->quit.w = 1;
	rect->quit.h = 1;
	SDL_QueryTexture(r->f->quit, NULL, NULL, &(rect->quit.w), &(rect->quit.h));

	// SPACE
	rect->space.x = rect->fillboard.w + INDENT + 20;
	rect->space.y = BAR_HEIGHT + INDENT + 20;
	rect->space.w = 1;
	rect->space.h = 1;
	SDL_QueryTexture(r->f->space, NULL, NULL, &(rect->space.w), &(rect->space.h));
	// PAUSE
	rect->pause.x = rect->space.x + rect->space.w + 193;
	rect->pause.y = rect->space.y;
	rect->pause.w = 1;
	rect->pause.h = 1;
	SDL_QueryTexture(r->f->pause, NULL, NULL, &(rect->pause.w), &(rect->pause.h));
	// RESUME
	rect->resume.x = rect->space.x + rect->space.w + 169;
	rect->resume.y = rect->space.y;
	rect->resume.w = 1;
	rect->resume.h = 1;
	SDL_QueryTexture(r->f->resume, NULL, NULL, &(rect->resume.w), &(rect->resume.h));

	//R
	rect->re.x = rect->fillboard.w + INDENT + 20;
	rect->re.y = rect->space.y + INDENT * 2;
	rect->re.w = 1;
	rect->re.h = 1;
	SDL_QueryTexture(r->f->re, NULL, NULL, &(rect->re.w), &(rect->re.h));
	//REPLAY
	rect->replay.x = rect->re.x + rect->re.w + INDENT * 8.2;
	rect->replay.y = rect->space.y + INDENT * 2;
	rect->replay.w = 1;
	rect->replay.h = 1;
	SDL_QueryTexture(r->f->replay, NULL, NULL, &(rect->replay.w), &(rect->replay.h));

	// <----- CURSOR BACK
	rect->cur_back.x = rect->fillboard.w + INDENT + 8;
	rect->cur_back.y = rect->re.y + INDENT * 1.8;
	rect->cur_back.w = 60;
	rect->cur_back.h = 30;
	SDL_QueryTexture(r->t->cur_back, NULL, NULL, &(rect->cur_back.w), &(rect->cur_back.h));
	// -----> CURSOR FORWARD
	rect->cur_forward.x = rect->fillboard.w + INDENT + 60;
	rect->cur_forward.y = rect->cur_back.y;
	rect->cur_forward.w = 60;
	rect->cur_forward.h = 30;
	SDL_QueryTexture(r->t->cur_forward, NULL, NULL, &(rect->cur_forward.w), &(rect->cur_forward.h));
	// BACK_FORWARD
	rect->back_forward.x = rect->cur_forward.x + rect->cur_forward.w + 42;
	rect->back_forward.y = rect->cur_back.y + INDENT / 2.6;
	rect->back_forward.w = 1;
	rect->back_forward.h = 1;
	SDL_QueryTexture(r->f->back_forward, NULL, NULL, &(rect->back_forward.w), &(rect->back_forward.h));

	// /\ CURSOR UP
	rect->cur_up.x = rect->fillboard.w + INDENT + 14;
	rect->cur_up.y = rect->cur_back.y + INDENT * 2.2;
	rect->cur_up.w = 60;
	rect->cur_up.h = 30;
	SDL_QueryTexture(r->t->cur_up, NULL, NULL, &(rect->cur_up.w), &(rect->cur_up.h));
	// \/ CURSOR DOWN
	rect->cur_down.x = rect->cur_up.x + 40;
	rect->cur_down.y = rect->cur_up.y;
	rect->cur_down.w = 60;
	rect->cur_down.h = 30;
	SDL_QueryTexture(r->t->cur_down, NULL, NULL, &(rect->cur_down.w), &(rect->cur_down.h));
	// SPEED
	rect->speed.x = rect->cur_down.x + 190;
	rect->speed.y = rect->cur_down.y + INDENT / 4;
	rect->speed.w = 1;
	rect->speed.h = 1;
	SDL_QueryTexture(r->f->speed, NULL, NULL, &(rect->speed.w), &(rect->speed.h));
	// SPEEDRATE
	rect->speedrate.x = rect->cur_down.x + 306;
	rect->speedrate.y = rect->cur_down.y + INDENT / 2.2;
	rect->speedrate.w = 1;
	rect->speedrate.h = 1;
	SDL_QueryTexture(r->f->speedrate, NULL, NULL, &(rect->speedrate.w), &(rect->speedrate.h));

	//NAME OF PLAYER_1 that will play for ASIANS
	rect->p1_name.x = rect->fillboard.w + INDENT + 20;
	rect->p1_name.y = rect->keymenu.h - (INDENT * 5 - 8);
	rect->p1_name.w = 1;
	rect->p1_name.h = 1;
	SDL_QueryTexture(r->f->p1_name, NULL, NULL, &(rect->p1_name.w), &(rect->p1_name.h));
	//NAME OF PLAYER_2 that will play for COVID
	rect->p2_name.x = rect->fillboard.w + INDENT + 20;
	rect->p2_name.y = rect->keymenu.h - INDENT;
	rect->p2_name.w = 1;
	rect->p2_name.h = 1;
	SDL_QueryTexture(r->f->p2_name, NULL, NULL, &(rect->p2_name.w), &(rect->p2_name.h));
	//PLAYER_3 that will play for EARTH
	rect->p3_name.x = rect->fillboard.w + INDENT + 20;
	rect->p3_name.y = rect->keymenu.h - (INDENT * 8 + 14);
	rect->p3_name.w = 1;
	rect->p3_name.h = 1;
	SDL_QueryTexture(r->f->p3_name, NULL, NULL, &(rect->p3_name.w), &(rect->p3_name.h));

	//ASIANS :
	rect->p1_keymenu.x = rect->fillboard.w + INDENT + 20;
	rect->p1_keymenu.y = rect->p1_name.y - INDENT - 20;
	rect->p1_keymenu.w = 1;
	rect->p1_keymenu.h = 1;
	SDL_QueryTexture(r->f->p1_keymenu, NULL, NULL, &(rect->p1_keymenu.w), &(rect->p1_keymenu.h));
	// COVID19 :
	rect->p2_keymenu.x = rect->fillboard.w + INDENT + 20;
	rect->p2_keymenu.y = rect->p2_name.y - INDENT - 20;
	rect->p2_keymenu.w = 1;
	rect->p2_keymenu.h = 1;
	SDL_QueryTexture(r->f->p2_keymenu, NULL, NULL, &(rect->p2_keymenu.w), &(rect->p2_keymenu.h));
	// EARTH :
	rect->p3_keymenu.x = rect->fillboard.w + INDENT + 20;
	rect->p3_keymenu.y = rect->p3_name.y - INDENT - 24;
	rect->p3_keymenu.w = 1;
	rect->p3_keymenu.h = 1;
	SDL_QueryTexture(r->f->p3_keymenu, NULL, NULL, &(rect->p3_keymenu.w), &(rect->p3_keymenu.h));
	return ;
}

void				rect_bar(t_rend *r, t_rect *rect, t_f *lst)
{
	// LEFT BAR
	rect->bar_left.x = INDENT;
	rect->bar_left.y = rect->fillboard.h + (INDENT * 2);
	rect->bar_left.w = INDENT + 128;
	rect->bar_left.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->bar_left, 40, 40, 40);
	// RIGHT BAR
	rect->bar_right.x = 1408;
	rect->bar_right.y = rect->fillboard.h + (INDENT * 2);
	rect->bar_right.w = INDENT + 128;
	rect->bar_right.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->bar_right, 40, 40, 40);
	// CENTER BAR
	rect->bar_center.x = rect->bar_left.w + INDENT;
	rect->bar_center.y = rect->fillboard.h + (INDENT * 2);
	rect->bar_center.w = 1200;
	rect->bar_center.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->bar_center, 100, 200, 200);
	SDL_SetTextureAlphaMod(r->t->bar_center, 255);

	// LEFT/RIGHT DELIMITER BAR
	rect->bar_delimiter.x = INDENT + 160;
	rect->bar_delimiter.y = rect->fillboard.h + (INDENT * 2);
	rect->bar_delimiter.w = INDENT / 2;
	rect->bar_delimiter.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->bar_delimiter, 115, 115, 115);
	rect->bar_delimiter_2.x = 1392;
	rect->bar_delimiter_2.y = rect->fillboard.h + (INDENT * 2);
	rect->bar_delimiter_2.w = INDENT / 2;
	rect->bar_delimiter_2.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->bar_delimiter, 115, 115, 115);

	// PROGRESS BAR P1
	rect->bar_center_p1.x = rect->bar_left.w + INDENT;
	rect->bar_center_p1.y = rect->fillboard.h + (INDENT * 2);
	rect->bar_center_p1.w = 1200 * (lst->ally_cnt * 100 / r->event->mapsize) / 100;
	rect->bar_center_p1.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->bar_center_p1, 194, 1, 20);
	// PROGRESS BAR P2
	rect->bar_center_p2.x = 1408 - (1200 * (lst->enemy_cnt * 100 / r->event->mapsize) / 100);
	rect->bar_center_p2.y = rect->fillboard.h + (INDENT * 2);
	rect->bar_center_p2.w = 1200 * (lst->enemy_cnt * 100 / r->event->mapsize) / 100;
	rect->bar_center_p2.h = BAR_HEIGHT;
	SDL_SetTextureColorMod(r->t->bar_center_p2, 255, 220, 55);

	// NAME BAR P1
	rect->p1_bar.x = INDENT + 20;
	rect->p1_bar.y = rect->fillboard.h + (INDENT * 2) + 10;
	rect->p1_bar.w = 1;
	rect->p1_bar.h = 1;
	SDL_QueryTexture(r->f->p1_bar, NULL, NULL, &(rect->p1_bar.w), &(rect->p1_bar.h));
	// NAME BAR P2
	rect->p2_bar.x = SCREEN_WIDTH - (INDENT * 2) - 110;
	rect->p2_bar.y = rect->fillboard.h + (INDENT * 2) + 10;
	rect->p2_bar.w = 1;
	rect->p2_bar.h = 1;
	SDL_QueryTexture(r->f->p2_bar, NULL, NULL, &(rect->p2_bar.w), &(rect->p2_bar.h));
	return ;
}

void				rect_menu(t_rend *r, t_rect *rect)
{
	// FILLBOARD
	rect->fillboard.x = INDENT;
	rect->fillboard.y = INDENT;
	rect->fillboard.w = (SCREEN_WIDTH / 1.30) - (INDENT * 4);
	rect->fillboard.h = SCREEN_HEIGHT - (BAR_HEIGHT) - (INDENT * 3);
	SDL_SetTextureColorMod(r->t->fillboard, 40, 40, 40);
	SDL_SetTextureAlphaMod(r->t->fillboard, 150);

	// KEYMENU
	rect->keymenu.x = rect->fillboard.w + INDENT;
	rect->keymenu.y = INDENT;
	rect->keymenu.w = SCREEN_WIDTH - rect->fillboard.w - (INDENT * 2);
	rect->keymenu.h = rect->fillboard.h;
	SDL_SetTextureColorMod(r->t->keymenu, 15, 25, 50);
	SDL_SetTextureAlphaMod(r->t->keymenu, 255);
	return ;
}
