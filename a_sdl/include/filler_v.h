/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_v.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 02:21:57 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/13 13:42:03 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_V_H
# define FILLER_V_H

#include <sys/types.h> //for open
#include <sys/stat.h> //for open
#include <fcntl.h> //for open
#include <unistd.h> //for read
#include <stdio.h> // for fwrite
#include "../../a_libft/libft.h"
#include "../../a_printf/header.h"
#include "../frameworks/SDL2.framework/Headers/SDL.h"
// #include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
// #include "../frameworks/SDL2_image.framework/Headers/SDL_image.h"
// #include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"

#define NAME_ALLY "a.out"
#define NAME_FIELD "Plateau"
#define NAME_PIECE "Piece"
#define NAME_GOT "got"
#define BUF_SIZE 1000
#define HGT 4
#define TRUE 1
#define FALSE 0

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
    struct s_filler    *next;
    struct s_filler    *prev;
}						t_filler;

/*
* основные функции filler'a
*/
void    		init_structs(t_filler *filler, t_piece *piece, t_map *map, t_pos *pos);
void    		check_player(t_filler *filler, char **line);
void			record_player(t_filler *filler, int i);
void			record_map(t_filler *filler, char **line);
void			record_map_positions(t_filler *filler, char **line);
void			record_piece(t_filler *filler, char **line);
void			record_piece_positions(t_filler *filler, char **line);
void			record_got_pos(t_filler *filler, char **line);

/*
* ВИЗУАЛИЗАТОР
*/
void			init_v();

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