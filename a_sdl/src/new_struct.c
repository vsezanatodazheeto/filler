/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:56:52 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/19 17:14:11 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

t_piece  *new_t_piece()
{
        t_piece  *ptr;

        if (!(ptr = malloc(sizeof(t_piece))))
			return (NULL);
        return ptr;
}

t_map  *new_t_map()
{
        t_map  *ptr;

        if (!(ptr = malloc(sizeof(t_map))))
			return (NULL);
        return ptr;
}

t_pos  *new_t_pos()
{
        t_pos  *ptr;

        if (!(ptr = malloc(sizeof(t_pos))))
			return (NULL);
        return ptr;
}

t_filler  *new_t_filler()
{
        t_filler  *ptr;

        if (!(ptr = malloc(sizeof(t_filler))))
			return (NULL);
        ptr->next = NULL;
        return ptr;
}