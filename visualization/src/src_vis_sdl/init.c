/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/04 14:47:51 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vis_filler.h"
#include "../../include/vis_sdl.h"

void			quit(SDL_Window **win, t_rend *r, t_music *music)
{
	// TEXTURES
	SDL_DestroyTexture(r->t->bg);
	r->t->bg = NULL;
	SDL_DestroyTexture(r->t->fillboard);
	r->t->fillboard = NULL;
	SDL_DestroyTexture(r->t->keymenu);
	r->t->keymenu = NULL;
	SDL_DestroyTexture(r->t->bar_left);
	r->t->bar_left = NULL;
	SDL_DestroyTexture(r->t->bar_right);
	r->t->bar_right = NULL;
	SDL_DestroyTexture(r->t->bar_center);
	r->t->bar_center = NULL;
	SDL_DestroyTexture(r->t->bar_center_p1);
	r->t->bar_center_p1 = NULL;
	SDL_DestroyTexture(r->t->bar_center_p2);
	r->t->bar_center_p2 = NULL;
	SDL_DestroyTexture(r->t->bar_delimiter);
	r->t->bar_delimiter = NULL;
	SDL_DestroyTexture(r->t->cur_forward);
	r->t->cur_forward = NULL;
	SDL_DestroyTexture(r->t->cur_back);
	r->t->cur_back = NULL;
	SDL_DestroyTexture(r->t->cur_up);
	r->t->cur_up = NULL;
	SDL_DestroyTexture(r->t->cur_down);
	r->t->cur_down = NULL;
	SDL_DestroyTexture(r->t->asian);
	r->t->asian = NULL;
	SDL_DestroyTexture(r->t->cv19);
	r->t->cv19 = NULL;
	SDL_DestroyTexture(r->t->figure);
	r->t->figure = NULL;
	SDL_DestroyTexture(r->t->earth);
	r->t->earth = NULL;
	SDL_DestroyTexture(r->t->earth_grid);
	r->t->earth_grid = NULL;
	// FONTS
	SDL_DestroyTexture(r->f->cmdw);
	r->f->cmdw = NULL;
	SDL_DestroyTexture(r->f->quit);
	r->f->quit = NULL;
	SDL_DestroyTexture(r->f->space);
	r->f->space = NULL;
	SDL_DestroyTexture(r->f->pause);
	r->f->pause = NULL;
	SDL_DestroyTexture(r->f->resume);
	r->f->resume = NULL;
	SDL_DestroyTexture(r->f->re);
	r->f->re = NULL;
	SDL_DestroyTexture(r->f->replay);
	r->f->replay = NULL;
	SDL_DestroyTexture(r->f->back_forward);
	r->f->back_forward = NULL;
	SDL_DestroyTexture(r->f->speed);
	r->f->speed = NULL;
	SDL_DestroyTexture(r->f->speedrate);
	r->f->speedrate = NULL;
	SDL_DestroyTexture(r->f->p1_bar);
	r->f->p1_bar = NULL;
	SDL_DestroyTexture(r->f->p2_bar);
	r->f->p2_bar = NULL;
	SDL_DestroyTexture(r->f->p1_score);
	r->f->p1_score = NULL;
	SDL_DestroyTexture(r->f->p2_score);
	r->f->p2_score = NULL;
	SDL_DestroyTexture(r->f->p1_keymenu);
	r->f->p1_keymenu = NULL;
	SDL_DestroyTexture(r->f->p2_keymenu);
	r->f->p2_keymenu = NULL;
	SDL_DestroyTexture(r->f->p3_keymenu);
	r->f->p3_keymenu = NULL;
	SDL_DestroyTexture(r->f->p1_name);
	r->f->p1_name = NULL;
	SDL_DestroyTexture(r->f->p2_name);
	r->f->p2_name = NULL;
	SDL_DestroyTexture(r->f->p3_name);
	r->f->p3_name = NULL;
	// MUSIC
    Mix_FreeMusic(music->fastest);
    music->fastest = NULL;
	// RENDER
	SDL_DestroyRenderer(r->rend);
	r->rend = NULL;
	// WINDOW
	SDL_DestroyWindow(*win);
	*win = NULL;
	TTF_Quit();
	SDL_Quit();
	IMG_Quit();
	Mix_Quit();
	return ;
}

