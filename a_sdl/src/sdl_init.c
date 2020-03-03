/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/03 23:59:46 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

void			quit(SDL_Window **win, t_rend *r)
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
	SDL_DestroyTexture(r->f->re);
	SDL_DestroyTexture(r->f->replay);
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
	TTF_Quit();
	SDL_Quit();
	IMG_Quit();
	return ;
}

int				create_font(t_rend *r)
{
	if (!(r->f->cmdw = load_font(&(r->rend), CMDW, FONT_SIZE, white)))
		return (1);
	if (!(r->f->quit = load_font(&(r->rend), QUIT, FONT_SIZE, white)))
		return (1);
	if (!(r->f->space = load_font(&(r->rend), SPACE, FONT_SIZE, white)))
		return (1);
	if (!(r->f->pause = load_font(&(r->rend), PAUSE, FONT_SIZE, white)))
		return (1);
	if (!(r->f->resume = load_font(&(r->rend), RESUME, FONT_SIZE, white)))
		return (1);
	if (!(r->f->re = load_font(&(r->rend), R, FONT_SIZE, white)))
		return (1);
	if (!(r->f->replay = load_font(&(r->rend), REPLAY, FONT_SIZE, white)))
		return (1);
	if (!(r->f->back_forward = load_font(&(r->rend), BACK_FORWARD, FONT_SIZE, white)))
		return (1);
	if (!(r->f->speed = load_font(&(r->rend), SPEED, FONT_SIZE, white)))
		return (1);
	if (!(r->f->speedrate = load_font(&(r->rend), SPEEDRATE2, FONT_SIZE_2, white)))
		return (1);
	if (!(r->f->p1_bar = load_font(&(r->rend), P1_BAR, FONT_SIZE, red)))
		return (1);
	if (!(r->f->p2_bar = load_font(&(r->rend), P2_BAR, FONT_SIZE, yellow)))
		return (1);
	if (!(r->f->p1_score = load_font(&(r->rend), "0", FONT_SIZE, white)))
		return (1);
	if (!(r->f->p2_score = load_font(&(r->rend), "  0", FONT_SIZE, white)))
		return (1);
	if (!(r->f->p1_keymenu = load_font(&(r->rend), K_P1_NAME_, FONT_SIZE, white)))
		return (1);
	if (!(r->f->p2_keymenu = load_font(&(r->rend), K_P2_NAME_, FONT_SIZE, white)))
		return (1);
	if (!(r->f->p3_keymenu = load_font(&(r->rend), K_P3_NAME_, FONT_SIZE, white)))
		return (1);
	if (!(r->f->p1_name = load_font(&(r->rend), r->player->p1, FONT_SIZE, white)))
		return (1);
	if (!(r->f->p2_name = load_font(&(r->rend), r->player->p2, FONT_SIZE, white)))
		return (1);
	if (!(r->f->p3_name = load_font(&(r->rend), r->player->field, FONT_SIZE, white)))
		return (1);
	return (0);
}

int				create_texture(t_rend *r)
{
	if (!(r->t->bg = load_texture(&(r->rend), "resources/checker.png")))
		return (1);
	if (!(r->t->fillboard = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if (!(r->t->keymenu = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if (!(r->t->bar_left = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if (!(r->t->bar_right = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if (!(r->t->bar_center = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if (!(r->t->bar_center_p1 = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if (!(r->t->bar_center_p2 = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if (!(r->t->bar_delimiter = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if (!(r->t->cur_forward = load_texture(&(r->rend), "resources/cur.png")))
		return (1);
	if (!(r->t->cur_back = load_texture(&(r->rend), "resources/cur.png")))
		return (1);
	if (!(r->t->cur_up = load_texture(&(r->rend), "resources/cur.png")))
		return (1);
	if (!(r->t->cur_down = load_texture(&(r->rend), "resources/cur.png")))
		return (1);
	if (!(r->t->asian = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if (!(r->t->cv19 = load_texture(&(r->rend), "resources/bg.png")))
		return (1);
	if (!(r->t->figure = load_texture(&r->rend, "resources/bg.png")))
		return (1);
	if (!(r->t->earth = load_texture(&r->rend, "resources/bg.png")))
		return (1);
	if (!(r->t->earth_grid = load_texture(&r->rend, "resources/bg.png")))
		return (1);
	return (0);
}

int				create(SDL_Window **win, t_rend *r)
{
	Uint32 render_flags;

	render_flags = SDL_RENDERER_ACCELERATED;
	if (!(*win = SDL_CreateWindow("Huiler2.0",
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
	if (create_font(r) != 0)
		return (1);
	if (create_texture(r) != 0)
		return (1);
	return (0);
}

void			init_music(t_music *music)
{
    music->slowlest = Mix_LoadMUS("resources/025.mp3");
    music->slow = Mix_LoadMUS("resources/05.mp3");
    music->normal = Mix_LoadMUS("resources/1.mp3");
    music->fast = Mix_LoadMUS("resources/125.mp3");
    music->fastest = Mix_LoadMUS("resources/15.mp3");
	return ;
}

void			init_t_rend(t_rend *r, t_textur *t, t_font *f, t_rect *rect, t_event *event, t_player *player, t_f *lst)
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
	f->re = NULL;
	f->replay = NULL;
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
	// EVENT
	event->run = 1;
	event->pause = 1;
	event->shift = 0;
	event->delay = 40;
	event->color = 2;
	event->mapsize = lst->m->height * lst->m->width;
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

int				init_lib(void)
{
	// Initialize PNG loading
	int flags;
	int flags_mix ;

	flags = IMG_INIT_PNG;
	flags_mix = MIX_INIT_MP3;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		return (1);
	if (!(IMG_Init(flags) & flags))
		return (1);
	if (TTF_Init() != 0)
		return (1);
	if (!Mix_Init(flags_mix))
		return (1);
	else
		Mix_OpenAudio(48000, AUDIO_S32SYS, 2, 640);
	// Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		return (1);
	return (0);
}
