/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 02:21:57 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/28 01:55:17 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <stdio.h> // for fwrite
#include <unistd.h>
#include "../../a_printf/header.h"
#include "../../a_libft/libft.h"
#include "../../a_gnl/get_next_line.h"

#define NAME_FIELD "Plateau"
#define NAME_PIECE "Piece"
#define NAME_GOT "got"
#define HGT 4
#define TRUE 1
#define FALSE 0

typedef struct			s_player
{
	char				*p1;
	char				*p2;
	char				*field;
	char				ally;
	char				enemy;
}						t_player;

typedef struct			s_m
{
	int					width;
	int					height;
	int					**map;
}						t_m;

typedef struct			s_piece_of_shit
{
	int					width;
	int					height;
	int					**piece;
}						t_p;

typedef struct			s_pos
{
	int					i;
	int					j;
	char				turn;
}						t_pos;

typedef struct			s_f
{
	int					ally_cnt;
	int					enemy_cnt;
	int					field_cnt;
	t_p					*p;
	t_m					*m;
	t_pos				*pos;
    struct s_f			*next;
    struct s_f			*prev;
}						t_f;

/*
* вспомогательные функции из библиотеки
*/
int     		ft_printf(const char *str, ...);
int     		get_next_line(int fd, char **line);
char			**ft_strsplit(char const *str, char ch);

/*
* основные функции filler'a
*/
void			check_player(t_player *player, char **line);
void			init_struct_player(t_player *player);
void    		init_structs(t_f *f, t_p *p, t_m *m, t_pos *pos);
// void			reading_to_struct(t_f *f, t_player *player, char **line);
void 			record_player(t_player *player, int i);
int				record_map(t_f *f, char **line);
void			record_map_positions(t_f *f, t_player *players, char **line);
int				record_piece(t_f *f, char **line);
void			record_piece_positions(t_f *f, char **line);
void			record_got_pos(t_f *f, char **line);

/*
* вспомогательные функции для filler'а
*/
int				ft_isupch(char ch_1, char ch_2, char ch_3);
int				ft_isupch_2(char str_ch_1, char str_ch_2, char ch_1, char ch_2);
int				get_size(int *height, int *width, char **line);
int				ft_strinstr(char *str_dad, char *str_son);
void			ft_arrdel(void ***arr);
// void    		add_struct(t_f *curlst);
t_f 			*new_t_filler();
t_pos  			*new_t_pos();
t_m 			*new_t_map();
t_p				*new_t_piece();

void			print_everything(t_f *f); //delete me
// добавить в либу блять
#endif