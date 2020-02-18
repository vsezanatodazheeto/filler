/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_v.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 02:21:57 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/18 13:15:11 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_V_H
# define FILLER_V_H

#include <sys/types.h> //for open
#include <sys/stat.h> //for open
#include <fcntl.h> //for open
#include <unistd.h> //for read
#include <stdio.h> // for fwrite
#include "../../a_printf/header.h"
#include "../../a_libft/libft.h"
// #include <SDL2/SDL.h> //for linux
// #include <SDL2/SDL_image.h> // for linux
// #include <SDL2/SDL_ttf.h> // for linux
#include "../frameworks/SDL2.framework/Headers/SDL.h"
#include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
#include "../frameworks/SDL2_image.framework/Headers/SDL_image.h"
#include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"

/*
* visualiser constants
*/
// 2560×1440 fullscreen mac
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 1120
#define INDENT 32
#define BAR_HEIGHT 64
#define KEY_HEIGHT 1088
#define FONT_SIZE 50
#define FONT_SIZE_2 50
#define K_QUIT "CMD + W"
#define QUIT "quit"
#define K_PAUSE "SPACE"
#define PAUSE "pause"
#define RESUME "resume"
#define F_BACK "back"
#define F_FORWARD "forward"
#define BLEND_ON SDL_BLENDMODE_MOD
#define BLEND_OFF SDL_BLENDMODE_BLEND
/*
* filler constants
*/
#define NAME_ALLY "a.out"
#define NAME_FIELD "Plateau"
#define NAME_PIECE "Piece"
#define NAME_GOT "got"
#define HGT 4
#define TRUE 1
#define FALSE 0

typedef struct			s_players
{
	char				*p1;
	char				*p2;
	int					p2_len;
}						t_players;

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
	SDL_Texture			*p1;
	SDL_Texture			*p2;

}						t_font;

typedef struct			s_textur
{
	SDL_Texture			*bg;
    SDL_Texture			*cur;
    SDL_Texture			*m_key;
    SDL_Texture			*m_filler;
    SDL_Texture			*m_bar;
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







typedef struct			s_map
{
	int					width;
	int					height;
	int					**map;
}						t_map;

typedef struct			s_piece_of_shit
{
	int					width;
	int					height;
	int					**piece;
}						t_piece;

typedef struct			s_position
{
	int					i;
	int					j;
	char				turn;
}						t_pos;

typedef struct			s_filler
{
	char				ally;
	char				enemy;
	int					ally_c;
	int					enemy_c;
	t_piece				*piece;
	t_map				*map;
	t_pos				*pos;
    struct s_filler		*next;
    struct s_filler		*prev;
}						t_filler;

/*
* ВИЗУАЛИЗАТОР
*/
int					main_v(t_filler *filler, t_players *players);
int					init_lib();
void				init_t_rend(t_rend *r, t_textur *t, t_font *f, t_rect *rect);
int					create(SDL_Window **win, t_rend *r, t_players *player);
int					create_textur(t_rend *r);
void				create_font(t_rend *r, t_players *player);
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

/*
*
*/

/*
* вспомогательные функции из библиотеки
*/
int				ft_tolow(int ch);
// int     		ft_printf(const char *str, ...);
int     		get_next_line(int fd, char **line);
char			**ft_strsplit(char const *str, char ch);

/*
* основные функции filler'a
*/
void			init_struct_players(t_players *players);
void    		init_structs(t_filler *filler, t_piece *piece, t_map *map, t_pos *pos);
void			check_player(t_filler *filler, t_players *players, char **line);
void			record_player(t_filler *filler, int i);
void			record_map(t_filler *filler, char **line);
void			record_map_positions(t_filler *filler, char **line);
void			record_piece(t_filler *filler, char **line);
void			record_piece_positions(t_filler *filler, char **line);
void			record_got_pos(t_filler *filler, char **line);


/*
* вспомогательные функции для filler'а
*/
int				ft_is_strstr(char *str_dad, char *str_son);
void			print_everything(t_filler *filler);
void    		add_struct(t_filler *cur_lst);
t_filler 		*new_t_filler();
t_pos  			*new_t_pos();
t_map 			*new_t_map();
t_piece			*new_t_piece();

#endif