/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:05:08 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/24 05:09:53 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/filler.h"
#include "include/sdl.h"

void        reading_to_struct(t_f *f, t_player *player, char **line)
{
	while (get_next_line(0, &(*line)))
	{
		if (**line == 'P' && ft_strinstr(*line, NAME_FIELD))
		{
			if (record_map(f, &(*line)) == 1)
				break ;
			if (!(get_next_line(0, &(*line))))
				break ;
			record_map_positions(f, player, &(*line));
		}
		else if (**line == 'P' && ft_strinstr(*line, NAME_PIECE))
		{
			if (record_piece(f, &(*line)) == 1)
				break ;
			record_piece_positions(f, &(*line));
		}
		else if (**line == '<' && ft_strinstr(*line, NAME_GOT))
		{
			record_got_pos(f, &(*line));
			return ;
		}
	}
	return ;
}

void    add_struct(t_f *cur_lst)
{
        t_f  *ptr;

        ptr = new_t_filler();
        cur_lst->next = ptr;
        return ;
}

int main() 
{ 
    t_f			*cur_lst;
    t_f			*fst_lst;
	t_p			*p;
	t_m			*m;
	t_pos		*pos;
    t_player    player[1];
	char 		*line;
	int			i;

	i  = 0;
    line = NULL;
    fst_lst = new_t_filler();
	cur_lst = fst_lst;
    init_struct_player(player);
	check_player(cur_lst, player, &line);
    while(line)
    {
        init_structs(cur_lst, p, m, pos);
        reading_to_struct(cur_lst, player, &line);
		if (line)
        {
			add_struct(cur_lst);
    		cur_lst = cur_lst->next;
		}
		else
			break ;
    }
	cur_lst->ally_c = 0;
	cur_lst->enemy_c = 0;
	cur_lst->p = NULL;
	cur_lst->m = NULL;
	cur_lst->pos = NULL;
	cur_lst->next = NULL;
	cur_lst->prev = NULL;
	int n = 0;
    main_v(fst_lst, player);
    return (0);
} 

// переписать got_pos
// переписать check_player