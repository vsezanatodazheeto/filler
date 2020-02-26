/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 02:21:57 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/26 20:22:18 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_H
# define SDL_H

// #include <SDL2/SDL.h> //for linux
// #include <SDL2/SDL_image.h> // for linux
// #include <SDL2/SDL_ttf.h> // for linux
#include <math.h>
#include "../frameworks/SDL2.framework/Headers/SDL.h"
#include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
#include "../frameworks/SDL2_image.framework/Headers/SDL_image.h"
#include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"

// 2560×1440 fullscreen mac
// 1600 x 1120
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 1120
#define INDENT 32
#define BAR_HEIGHT 64
#define KEY_HEIGHT 1088
#define FONT_SIZE 50
#define FONT_SIZE_2 42
#define K_QUIT "CMD + W"
#define QUIT "quit"
#define K_PAUSE "SPACE"
#define PAUSE "pause"
#define RESUME "resume"
#define BACK_FORWARD "back/forward"
#define SPEED "speed:"
#define SPEEDRATE0 "0.25"
#define SPEEDRATE1 " 0.5"
#define SPEEDRATE2 "   1"
#define SPEEDRATE3 "1.25"
#define SPEEDRATE4 " 1.5"
#define SPEEDARRAY (const char[5][5]) {SPEEDRATE0, SPEEDRATE1, SPEEDRATE2, SPEEDRATE3, SPEEDRATE4}
#define K_P1_NAME "ASIANS"
#define K_P2_NAME "COVID19"
#define K_P1_NAME_ "ASIANS:"
#define K_P2_NAME_ "COVID19:"
#define K_P3_NAME_ "EARTH:"
#define BLEND_ON SDL_BLENDMODE_MOD
#define BLEND_OFF SDL_BLENDMODE_BLEND

static const SDL_Color white = {255, 255, 255};
static const SDL_Color red = {194, 1, 20};
static const SDL_Color blue = {199, 214, 213};
static const SDL_Color green = {110, 155, 85};

typedef struct			s_flags
{
	int	p;
	int dealay;
}						t_flags;

typedef struct			s_rect
{
	SDL_Rect			bg;
    SDL_Rect			key;
    SDL_Rect			filler;
    SDL_Rect			bar_left;
    SDL_Rect			bar_right;
    SDL_Rect			bar_center;
    SDL_Rect			bar_bord;
    SDL_Rect			bar_bord_2;
    SDL_Rect			k_quit;
    SDL_Rect			quit;
    SDL_Rect			k_pause;
    SDL_Rect			pause;
    SDL_Rect			resume;
    SDL_Rect			cur_forward;
    SDL_Rect			cur_back;
    SDL_Rect			cur_up;
    SDL_Rect			cur_down;
    SDL_Rect			back_forward;
    SDL_Rect			speed;
    SDL_Rect			speedrate;
    SDL_Rect			p1;
    SDL_Rect			p2;
    SDL_Rect			p1_;
    SDL_Rect			p2_;
    SDL_Rect			p3_;
    SDL_Rect			p1_name;
    SDL_Rect			p2_name;
    SDL_Rect			p3_name;
	SDL_Rect			asian;
	SDL_Rect			cv_19;
	SDL_Rect			earth;
	//
	SDL_Rect			kek;
}						t_rect;

typedef struct			s_font
{
	SDL_Texture			*k_quit;
	SDL_Texture			*quit;
	SDL_Texture			*k_pause;
	SDL_Texture			*pause;
	SDL_Texture			*resume;
	SDL_Texture			*back_forward;
	SDL_Texture			*speed;
	SDL_Texture			*speedrate;
	SDL_Texture			*p1_;
	SDL_Texture			*p2_;
	SDL_Texture			*p3_;
	SDL_Texture			*p1;
	SDL_Texture			*p2;
	SDL_Texture			*p3;
	SDL_Texture			*p1_name;
	SDL_Texture			*p2_name;
	SDL_Texture			*p3_name;

}						t_font;

typedef struct			s_textur
{
	SDL_Texture			*bg;
    SDL_Texture			*cur_forward;
    SDL_Texture			*cur_back;
    SDL_Texture			*cur_up;
    SDL_Texture			*cur_down;
    SDL_Texture			*m_key;
    SDL_Texture			*m_filler;
    SDL_Texture			*m_bar_left;
    SDL_Texture			*m_bar_right;
    SDL_Texture			*m_bar_center;
    SDL_Texture			*m_bar_delimiter;
	SDL_Texture			*asian;
	SDL_Texture			*cv_19;
    //
	SDL_Texture			*kek;
}						t_textur;

typedef struct			s_rend
{
	t_player			*player;
	SDL_RendererFlip 	flip_hor;
	SDL_RendererFlip 	flip_non;
	SDL_BlendMode		blend_p;
	SDL_BlendMode		blend_r;
	SDL_Renderer 		*rend;
	t_textur			*t;
	t_font				*f;
	t_rect				*rect;
}						t_rend;

int					main_v(t_f *f, t_player *player);
int					init_lib();
void				init_t_rend(t_rend *r, t_textur *t, t_font *f, t_rect *rect);
int					create(SDL_Window **win, t_rend *r, t_player *player);
int					create_textur(t_rend *r);
void				create_font(t_rend *r);
int					quit(SDL_Window **win, t_rend *r);

SDL_Texture			*load_texture(SDL_Renderer **rend, char *path);
SDL_Texture			*load_font(SDL_Renderer **rend, char *path, int size, SDL_Color clr);

void				menu_rect(t_rend *r, t_rect *rect);
void				word_rect(t_rend *r, t_rect *rect);
void				field_rect(t_rend *r, t_rect *rect, t_f *lst);
void				draw_bacground(t_rend *r, t_rect *rect);
void				draw_menu(t_rend *r, t_rect *rect);
void				draw_message(t_rend *r, t_rect *rect);
void				draw_player(t_rend *r, t_rect *rect);
void				draw_player_name(t_rend *r, t_rect *rect);
void				draw_map(t_rend *r, t_rect *rect, t_f *curlst);

#endif