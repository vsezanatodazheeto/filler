/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/02 19:47:49 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

int				quit(SDL_Window **win, t_rend *r)
{
	// TEXTURES
	SDL_DestroyTexture(r->t->bg);
	SDL_DestroyTexture(r->t->fillboard);
	SDL_DestroyTexture(r->t->keymenu);
	SDL_DestroyTexture(r->t->bar_left);
	SDL_DestroyTexture(r->t->bar_right);
	SDL_DestroyTexture(r->t->bar_center);
	SDL_DestroyTexture(r->t->bar_center_p1);
	SDL_DestroyTexture(r->t->bar_center_p2);
	SDL_DestroyTexture(r->t->bar_delimiter);
	//
	SDL_DestroyTexture(r->t->cur_forward);
	SDL_DestroyTexture(r->t->cur_back);
	SDL_DestroyTexture(r->t->cur_up);
	SDL_DestroyTexture(r->t->cur_down);
	//
	SDL_DestroyTexture(r->t->asian);
	SDL_DestroyTexture(r->t->cv19);
	SDL_DestroyTexture(r->t->figure);
	SDL_DestroyTexture(r->t->earth);
	SDL_DestroyTexture(r->t->earth_grid);
	// FONTS
	SDL_DestroyTexture(r->f->cmdw);
	SDL_DestroyTexture(r->f->quit);
	SDL_DestroyTexture(r->f->space);
	SDL_DestroyTexture(r->f->pause);
	SDL_DestroyTexture(r->f->resume);
	SDL_DestroyTexture(r->f->back_forward);
	SDL_DestroyTexture(r->f->speed);
	SDL_DestroyTexture(r->f->speedrate);
	SDL_DestroyTexture(r->f->p1_bar);
	SDL_DestroyTexture(r->f->p2_bar);
	SDL_DestroyTexture(r->f->p1_score);
	SDL_DestroyTexture(r->f->p2_score);
	SDL_DestroyTexture(r->f->p1_keymenu);
	SDL_DestroyTexture(r->f->p2_keymenu);
	SDL_DestroyTexture(r->f->p3_keymenu);
	SDL_DestroyTexture(r->f->p1_name);
	SDL_DestroyTexture(r->f->p2_name);
	SDL_DestroyTexture(r->f->p3_name);
	// RENDER
	SDL_DestroyRenderer(r->rend);
	// WINDOW
	SDL_DestroyWindow(*win);
	*win = NULL;
    SDL_Quit();
    IMG_Quit();
    return (0);
}

void				create_font(t_rend *r)
{
	r->f->cmdw = load_font(&(r->rend), CMDW, FONT_SIZE, white);
	r->f->quit = load_font(&(r->rend), QUIT, FONT_SIZE, white);
    r->f->space = load_font(&(r->rend), SPACE, FONT_SIZE, white);
    r->f->pause = load_font(&(r->rend), PAUSE, FONT_SIZE, white);
    r->f->resume = load_font(&(r->rend), RESUME, FONT_SIZE, white);
    r->f->back_forward = load_font(&(r->rend), BACK_FORWARD, FONT_SIZE, white);
    r->f->speed = load_font(&(r->rend), SPEED, FONT_SIZE, white);
    r->f->speedrate = load_font(&(r->rend), SPEEDRATE2, FONT_SIZE_2, white);
	r->f->p1_bar = load_font(&(r->rend), P1_BAR, FONT_SIZE, red);
	r->f->p2_bar = load_font(&(r->rend), P2_BAR, FONT_SIZE, yellow);
    r->f->p1_score = load_font(&(r->rend), "0", FONT_SIZE, white);
    r->f->p2_score = load_font(&(r->rend), "  0", FONT_SIZE, white);
	r->f->p1_keymenu = load_font(&(r->rend), K_P1_NAME_, FONT_SIZE, white);
	r->f->p2_keymenu = load_font(&(r->rend), K_P2_NAME_, FONT_SIZE, white);
	r->f->p3_keymenu = load_font(&(r->rend), K_P3_NAME_, FONT_SIZE, white);
    r->f->p1_name = load_font(&(r->rend), r->player->p1, FONT_SIZE, white);
    r->f->p2_name = load_font(&(r->rend), r->player->p2, FONT_SIZE, white);
    r->f->p3_name = load_font(&(r->rend), r->player->field, FONT_SIZE, white);
	return ;
}

