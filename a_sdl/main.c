/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:05:08 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/03 19:00:48 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/filler.h"
#include "include/sdl.h"

int tt;

t_f        *reading_to_struct(t_f **lst, t_player *player, char **line)
{
	t_p			*p;
	t_m			*m;
	t_pos		*pos;
	t_f			*fst;
	char		*tmp;
	int			i;

	i = 0;
	tmp = NULL;
	fst = NULL;
	while (get_next_line(tt, &(*line)))
	{
		if (**line == '=')
			break ;
		if (**line == 'P' && ft_strinstr(*line, NAME_FIELD))
		{
			add_struct(lst);
        	init_structs(*lst, p, m, pos);
		}
		if (**line == 'P' && ft_strinstr(*line, NAME_FIELD))
		{
			if (record_map(*lst, &(*line)) == 1)
				break ;
			if (!(get_next_line(tt, &(*line))))
				break ;
			record_map_positions(*lst, player, &(*line));
			if (!(get_next_line(tt, &(*line))))
				break ;
		}
		if (**line == 'P' && ft_strinstr(*line, NAME_PIECE))
		{
			if (record_piece(*lst, &(*line)) == 1)
				break ;
			record_piece_positions(*lst, &(*line));
			if (!(get_next_line(tt, &(*line))))
				break ;
		}
		if (**line == '<' && ft_strinstr(*line, NAME_GOT))
			record_got_pos(*lst, &(*line));
		if (i == 0 && *lst)
		{
			i++;
			fst = *lst;
		}
	}
	return (fst);
}
void		ft_free_player(t_player *player)
{
	ft_memdel((void **)&player->p1);
	ft_memdel((void **)&player->p2);
	ft_memdel((void **)&player->field);
	return ;
}
void		ft_free_lst(t_f **lst)
{
	t_f *cur_lst;

	while ((*lst)->next)
	{
		cur_lst = *lst;
		// for piece
		ft_arrdel((void ***)&cur_lst->p->piece);
		free(cur_lst->p);
		// for map
		ft_arrdel((void ***)&cur_lst->m->map);
		free(cur_lst->m);
		// for pos
		free(cur_lst->pos);
		*lst = (*lst)->next;
		free(cur_lst);
	}
	ft_arrdel((void ***)&(*lst)->p->piece);
	free((*lst)->p);
	ft_arrdel((void ***)&(*lst)->m->map);
	free((*lst)->m);
	free((*lst)->pos);
	free(*lst);
	lst = NULL;
	return ;
}

int			main(int ac, char **av) 
{ 
    t_f			*f;
    t_f			*fst_lst;
    t_player    player[1];
	char 		*line;

    f = NULL;
	fst_lst = NULL;
    line = NULL;
	tt = open(av[1], O_RDONLY);
	ft_printf("%s\n", av[1]);
    init_struct_player(player);
	check_player(player, &line);
	fst_lst = reading_to_struct(&f, player, &line);
    sdl_main(fst_lst, player);
	ft_free_lst(&fst_lst);
	ft_free_player(player);
    return (0);
} 

// переписать got_pos
// переписать check_player