/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_sdl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 02:21:57 by yshawn            #+#    #+#             */
/*   Updated: 2020/06/15 03:12:04 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_H
# define SDL_H

# include "vis_filler.h"

#if defined(__linux__) // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
	# include <SDL2/SDL.h>
	# include <SDL2/SDL_image.h>
	# include <SDL2/SDL_ttf.h>
	# include <SDL2/SDL_mixer.h>
#elif defined(__APPLE__) // Apple OSX and iOS (Darwin)
	# include "../frameworks/SDL2.framework/Headers/SDL.h"
	# include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
	# include "../frameworks/SDL2_image.framework/Headers/SDL_image.h"
	# include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"
#endif

/*
** path to pics, music, fonts
*/
# define PATH "../visualization/data/"
# define PATH_TTF PATH "zb.ttf"
# define PATH_TEXTURE_1 PATH "checker.png"
# define PATH_TEXTURE_2 PATH "bg.png"
# define PATH_TEXTURE_3 PATH "cur.png"

/*
** size of window, window elements, fonts
*/
// # define SCREEN_WIDTH 1600
// # define SCREEN_HEIGHT 1120
# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 920
# define INDENT 32
# define BAR_HEIGHT INDENT * 2
# define FONT_SIZE 50
# define FONT_SIZE_2 42

/*
** titles
*/
# define CMDW "ESC"
# define QUIT "quit"
# define SPACE "SPACE"
# define PAUSE "pause"
# define RESUME "resume"
# define R "R"
# define REPLAY "replay"
# define BACK_FORWARD "back/forward"
# define SPEED "speed:"
# define P1_BAR "PEOPLE"
# define P2_BAR "COVID19"
# define K_P1_NAME_ "PEOPLE:"
# define K_P2_NAME_ "COVID19:"
# define K_P3_NAME_ "EARTH:"

/*
** events (keystroke)
*/
# define SPEEDRATE0 " 0.5"
# define SPEEDRATE1 "0.75"
# define SPEEDRATE2 "   1"
# define SPEEDRATE3 "1.25"
# define SPEEDRATE4 "  69"
# define SPEEDARRAY (const char[5][5]) {SPEEDRATE0, SPEEDRATE1, SPEEDRATE2, SPEEDRATE3, SPEEDRATE4}
# define BLEND_ON SDL_BLENDMODE_MOD
# define BLEND_OFF SDL_BLENDMODE_BLEND
# define DELAY_MIN 0
# define DELAY_MAX 80
# define DELAY_STEP 20

/*
** colors
*/
static const SDL_Color white = {255, 255, 255, 255};
static const SDL_Color red = {194, 1, 20, 255};
static const SDL_Color yellow = {255, 220, 55, 255};
static const SDL_Color grey = {115, 115, 115, 255};

# define COLORARRAY (SDL_Color [5]) {{221, 115, 115, 255},\
									 {244, 166, 152, 255},\
									 {255, 255, 255, 255},\
									 {198, 216, 195, 255},\
									 {160, 192, 132, 255}}

typedef struct			s_music
{
	Mix_Music *fastest;
}						t_music;

typedef struct			s_event
{
	int					run;
	int					pause; // even or 0 - GO, odd - STOP
	int					shift; // shift for background
	int					delay;
	int					color;
	int					mapsize; // width * height for fillboard
	char				*str_score; // bar score for players in percent
}						t_event;

typedef struct			s_rect
{
	SDL_Rect			bg;
	SDL_Rect			fillboard;
	SDL_Rect			keymenu;
	SDL_Rect			bar_left;
	SDL_Rect			bar_right;
	SDL_Rect			bar_center;
	SDL_Rect			bar_center_p1;
	SDL_Rect			bar_center_p2;
	SDL_Rect			bar_delimiter;
	SDL_Rect			bar_delimiter_2;
	SDL_Rect			cmdw;
	SDL_Rect			quit;
	SDL_Rect			space;
	SDL_Rect			pause;
	SDL_Rect			resume;
	SDL_Rect			re;
	SDL_Rect			replay;
	SDL_Rect			cur_forward;
	SDL_Rect			cur_back;
	SDL_Rect			cur_up;
	SDL_Rect			cur_down;
	SDL_Rect			back_forward;
	SDL_Rect			speed;
	SDL_Rect			speedrate;
	SDL_Rect			p1_bar;
	SDL_Rect			p2_bar;
	SDL_Rect			p1_score;
	SDL_Rect			p2_score;
	SDL_Rect			p1_keymenu;
	SDL_Rect			p2_keymenu;
	SDL_Rect			p3_keymenu;
	SDL_Rect			p1_name;
	SDL_Rect			p2_name;
	SDL_Rect			p3_name;
	SDL_Rect			asian;
	SDL_Rect			cv19;
	SDL_Rect			figure;
	SDL_Rect			earth;
	SDL_Rect			earth_grid;
}						t_rect;

