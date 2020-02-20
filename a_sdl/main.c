/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:05:08 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/20 18:29:29 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/filler.h"
#include "include/sdl.h"

void        reading_to_struct(t_filler *filler, char **line)
{
	while (get_next_line(0, &(*line)))
	{
		if (**line == 'P' && ft_is_strstr(*line, NAME_FIELD))
		{
			record_map(filler, &(*line));
			record_map_positions(filler, &(*line));
		}
		else if (**line == 'P' && ft_is_strstr(*line, NAME_PIECE))
		{
			record_piece(filler, &(*line));
			record_piece_positions(filler, &(*line));
		}
		else if (**line == '<' && ft_is_strstr(*line, NAME_GOT))
		{
			record_got_pos(filler, &(*line));
			return ;
		}
	}
	return ;
}

void    add_struct(t_filler *cur_lst)
{
        t_filler  *ptr;

        ptr = new_t_filler();
        cur_lst->next = ptr;
        return ;
}

int main() 
{ 
    t_filler    *cur_lst;
    t_filler	*fst_lst;
	t_piece		*piece;
	t_map		*map;
	t_pos		*pos;
    t_player    player[1];
	char 		*line;
	int			i;

	i  = 0;
    fst_lst = new_t_filler();
	cur_lst = fst_lst;
    line = NULL;
    init_struct_player(player);
	check_player(cur_lst, player, &line);
    while(++i < 12) // исправить
    {
        map = new_t_map();
        pos = new_t_pos();
        piece = new_t_piece();
        init_structs(cur_lst, piece, map, pos);
        reading_to_struct(cur_lst, &line);
        add_struct(cur_lst);
        cur_lst = cur_lst->next;
        break ;
    }
    print_everything(fst_lst);
	// exit(1);
    main_v(fst_lst, player);
    return (0);
} 