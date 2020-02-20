/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/20 18:21:11 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

int				quit(SDL_Window **win, t_rend *r)
{
	// TEXTURES
	SDL_DestroyTexture(r->t->bg);
	SDL_DestroyTexture(r->t->cur);
	SDL_DestroyTexture(r->t->m_filler);
	SDL_DestroyTexture(r->t->m_key);
	SDL_DestroyTexture(r->t->m_bar);
	SDL_DestroyTexture(r->t->asian);
	SDL_DestroyTexture(r->t->cv_19);
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
	SDL_DestroyTexture(r->f->p1_);
	SDL_DestroyTexture(r->f->p2_);
	SDL_DestroyTexture(r->f->p1_name);
	SDL_DestroyTexture(r->f->p2_name);
	// RENDER
	SDL_DestroyRenderer(r->rend);
	// WINDOW
	SDL_DestroyWindow(*win);
	*win = NULL;
    SDL_Quit();
    IMG_Quit();
    return 0;
}

void				create_font(t_rend *r)
{
	r->f->k_quit = load_font(&(r->rend), K_QUIT, FONT_SIZE);
	r->f->quit = load_font(&(r->rend), QUIT, FONT_SIZE);
    r->f->k_pause = load_font(&(r->rend), K_PAUSE, FONT_SIZE);
    r->f->pause = load_font(&(r->rend), PAUSE, FONT_SIZE);
    r->f->resume = load_font(&(r->rend), RESUME, FONT_SIZE);
    r->f->back = load_font(&(r->rend), F_BACK, FONT_SIZE);
    r->f->forward = load_font(&(r->rend), F_FORWARD, FONT_SIZE);
	r->f->p1 = load_font(&(r->rend), K_P1_NAME, FONT_SIZE);
	r->f->p2 = load_font(&(r->rend), K_P2_NAME, FONT_SIZE);
	r->f->p1_ = load_font(&(r->rend), K_P1_NAME_, FONT_SIZE);
	r->f->p2_ = load_font(&(r->rend), K_P2_NAME_, FONT_SIZE);
    r->f->p1_name = load_font(&(r->rend), r->player->p1, FONT_SIZE);
    r->f->p2_name = load_font(&(r->rend), r->player->p2, FONT_SIZE);
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
	if(!(r->t->asian = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->cv_19 = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
    return (0);
}

int				create(SDL_Window **win, t_rend *r, t_player *player)
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
	r->player = player;
	create_font(r);
	create_textur(r);
    return (0);
}

void			init_t_rend(t_rend *r, t_textur *t, t_font *f, t_rect *rect)
{
	// rect->p_bg = 0;
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
	f->p1_ = NULL;
	f->p2_ = NULL;
	f->p1_name = NULL;
	f->p2_name = NULL;
	t->bg = NULL;
	t->cur = NULL;
    t->m_key = NULL;
    t->m_filler = NULL;
    t->m_bar = NULL;
	t->asian = NULL;
	t->cv_19 = NULL;
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