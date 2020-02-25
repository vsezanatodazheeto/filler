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
	return;
}
void draw_player(t_rend *r, t_rect *rect)
{
	rect->p1.x = INDENT + 20;
	rect->p1.y = rect->filler.h + (INDENT * 2) + 10;
	rect->p1.w = 1;
	rect->p1.h = 1;
	SDL_QueryTexture(r->f->p1, NULL, NULL, &(rect->p1.w), &(rect->p1.h));
	SDL_RenderCopy(r->rend, r->f->p1, NULL, &(rect->p1));
	rect->p2.x = SCREEN_WIDTH - (INDENT * 2) - 110;
	rect->p2.y = rect->filler.h + (INDENT * 2) + 10;
	rect->p2.w = 1;
	rect->p2.h = 1;
	SDL_QueryTexture(r->f->p2, NULL, NULL, &(rect->p2.w), &(rect->p2.h));
	SDL_RenderCopy(r->rend, r->f->p2, NULL, &(rect->p2));
	// это отдельная функция
	rect->p1.x = rect->filler.w + INDENT + 20;
	rect->p1.y = rect->p1_name.y - INDENT - 20;
	rect->p1.w = 1;
	rect->p1.h = 1;
	SDL_QueryTexture(r->f->p1_, NULL, NULL, &(rect->p1.w), &(rect->p1.h));
	SDL_RenderCopy(r->rend, r->f->p1_, NULL, &(rect->p1));
	rect->p2.x = rect->filler.w + INDENT + 20;
	rect->p2.y = rect->p2_name.y - INDENT - 20;
	rect->p2.w = 1;
	rect->p2.h = 1;
	SDL_QueryTexture(r->f->p2_, NULL, NULL, &(rect->p2.w), &(rect->p2.h));
	SDL_RenderCopy(r->rend, r->f->p2_, NULL, &(rect->p2));
	return ;
}

void				draw_player_name(t_rend *r, t_rect *rect)
{
	rect->p1_name.x = rect->filler.w + INDENT + 20;
	rect->p1_name.y = rect->key.h - (INDENT * 5);
	rect->p1_name.w = 1;
	rect->p1_name.h = 1;
	SDL_QueryTexture(r->f->p1_name, NULL, NULL, &(rect->p1_name.w), &(rect->p1_name.h));
	SDL_RenderCopy(r->rend, r->f->p1_name, NULL, &(rect->p1_name));
	rect->p2_name.x = rect->filler.w + INDENT + 20;
	rect->p2_name.y = rect->key.h - INDENT;
	rect->p2_name.w = 1;
	rect->p2_name.h = 1;
	SDL_QueryTexture(r->f->p2_name, NULL, NULL, &(rect->p2_name.w), &(rect->p2_name.h));
	SDL_RenderCopy(r->rend, r->f->p2_name, NULL, &(rect->p2_name));
}

void				draw_msg_cursor_forward(t_rend *r, t_rect *rect)
{
	rect->cur.x = rect->filler.w + INDENT + 20;
	rect->cur.y = BAR_HEIGHT * 3 + INDENT + 28;
	rect->cur.w = 60;
	rect->cur.h = 30;
	SDL_RenderCopy(r->rend, r->t->cur, NULL, &(rect->cur));
	SDL_SetTextureColorMod( r->t->cur, 255, 255, 255);
	rect->forward.x = rect->cur.x + rect->cur.w + 195;
	rect->forward.y = BAR_HEIGHT * 3 + INDENT + 20;
	rect->forward.w = 1;
	rect->forward.h = 1;
	SDL_QueryTexture(r->f->forward, NULL, NULL, &(rect->forward.w), &(rect->forward.h));
	SDL_RenderCopy(r->rend, r->f->forward, NULL, &(rect->forward));
	return ;
}

void				draw_msg_cursor_back(t_rend *r, t_rect *rect)
{
	rect->cur_2.x = rect->filler.w + INDENT + 20;
	rect->cur_2.y = BAR_HEIGHT * 2 + INDENT + 28;
	rect->cur_2.w = 60;
	rect->cur_2.h = 30;
	SDL_RenderCopyEx(r->rend, r->t->cur_2, NULL, &(rect->cur_2), 0.0, 0, r->flip);
	SDL_SetTextureColorMod( r->t->cur_2, 255, 255, 255);
	rect->back.x = rect->cur.x + rect->cur.w + 255;
	rect->back.y = BAR_HEIGHT * 2 + INDENT + 20;
	rect->back.w = 1;
	rect->back.h = 1;
	SDL_QueryTexture(r->f->back, NULL, NULL, &(rect->back.w), &(rect->back.h));
	SDL_RenderCopy(r->rend, r->f->back, NULL, &(rect->back));
	return ;
}

void				draw_msg_pause(t_rend *r, t_rect *rect)
{
	SDL_RenderCopy(r->rend, r->f->k_pause, NULL, &(rect->k_pause));
	SDL_RenderCopy(r->rend, r->f->pause, NULL, &(rect->pause));
	SDL_RenderCopy(r->rend, r->f->resume, NULL, &(rect->resume));
	return ;
}

void				draw_msg_quit(t_rend *r, t_rect *rect)
{
	SDL_RenderCopy(r->rend, r->f->k_quit, NULL, &(rect->k_quit));
	SDL_RenderCopy(r->rend, r->f->quit, NULL, &(rect->quit));
	return ;
}

void				draw_bar_bord(t_rend *r, t_rect *rect)
{
	SDL_RenderCopy(r->rend, r->t->m_bar, NULL, &(rect->bar_bord));
	SDL_RenderCopy(r->rend, r->t->m_bar, NULL, &(rect->bar_bord_2));
	return ;
}

void				draw_bar(t_rend *r, t_rect *rect)
{
	// left bar
	SDL_RenderCopy(r->rend, r->t->m_bar, NULL, &(rect->bar));
	// right bar
	SDL_RenderCopy(r->rend, r->t->m_bar, NULL, &(rect->bar_2));
	// centered bar
	SDL_RenderCopy(r->rend, r->t->m_bar, NULL, &(rect->bar_3));
	return ;
}

void				draw_keyboard(t_rend *r, t_rect *rect)
{
	SDL_RenderCopy(r->rend, r->t->m_key, NULL, &(rect->key));
	return ;
}

void				draw_fillboard(t_rend *r, t_rect *rect)
{
	SDL_RenderCopy(r->rend, r->t->m_filler, NULL, &(rect->filler));
	return ;
}

void				draw_bacground(t_rend *r, t_rect *rect)
{
	int 			i;
	int				n;

	i = 0;
	n = 0;
	while (i < SCREEN_WIDTH * SCREEN_HEIGHT)
	{
		rect->bg.x = (n % SCREEN_WIDTH) + keker;
		rect->bg.y = (n / SCREEN_WIDTH) * 32;
		rect->bg.w = 32;
		rect->bg.h = 32;
		// if (rect->bg.x >= SCREEN_WIDTH)
		// {	
		// 	ft_printf("heh\n");
		// 	n = 0;
		// 	keker = 0;
		// 	rect->bg.x = (n % SCREEN_WIDTH) + keker;
		// }
		// SDL_RenderSetViewport(rend, &topLeftViewport);
		//Render texture to screen
		SDL_SetTextureColorMod( r->t->bg, 75, 66, 55);
		SDL_RenderCopy(r->rend, r->t->bg, NULL, &(rect->bg));
		i = i + INDENT;
		n = n + INDENT;
	}
	// keker++;
	return ;
}