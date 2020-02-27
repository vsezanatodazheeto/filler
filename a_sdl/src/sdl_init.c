/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/27 17:26:18 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

int				quit(SDL_Window **win, t_rend *r)
{
	// TEXTURES
	SDL_DestroyTexture(r->t->bg);
	SDL_DestroyTexture(r->t->cur_forward);
	SDL_DestroyTexture(r->t->cur_back);
	SDL_DestroyTexture(r->t->cur_up);
	SDL_DestroyTexture(r->t->cur_down);
	SDL_DestroyTexture(r->t->m_filler);
	SDL_DestroyTexture(r->t->m_key);
	SDL_DestroyTexture(r->t->m_bar_left);
	SDL_DestroyTexture(r->t->m_bar_right);
	SDL_DestroyTexture(r->t->m_bar_center);
	SDL_DestroyTexture(r->t->m_bar_center_p1);
	SDL_DestroyTexture(r->t->m_bar_center_p2);
	SDL_DestroyTexture(r->t->m_bar_delimiter);
	SDL_DestroyTexture(r->t->asian);
	SDL_DestroyTexture(r->t->cv19);
	// FONTS
	SDL_DestroyTexture(r->f->k_quit);
	SDL_DestroyTexture(r->f->quit);
	SDL_DestroyTexture(r->f->k_pause);
	SDL_DestroyTexture(r->f->pause);
	SDL_DestroyTexture(r->f->resume);
	SDL_DestroyTexture(r->f->back_forward);
	SDL_DestroyTexture(r->f->speed);
	SDL_DestroyTexture(r->f->speedrate);
	SDL_DestroyTexture(r->f->p1);
	SDL_DestroyTexture(r->f->p2);
	SDL_DestroyTexture(r->f->p1_);
	SDL_DestroyTexture(r->f->p2_);
	SDL_DestroyTexture(r->f->p1_score);
	SDL_DestroyTexture(r->f->p2_score);
	SDL_DestroyTexture(r->f->p1_percent);
	SDL_DestroyTexture(r->f->p2_percent);
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
	r->f->k_quit = load_font(&(r->rend), K_QUIT, FONT_SIZE, white);
	r->f->quit = load_font(&(r->rend), QUIT, FONT_SIZE, white);
    r->f->k_pause = load_font(&(r->rend), K_PAUSE, FONT_SIZE, white);
    r->f->pause = load_font(&(r->rend), PAUSE, FONT_SIZE, white);
    r->f->resume = load_font(&(r->rend), RESUME, FONT_SIZE, white);
    r->f->back_forward = load_font(&(r->rend), BACK_FORWARD, FONT_SIZE, white);
    r->f->speed = load_font(&(r->rend), SPEED, FONT_SIZE, white);
    r->f->speedrate = load_font(&(r->rend), SPEEDRATE2, FONT_SIZE_2, white);
	r->f->p1 = load_font(&(r->rend), K_P1_NAME, FONT_SIZE, red);
	r->f->p2 = load_font(&(r->rend), K_P2_NAME, FONT_SIZE, blue);
	r->f->p1_ = load_font(&(r->rend), K_P1_NAME_, FONT_SIZE, white);
	r->f->p2_ = load_font(&(r->rend), K_P2_NAME_, FONT_SIZE, white);
	r->f->p3_ = load_font(&(r->rend), K_P3_NAME_, FONT_SIZE, white);
    r->f->p1_name = load_font(&(r->rend), r->player->p1, FONT_SIZE, white);
    r->f->p2_name = load_font(&(r->rend), r->player->p2, FONT_SIZE, white);
    r->f->p3_name = load_font(&(r->rend), "field 20 x 20", FONT_SIZE, white);
    r->f->p1_score = load_font(&(r->rend), "0", FONT_SIZE, white);
    r->f->p2_score = load_font(&(r->rend), "  0", FONT_SIZE, white);
    r->f->p1_percent = load_font(&(r->rend), "%", FONT_SIZE, white);
    r->f->p2_percent = load_font(&(r->rend), "%", FONT_SIZE, white);
	return ;
}

int				create_textur(t_rend *r)
{
    if(!(r->t->bg = load_texture(&(r->rend), "resources/checker.png")))
		return (1);
    if(!(r->t->cur_forward = load_texture(&(r->rend), "resources/cur.png")))
		return (1);
    if(!(r->t->cur_back = load_texture(&(r->rend), "resources/cur.png")))
		return (1);
    if(!(r->t->cur_up = load_texture(&(r->rend), "resources/cur.png")))
		return (1);
    if(!(r->t->cur_down = load_texture(&(r->rend), "resources/cur.png")))
		return (1);
    if(!(r->t->m_key = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->m_filler = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->m_bar_left = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->m_bar_right = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->m_bar_center = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->m_bar_center_p1 = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->m_bar_center_p2 = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->m_bar_delimiter = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->asian = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->cv19 = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->kek = load_texture(&r->rend, "resources/bg.png")))
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
									SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN)))
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
	// init TEXTURES
	t->bg = NULL;
	t->cur_forward = NULL;
	t->cur_back = NULL;
	t->cur_up = NULL;
	t->cur_down = NULL;
    t->m_key = NULL;
    t->m_filler = NULL;
    t->m_bar_left = NULL;
    t->m_bar_right = NULL;
    t->m_bar_center = NULL;
    t->m_bar_center_p1 = NULL;
    t->m_bar_center_p2 = NULL;
    t->m_bar_delimiter = NULL;
	t->asian = NULL;
	t->cv19 = NULL;
	// init FONTS
	f->k_quit = NULL;
	f->quit = NULL;
	f->k_pause = NULL;
	f->pause = NULL;
	f->resume = NULL;
	f->back_forward = NULL;
	f->speed = NULL;
	f->p1 = NULL;
	f->p2 = NULL;
	f->p1_ = NULL;
	f->p2_ = NULL;
	f->p3_ = NULL;
	f->p3_ = NULL;
	f->p1_score = NULL;
	f->p2_score = NULL;
	f->p1_percent = NULL;
	f->p2_percent = NULL;
	f->p1_name = NULL;
	f->p2_name = NULL;
	f->p3_name = NULL;
	// init RENDERER
	r->flip_hor = SDL_FLIP_HORIZONTAL;
	r->flip_non = SDL_FLIP_NONE;
	r->blend_p = BLEND_ON;
	r->blend_r = BLEND_OFF;
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