typedef struct			s_font
{
	SDL_Texture			*cmdw;
	SDL_Texture			*quit;
	SDL_Texture			*space;
	SDL_Texture			*pause;
	SDL_Texture			*resume;
	SDL_Texture			*re;
	SDL_Texture			*replay;
	SDL_Texture			*back_forward;
	SDL_Texture			*speed;
	SDL_Texture			*speedrate;
	SDL_Texture			*p1_bar;
	SDL_Texture			*p2_bar;
	SDL_Texture			*p1_score;
	SDL_Texture			*p2_score;
	SDL_Texture			*p1_keymenu;
	SDL_Texture			*p2_keymenu;
	SDL_Texture			*p3_keymenu;
	SDL_Texture			*p1_name;
	SDL_Texture			*p2_name;
	SDL_Texture			*p3_name;
}						t_font;

typedef struct			s_textur
{
	SDL_Texture			*bg;
	SDL_Texture			*fillboard;
	SDL_Texture			*keymenu;
	SDL_Texture			*bar_left;
	SDL_Texture			*bar_right;
	SDL_Texture			*bar_center;
	SDL_Texture			*bar_center_p1; //font
	SDL_Texture			*bar_center_p2; //font
	SDL_Texture			*bar_delimiter;
	SDL_Texture			*cur_forward;
	SDL_Texture			*cur_back;
	SDL_Texture			*cur_up;
	SDL_Texture			*cur_down;
	SDL_Texture			*asian;
	SDL_Texture			*cv19;
	SDL_Texture			*figure;
	SDL_Texture			*earth;
	SDL_Texture			*earth_grid;
}						t_textur;

typedef struct			s_rend
{
	SDL_RendererFlip	flip_hor;
	SDL_RendererFlip	flip_non;
	SDL_BlendMode		blend_p;
	SDL_BlendMode		blend_r;
	SDL_Renderer		*rend;
	t_textur			*t;
	t_font				*f;
	t_rect				*rect;
	t_event				*event;
	t_player			*player;
}						t_rend;

void					sdl_main(t_f *f, t_player *player);
int						init_lib();
void					init_t_rend(t_rend *r, t_textur *t, t_font *f, t_rect *rect, t_event *event, t_player *player, t_f *lst);
int						create(SDL_Window **win, t_rend *r, t_music *music);
int						create_texture(t_rend *r);
int						create_font(t_rend *r);
int						create_music(t_music *music);
void					quit(SDL_Window **win, t_rend *r, t_music *music);

int						key_event(SDL_Event e, t_rend *r, t_f **lst, t_f **fst_lst, t_music *music);
void					rect_menu(t_rend *r, t_rect *rect);
void					rect_bar(t_rend *r, t_rect *rect, t_f *lst);
void					rect_message(t_rend *r, t_rect *rect);
void					rect_field(t_rend *r, t_rect *rect, t_f *lst);
void					draw_bacground(t_rend *r, t_rect *rect);
void					draw_menu(t_rend *r, t_rect *rect, t_f *lst);
void					draw_message(t_rend *r, t_rect *rect);
void					draw_playername(t_rend *r, t_rect *rect);
void					draw_map(t_rend *r, t_rect *rect, t_f *curlst);
void					draw_figure(t_rend *r, t_rect *rect, t_f *lst);
void					draw_map_grid(t_rend *r, t_rect *rect);

int						keep_stop_game(t_rend *r, t_f **lst);
void					blendmode_swap(t_rend *r);
int						score_recount(t_rend *r, t_f *lst);
SDL_Texture				*load_texture(SDL_Renderer **rend, char *path);
SDL_Texture				*load_font(SDL_Renderer **rend, char *path, int size, SDL_Color clr);

#endif
