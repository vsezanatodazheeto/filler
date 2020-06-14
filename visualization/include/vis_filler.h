/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_filler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 02:21:57 by yshawn            #+#    #+#             */
/*   Updated: 2020/06/14 23:49:44 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include "../../lib/include/libft.h"
# include "../../lib/include/ft_printf.h"
# include "../../lib/include/get_next_line.h"

# define NAME_FIELD "Plateau"
# define NAME_PIECE "Piece"
# define NAME_GOT "got"
# define FIELD "field"
# define TRUE 1
# define FALSE 0

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
** основные функции filler'a
*/
int						check_player(t_player *player, char **line);
void					init_struct_player(t_player *player);
void					init_structs(t_f *f, t_p *p, t_m *m, t_pos *pos);
t_f						*reading_to_struct(t_f **lst, t_player *player, char **line);
void					record_player(t_player *player, int i);
int						record_map(t_f *f, char **line);
void					record_map_positions(t_f *f, t_player *players, char **line);
int						record_piece(t_f *f, char **line);
void					record_piece_positions(t_f *f, char **line);
void					record_got_pos(t_f *f, char **line);

/*
** вспомогательные функции для filler'а
*/
int						ft_isupch(char ch_1, char ch_2, char ch_3);
int						ft_isupch_2(char str_ch_1, char str_ch_2, char ch_1, char ch_2);
int						ft_stsp(char *s);
int						get_size(int *height, int *width, char **line);
int						ft_strinstr(char *str_dad, char *str_son);
void					add_struct(t_f **cur_lst);
t_f						*new_t_filler();
t_pos					*new_t_pos();
t_m						*new_t_map();
t_p						*new_t_piece();
t_f						*leave(t_f **fst_lst, t_player *player);
void					ft_free_lst(t_f **lst);
void					ft_free_player(t_player *player);
char					*ft_namefield(int height, int width);

#endif
