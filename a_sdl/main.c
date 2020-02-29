/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:05:08 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/29 12:41:19 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/filler.h"
#include "include/sdl.h"

void    add_struct(t_f **cur_lst)
{
        t_f  *ptr;

		if (*cur_lst == NULL)
        	*cur_lst = new_t_filler();
		else
		{
        	ptr = new_t_filler();
        	(*cur_lst)->next = ptr;
			ptr->prev = *cur_lst;
			*cur_lst = (*cur_lst)->next;
		}
        return ;
}

t_f        *reading_to_struct(t_f **lst, t_player *player, char **line)
{
	int			i;
	t_p			*p;
	t_m			*m;
	t_pos		*pos;
	char		*tmp;
	t_f			*fst = NULL;;

	i = 0;
	tmp = NULL;
	while (get_next_line(0, &(*line)))
	{
		if (**line == '=')
			break;
		if (**line == 'P' && ft_strinstr(*line, NAME_FIELD))
		{
			add_struct(lst);
        	init_structs(*lst, p, m, pos);
		}
		if (**line == 'P' && ft_strinstr(*line, NAME_FIELD))
		{
			if (record_map(*lst, &(*line)) == 1)
				break ;
			if (!(get_next_line(0, &(*line))))
				break ;
			record_map_positions(*lst, player, &(*line));
			if (!(get_next_line(0, &(*line))))
				break ;
		}
		if (**line == 'P' && ft_strinstr(*line, NAME_PIECE))
		{
			if (record_piece(*lst, &(*line)) == 1)
				break ;
			record_piece_positions(*lst, &(*line));
			if (!(get_next_line(0, &(*line))))
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

int		main() 
{ 
    t_f			*f;
    t_f			*fst_lst;
    t_player    player[1];
	char 		*line;

    line = NULL;
    f = NULL;
	fst_lst = NULL;
    init_struct_player(player);
	check_player(player, &line);
	fst_lst = reading_to_struct(&f, player, &line);
	// while (fst_lst->next)
	// {
	// 	ft_printf("here: %d\n", fst_lst->ally_cnt);
	// 	ft_printf("here: %d\n", fst_lst->enemy_cnt);
	// 	ft_printf("here: %d\n", fst_lst->field_cnt);
	// 	fst_lst = fst_lst->next;
	// }
    main_v(fst_lst, player);
	// ft_printf("%s\n", player->field);
	// printf("%s\n", player->field);

    return (0);
} 

// пофришить
// листы
// переписать got_pos
// переписать check_player