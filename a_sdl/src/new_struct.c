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

t_p*	new_t_piece()
{
        t_p  *ptr;

        if (!(ptr = malloc(sizeof(t_p))))
			return (NULL);
        return ptr;
}

t_m		*new_t_map()
{
        t_m  *ptr;

        if (!(ptr = malloc(sizeof(t_m))))
			return (NULL);
        return ptr;
}

t_pos	*new_t_pos()
{
        t_pos  *ptr;

        if (!(ptr = malloc(sizeof(t_pos))))
			return (NULL);
        return ptr;
}

t_f  *new_t_filler()
{
        t_f  *ptr;

        if (!(ptr = malloc(sizeof(t_f))))
			return (NULL);
        ptr->next = NULL;
        return ptr;
}