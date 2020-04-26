/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:05:08 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/04 16:07:22 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vis_filler.h"
#include "../../include/vis_sdl.h"

int				fd;

t_f				*reading_to_struct(t_f **lst, t_player *player, char **line)
{
	t_p			*p;
	t_m			*m;
	t_pos		*pos;
	t_f			*fst;
	int			i;

	i = 0;
	p = NULL;
	m = NULL;
	pos = NULL;
	fst = NULL;
	while (get_next_line(fd, &(*line)))
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
				return (leave(&fst, player));
			if (!(get_next_line(fd, &(*line))))
				return (leave(&fst, player));
			record_map_positions(*lst, player, &(*line));
			if (!(get_next_line(fd, &(*line))))
				return (leave(&fst, player));
		}
		if (**line == 'P' && ft_strinstr(*line, NAME_PIECE))
		{
			if (record_piece(*lst, &(*line)) == 1)
				return (leave(&fst, player));
			record_piece_positions(*lst, &(*line));
			if (!(get_next_line(fd, &(*line))))
				return (leave(&fst, player));
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

int				main() 
{ 
		t_f			*f;
		t_f			*fst_lst;
		t_player    player[1];
		char 		*line;

		// fd = open(av[1], O_RDONLY);
		fd = 0;
		f = NULL;
		fst_lst = NULL;
		line = NULL;
		init_struct_player(player);
		if (check_player(player, &line) != 0)
			return (1);
		if (!(fst_lst = reading_to_struct(&f, player, &line)))
			return (1);
		else
		{
			sdl_main(fst_lst, player);
			ft_free_lst(&fst_lst);
			ft_free_player(player);
		}
		return (0);
	}
