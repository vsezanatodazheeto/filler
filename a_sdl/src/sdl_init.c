/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/18 13:04:26 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler_v.h"

int				quit(SDL_Window **win, t_rend *r)
{
	// TEXTURES
	SDL_DestroyTexture(r->t->bg);
	SDL_DestroyTexture(r->t->cur);
	SDL_DestroyTexture(r->t->m_filler);
	SDL_DestroyTexture(r->t->m_key);
	SDL_DestroyTexture(r->t->m_bar);
	// FONTS
	SDL_DestroyTexture(r->f->k_quit);
	SDL_DestroyTexture(r->f->quit);
	SDL_DestroyTexture(r->f->k_pause);
	SDL_DestroyTexture(r->f->pause);
	SDL_DestroyTexture(r->f->resume);
	SDL_DestroyTexture(r->f->back);
	SDL_DestroyTexture(r->f->forward);
	SDL_DestroyTexture(r->f->p1);
	SDL_DestroyTexture(r->f->p2);
	// RENDER
	SDL_DestroyRenderer(r->rend);
	// WINDOW
	SDL_DestroyWindow(*win);
	*win = NULL;
    SDL_Quit();
    IMG_Quit();
    return 0;
}

void				create_font(t_rend *r, t_players *player)
{
	r->f->k_quit = load_font(&(r->rend), K_QUIT, FONT_SIZE);
	r->f->quit = load_font(&(r->rend), QUIT, FONT_SIZE_2);
    r->f->k_pause = load_font(&(r->rend), K_PAUSE, FONT_SIZE);
    r->f->pause = load_font(&(r->rend), PAUSE, FONT_SIZE_2);
    r->f->resume = load_font(&(r->rend), RESUME, FONT_SIZE_2);
    r->f->back = load_font(&(r->rend), F_BACK, FONT_SIZE_2);
    r->f->forward = load_font(&(r->rend), F_FORWARD, FONT_SIZE_2);
	r->f->p1 = load_font(&(r->rend), player->p1, FONT_SIZE);
	r->f->p2 = load_font(&(r->rend), player->p2, FONT_SIZE);
    // f->mv_fw = load_font(&(*rend), F_FORW);
    // r->f->arr_bk = load_texture(&(r->rend), "resources/arrow.png");
	return ;
}

int				create_textur(t_rend *r)
{
    if(!(r->t->bg = load_texture(&(r->rend), "resources/checker.png")))
		return (1);
    if(!(r->t->cur = load_texture(&(r->rend), "resources/cursor.png")))
		return (1);
    if(!(r->t->m_key = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->m_filler = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->m_bar = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
    return (0);
}

int				create(SDL_Window **win, t_rend *r, t_players *player)
{
	Uint32 render_flags;

	render_flags = SDL_RENDERER_ACCELERATED;
    if (!(*win = SDL_CreateWindow("Huiler",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									SCREEN_WIDTH, SCREEN_HEIGHT,
									SDL_WINDOW_SHOWN)))
		return (1);
	if (!(r->rend = SDL_CreateRenderer(*win, -1, render_flags)))
		return (1);
	else
		SDL_SetRenderDrawColor(r->rend, 255, 255, 255, 255);
	// CREATE RENDER DATA
	create_font(r, player);
	create_textur(r);
	r->player = player;
	ft_printf("%d\n", r->player->p2_len);
    return (0);
}

void			init_t_rend(t_rend *r, t_textur *t, t_font *f, t_rect *rect)
{
	// rect->p_bg = NULL;
    // rect->p_key = NULL;
    // rect->p_filler = NULL;
    // rect->p_bar = NULL;
    // rect->p_qt = NULL;
    // rect->p_ps = NULL;
    // rect->p_arrb = NULL;
    // rect->p_mvb = NULL;
	f->k_quit = NULL;
	f->quit = NULL;
	f->k_pause = NULL;
	f->pause = NULL;
	f->resume = NULL;
	f->back = NULL;
	f->forward = NULL;
	f->p1 = NULL;
	f->p2 = NULL;
	t->bg = NULL;
	t->cur = NULL;
    t->m_key = NULL;
    t->m_filler = NULL;
    t->m_bar = NULL;
	r->flip = SDL_FLIP_HORIZONTAL;
	r->blend_p = BLEND_OFF;
	r->blend_r = BLEND_ON;
	r->rend = NULL;
	r->t = t;
	r->f = f;
	r->rect = rect;
}

int				init_lib()
{
	//Initialize PNG loading
	int flags;

	flags = IMG_INIT_PNG;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (1);
	if (!(IMG_Init(flags) & flags))
		return (1);
	if (TTF_Init() != 0)
		return (1);
	//Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		return (1);
	return (0);
}