int				create_texture(t_rend *r)
{
    if(!(r->t->bg = load_texture(&(r->rend), "resources/checker.png")))
		return (1);
	if(!(r->t->fillboard = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
    if(!(r->t->keymenu = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->bar_left = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->bar_right = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->bar_center = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->bar_center_p1 = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->bar_center_p2 = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->bar_delimiter = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	// ....
    if(!(r->t->cur_forward = load_texture(&(r->rend), "resources/cur.png")))
		return (1);
    if(!(r->t->cur_back = load_texture(&(r->rend), "resources/cur.png")))
		return (1);
    if(!(r->t->cur_up = load_texture(&(r->rend), "resources/cur.png")))
		return (1);
    if(!(r->t->cur_down = load_texture(&(r->rend), "resources/cur.png")))
		return (1);
	// ....
	if(!(r->t->asian = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->cv19 = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if(!(r->t->figure = load_texture(&r->rend, "resources/bg.png")))
		return (1);
	if(!(r->t->earth = load_texture(&r->rend, "resources/bg.png")))
		return (1);
	if(!(r->t->earth_grid = load_texture(&r->rend, "resources/bg.png")))
		return (1);
    return (0);
}

int				create(SDL_Window **win, t_rend *r)
{
	Uint32 render_flags;

	render_flags = SDL_RENDERER_ACCELERATED;
    if (!(*win = SDL_CreateWindow("Huiler",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									SCREEN_WIDTH, SCREEN_HEIGHT,
									SDL_WINDOW_SHOWN))) // SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
		return (1);
	if (!(r->rend = SDL_CreateRenderer(*win, -1, render_flags)))
		return (1);
	else
		SDL_SetRenderDrawColor(r->rend, 255, 255, 255, 255);
	// CREATE RENDER DATA
	create_font(r);
	create_texture(r);
    return (0);
}

void			init_t_rend(t_rend *r, t_textur *t, t_font *f, t_rect *rect, t_event *event, t_player *player)
{
	// init TEXTURES
	t->bg = NULL;
    t->fillboard = NULL;
    t->keymenu = NULL;
    t->bar_left = NULL;
    t->bar_right = NULL;
    t->bar_center = NULL;
    t->bar_center_p1 = NULL;
    t->bar_center_p2 = NULL;
    t->bar_delimiter = NULL;
	t->cur_forward = NULL;
	t->cur_back = NULL;
	t->cur_up = NULL;
	t->cur_down = NULL;
	t->asian = NULL;
	t->cv19 = NULL;
	t->figure = NULL;
	t->earth = NULL;
	t->earth_grid = NULL;
	// init FONTS
	f->cmdw = NULL;
	f->quit = NULL;
	f->space = NULL;
	f->pause = NULL;
	f->resume = NULL;
	f->back_forward = NULL;
	f->speed = NULL;
	f->p1_bar = NULL;
	f->p2_bar = NULL;
	f->p1_score = NULL;
	f->p2_score = NULL;
	f->p1_keymenu = NULL;
	f->p2_keymenu = NULL;
	f->p3_keymenu = NULL;
	f->p1_name = NULL;
	f->p2_name = NULL;
	f->p3_name = NULL;
	//EVENT
	event->run = TRUE;
	event->shift = 0;
	event->delay = 40;
	event->color = 2;
	event->str_score = NULL;
	// init RENDERER
	r->flip_hor = SDL_FLIP_HORIZONTAL;
	r->flip_non = SDL_FLIP_NONE;
	r->blend_p = BLEND_ON;
	r->blend_r = BLEND_OFF;
	r->rend = NULL;
	r->t = t;
	r->f = f;
	r->rect = rect;
	r->event = event;
	r->player = player;
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