int			create_music(t_music *music)
{
	if(!(music->fastest = Mix_LoadMUS("datasrc/fluk_dat.mp3")))
		return (1);
	return (0);
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
	if (!(r->t->bg = load_texture(&(r->rend), PATH_TEXTURE_1)))
		return (1);
	if (!(r->t->fillboard = load_texture(&(r->rend), PATH_TEXTURE_2)))
		return (1);
	if (!(r->t->keymenu = load_texture(&(r->rend), PATH_TEXTURE_2)))
		return (1);
	if (!(r->t->bar_left = load_texture(&(r->rend), PATH_TEXTURE_2)))
		return (1);
	if (!(r->t->bar_right = load_texture(&(r->rend), PATH_TEXTURE_2)))
		return (1);
	if (!(r->t->bar_center = load_texture(&(r->rend), PATH_TEXTURE_2)))
		return (1);
	if (!(r->t->bar_center_p1 = load_texture(&(r->rend), PATH_TEXTURE_2)))
		return (1);
	if (!(r->t->bar_center_p2 = load_texture(&(r->rend), PATH_TEXTURE_2)))
		return (1);
	if (!(r->t->bar_delimiter = load_texture(&(r->rend), PATH_TEXTURE_2)))
		return (1);
	if (!(r->t->cur_forward = load_texture(&(r->rend), PATH_TEXTURE_3)))
		return (1);
	if (!(r->t->cur_back = load_texture(&(r->rend), PATH_TEXTURE_3)))
		return (1);
	if (!(r->t->cur_up = load_texture(&(r->rend), PATH_TEXTURE_3)))
		return (1);
	if (!(r->t->cur_down = load_texture(&(r->rend), PATH_TEXTURE_3)))
		return (1);
	if (!(r->t->asian = load_texture(&(r->rend), PATH_TEXTURE_2)))
		return (1);
	if (!(r->t->cv19 = load_texture(&(r->rend), PATH_TEXTURE_2)))
		return (1);
	if (!(r->t->figure = load_texture(&r->rend, PATH_TEXTURE_2)))
		return (1);
	if (!(r->t->earth = load_texture(&r->rend, PATH_TEXTURE_2)))
		return (1);
	if (!(r->t->earth_grid = load_texture(&r->rend, PATH_TEXTURE_2)))
		return (1);
	return (0);
}

int				create(SDL_Window **win, t_rend *r, t_music *music)
{
	Uint32 flags_render;

	flags_render = SDL_RENDERER_ACCELERATED;
	// CREATE WINDOW
	if (!(*win = SDL_CreateWindow("FILLER 6.9",
								  SDL_WINDOWPOS_UNDEFINED,
								  SDL_WINDOWPOS_UNDEFINED,
								  SCREEN_WIDTH, SCREEN_HEIGHT,
								  SDL_WINDOW_SHOWN)))
	{
		ft_printf("{red} unable to create window in CREATE{eoc}\n");
		return (1);
	}
	// CREATE RENDERER IN WINDOW
	if (!(r->rend = SDL_CreateRenderer(*win, -1, flags_render)))
	{
		ft_printf("{red} unable to create renderer in CREATE{eoc}\n");
		return (1);
	}
	else
		SDL_SetRenderDrawColor(r->rend, 255, 255, 255, 255);
	// CREATE RENDERER DATA
	if (create_font(r) != 0)
	{
		ft_printf("{red} unable to load fonts in CREATE_FONT{eoc}\n");
		return (1);
	}
	if (create_texture(r) != 0)
	{
		ft_printf("{red} unable to load textures in CREATE_TEXTURE{eoc}\n");
		return (1);
	}
	if (create_music(music) != 0)
		ft_printf("{blue} unable to load music in CREATE_MUSIC{eoc}\n");
	return (0);
}

void			init_t_rend(t_rend *r, t_textur *t, t_font *f, t_rect *rect, t_event *event, t_player *player, t_f *lst)
{
	// TEXTURES
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
	// FONTS
	f->cmdw = NULL;
	f->quit = NULL;
	f->space = NULL;
	f->pause = NULL;
	f->resume = NULL;
	f->re = NULL;
	f->replay = NULL;
	f->back_forward = NULL;
	f->speed = NULL;
	f->speedrate = NULL;
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
	// MAIN STRUCT R
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
	int flags_img;
	int flags_mix ;

	flags_img = IMG_INIT_PNG;
	flags_mix = MIX_INIT_MP3;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		return (1);
	if (!(IMG_Init(flags_img) & flags_img))
		return (1);
	if (TTF_Init() != 0)
		return (1);
	if (!(Mix_Init(flags_mix) & flags_mix))
		return (1);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		ft_printf("{blue} unable to open audio in INIT_LIB{eoc}\n");
	// Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		return (1);
	return (0);
}
