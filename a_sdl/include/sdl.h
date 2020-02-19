/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 02:21:57 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/19 20:13:54 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_H
# define SDL_H

// #include <SDL2/SDL.h> //for linux
// #include <SDL2/SDL_image.h> // for linux
// #include <SDL2/SDL_ttf.h> // for linux
#include "../frameworks/SDL2.framework/Headers/SDL.h"
#include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
#include "../frameworks/SDL2_image.framework/Headers/SDL_image.h"
#include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"

// 2560×1440 fullscreen mac
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 1120
#define INDENT 32
#define BAR_HEIGHT 64
#define KEY_HEIGHT 1088
#define FONT_SIZE 50
#define K_QUIT "CMD + W"
#define QUIT "quit"
#define K_PAUSE "SPACE"
#define PAUSE "pause"
#define RESUME "resume"
#define F_BACK "back"
#define F_FORWARD "forward"
#define K_P1_NAME "ASIANS"
#define K_P2_NAME "COVID-19"
#define K_P1_NAME_ "ASIANS:"
#define K_P2_NAME_ "COVID-19:"
#define BLEND_ON SDL_BLENDMODE_MOD
#define BLEND_OFF SDL_BLENDMODE_BLEND

typedef struct			s_rect
{
	SDL_Rect			bg;
    SDL_Rect			key;
    SDL_Rect			filler;
    SDL_Rect			bar;
    SDL_Rect			k_quit;
    SDL_Rect			quit;
    SDL_Rect			k_pause;
    SDL_Rect			pause;
    SDL_Rect			resume;
    SDL_Rect			cur;
    SDL_Rect			back;
    SDL_Rect			forward;
    SDL_Rect			p1;
    SDL_Rect			p2;
    SDL_Rect			p1_;
    SDL_Rect			p2_;
    SDL_Rect			p1_name;
    SDL_Rect			p2_name;
	SDL_Rect			asian;
	SDL_Rect			cv_19;
}						t_rect;

typedef struct			s_font
{
	SDL_Texture			*k_quit;
	SDL_Texture			*quit;
	SDL_Texture			*k_pause;
	SDL_Texture			*pause;
	SDL_Texture			*resume;
	SDL_Texture			*back;
	SDL_Texture			*forward;
	SDL_Texture			*p1_;
	SDL_Texture			*p2_;
	SDL_Texture			*p1;
	SDL_Texture			*p2;
	SDL_Texture			*p1_name;
	SDL_Texture			*p2_name;

}						t_font;

typedef struct			s_textur
{
	SDL_Texture			*bg;
    SDL_Texture			*cur;
    SDL_Texture			*m_key;
    SDL_Texture			*m_filler;
    SDL_Texture			*m_bar;
	SDL_Texture			*asian;
	SDL_Texture			*cv_19;
}						t_textur;

typedef struct			s_rend
{
	SDL_RendererFlip 	flip;
	SDL_BlendMode		blend_p;
	SDL_BlendMode		blend_r;
	SDL_Renderer 		*rend;
	t_players			*player;
	t_textur			*t;
	t_font				*f;
	t_rect				*rect;
}						t_rend;

int					main_v(t_filler *filler, t_players *players);
int					init_lib();
void				init_t_rend(t_rend *r, t_textur *t, t_font *f, t_rect *rect);
int					create(SDL_Window **win, t_rend *r, t_players *player);
int					create_textur(t_rend *r);
void				create_font(t_rend *r);
int					quit(SDL_Window **win, t_rend *r);

SDL_Texture			*load_texture(SDL_Renderer **rend, char *path);
SDL_Texture			*load_font(SDL_Renderer **rend, char *path, int size);

void				draw_bacground(t_rend *r, t_rect *rect);
void				draw_fillboard(t_rend *r, t_rect *rect);
void				draw_keyboard(t_rend *r, t_rect *rect);
void				draw_bar(t_rend *r, t_rect *rect);
void				draw_msg_quit(t_rend *r, t_rect *rect);
void				draw_msg_pause(t_rend *r, t_rect *rect);
void				draw_msg_cursor_back(t_rend *r, t_rect *rect);
void				draw_msg_cursor_forward(t_rend *r, t_rect *rect);
void				draw_player(t_rend *r, t_rect *rect);
void				draw_player_name(t_rend *r, t_rect *rect);
void				draw_map(t_rend *r, t_rect *rect, t_filler *lst);

#endif