/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:37:13 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/20 22:41:23 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include "../a_libft/libft.h"

# define NAME_ALLY "a.out"
# define NAME_FIELD "Plateau"
# define NAME_PIECE "P"
# define BUF_SIZE 1000
# define HGT 4
# define TRUE 1
# define FALSE 0

typedef struct	s_m
{
	int			width;
	int			height;
	int			**map;
}				t_m;

typedef struct	s_piece_of_shit
{
	int			width;
	int			height;
	int			**piece;
}				t_p;

typedef struct	s_position
{
	int			i;
	int			j;
	int			x;
	int			y;
}				t_pos;

typedef struct	s_f
{
	char		ally;
	char		enemy;
	t_p			*p;
	t_m			*m;
	t_pos		*pos;
}				t_f;

/*
** вспомогательные функции из библиотеки
*/
int				ft_printf(const char *str, ...);
int				get_next_line(int fd, char **line);
char			**ft_strsplit(char const *str, char ch);

/*
** основные функции f'a
*/
void			init_structs(t_f *f, t_p *p, t_m *m, t_pos *pos);
int				check_player(t_f *f, char **line);
void			solving_filler(t_f *f, char **line);
void			record_player(t_f *f, int i);
int				record_map(t_f *f, char **line);
void			record_map_positions(t_f *f, char **line);
int				record_piece(t_f *f, char **line);
void			record_piece_positions(t_f *f, char **line);
void			fill_manhattan_distance(t_f *f);
void			free_data(t_f *f, char **line);

/*
** вспомогательные функции для f'а
*/
int				manhattan_formula(int x, int y, int i, int j);
int				ft_isupch_2(char str_ch_1, char str_ch_2, char ch_1, char ch_2);
int				ft_isupch(char ch_1, char ch_2, char ch_3);
int				get_size(int *height, int *width, char **line);
int				ft_strintchr(char *s, char ch);
int				ft_strinstr(char *str_dad, char *str_son);
void			printf_map(t_f *f); //delete me
void			printf_map_fill(t_f *f); // delete me
void			ft_arrdel(void ***arr);

#endif
